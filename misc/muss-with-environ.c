/*
 * Experiment with manually changing the environ(7) pointer. So, yeah, quite
 * possible for something misbehaved to muss with the pointer and create a
 * duplicate environment entry:
 *
 *   make muss-with-environ && ./muss-with-environ env | grep PATH
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>

void emit_help(void);

int main(int argc, char *argv[])
{
    int ch;
    extern char **environ;

    /* mostly to get argv lined up right */
    while ((ch = getopt(argc, argv, "h?")) != -1) {
        switch (ch) {

        case 'h':
        case '?':
        default:
            emit_help();
            /* NOTREACHED */
        }
    }
    argc -= optind;
    argv += optind;

    if (argc < 1)
        emit_help();

    /* don't do this. */
    char **envp = environ;
    while (*envp++ != NULL);
    envp--;
    *envp++ = "PATH=/wibble";
    envp = NULL;

    if (execvp(argv[0], argv) == -1)
        err(EX_OSERR, "could not exec '%s'", argv[0]);

    /* NOTREACHED due to exec or so we hope */
    exit(1);
}

void emit_help(void)
{
    fprintf(stderr, "Usage: muss-with-environ command [command args..]\n");
    exit(EX_USAGE);
}
