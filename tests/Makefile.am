LDADD = libmpci-tests.la $(top_builddir)/src/.libs/libmpci.la
AM_CPPFLAGS = -I$(top_srcdir)/src

check_LTLIBRARIES = libmpci-tests.la
libmpci_tests_la_SOURCES = mpci-tests.h \
	                   check_data_mpfi_fun_si.c \
                           check_data_mpci_fun_mpci.c \
                           check_data_mpci_fun_mpci_mpci.c \
	                   check_data_mpci_fun_mpci_si.c \
	                   check_data_mpci_fun_si_mpci.c \
                           read_data.c compare_results.c

check_PROGRAMS = tadd tsub tmul tdiv \
                 tadd_si tsub_si tsi_sub tmul_si tdiv_si tsi_div \
                 tlog formatting

TESTS = $(check_PROGRAMS)
