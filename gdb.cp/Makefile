VPATH = /Users/admin/Downloads/gnu-debugger-6.8-src/gdb/testsuite/gdb.cp
srcdir = /Users/admin/Downloads/gnu-debugger-6.8-src/gdb/testsuite/gdb.cp

EXECUTABLES = ambiguous annota2 anon-union cplusfuncs cttiadd \
	derivation inherit local member-ptr method misc \
        overload ovldbreak ref-typ ref-typ2 templates userdef virtfunc namespace \
	ref-types ref-params method2

all info install-info dvi install uninstall installcheck check:
	@echo "Nothing to be done for $@..."

clean mostlyclean:
	-rm -f *~ *.o *.ci
	-rm -f core ${EXECUTABLES}

distclean maintainer-clean realclean: clean
	-rm -f Makefile config.status config.log
