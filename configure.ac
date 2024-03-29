#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.65)
AC_INIT([mpci],[0.1],[enischte@gmail.com])
AC_CONFIG_SRCDIR([src/mpci.h])
AC_CONFIG_HEADERS([mpci_config.h])

AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror dist-bzip2 dist-zip])

dnl Extra arguments to configure
AC_ARG_WITH([mpfi_include],
            [AS_HELP_STRING([--with-mpfi-include=DIR],[MPFI include directory])],
            [CPPFLAGS="-I$withval $CPPFLAGS"])
AC_ARG_WITH([mpfi_lib],
            [AS_HELP_STRING([--with-mpfi-lib=DIR],[MPFI lib directory])],
            [LDFLAGS="-L$withval $LDFLAGS"])
AC_ARG_WITH([mpfi],
            [AS_HELP_STRING([--with-mpfi=DIR],[MPFI install directory])],
            [
            if test -z "$with_mpfi_include" -a -z "$with_mpfi_lib" ; then
               CPPFLAGS="-I$withval/include $CPPFLAGS"
               LDFLAGS="-L$withval/lib $LDFLAGS"
            else
               AC_MSG_FAILURE([Do not use --with-mpfi and --with-mpfi-include/--with-mpfi-lib options simultaneously.])
            fi
            ])
AC_ARG_WITH([mpfr_include],
            [AS_HELP_STRING([--with-mpfr-include=DIR],[MPFR include directory])],
            [CPPFLAGS="-I$withval $CPPFLAGS"])
AC_ARG_WITH([mpfr_lib],
            [AS_HELP_STRING([--with-mpfr-lib=DIR],[MPFR lib directory])],
            [LDFLAGS="-L$withval $LDFLAGS"])
AC_ARG_WITH([mpfr],
            [AS_HELP_STRING([--with-mpfr=DIR],[MPFR install directory])],
            [
            if test -z "$with_mpfr_include" -a -z "$with_mpfr_lib" ; then
               CPPFLAGS="-I$withval/include $CPPFLAGS"
               LDFLAGS="-L$withval/lib $LDFLAGS"
            else
               AC_MSG_FAILURE([Do not use --with-mpfr and --with-mpfr-include/--with-mpfr-lib options simultaneously.])
            fi
            ])
AC_ARG_WITH([gmp_include],
            [AS_HELP_STRING([--with-gmp-include=DIR],[GMP include directory])],
            [CPPFLAGS="-I$withval $CPPFLAGS"])
AC_ARG_WITH([gmp_lib],
            [AS_HELP_STRING([--with-gmp-lib=DIR],[GMP lib directory])],
            [LDFLAGS="-L$withval $LDFLAGS"])
AC_ARG_WITH([gmp],
            [AS_HELP_STRING([--with-gmp=DIR],[GMP install directory])],
            [
            if test -z "$with_gmp_lib" -a -z "$with_gmp_include" ; then
               CPPFLAGS="-I$withval/include $CPPFLAGS"
               LDFLAGS="-L$withval/lib $LDFLAGS"
            else
               AC_MSG_FAILURE([Do not use --with-gmp and --with-gmp-include/--with-gmp-lib options simultaneously.])
            fi
            ])

# Checks for programs.
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
LT_INIT

# Checks for libraries.
dnl Check GMP Header
AC_MSG_CHECKING(for gmp.h)
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include "gmp.h"
]])],[AC_MSG_RESULT(yes)],[
 AC_MSG_RESULT(no)
 AC_MSG_ERROR([gmp.h can't be found, or is unusable.])
])

AC_CHECK_LIB([gmp], [__gmpz_init],
             [LIBS="-lgmp $LIBS"],
             [AC_MSG_ERROR([libgmp not found.])])

AC_MSG_CHECKING(for valid GMP)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include "gmp.h"
#if (__GNU_MP_VERSION*100+__GNU_MP_VERSION_MINOR*10 < 410)
# error "min: GMP 4.1.0"
#endif
]], [[]])],[AC_MSG_RESULT(yes)],[
 AC_MSG_RESULT(no)
 AC_MSG_ERROR([GMP 4.1.0 min required])
])

dnl Check MPFR Header
AC_MSG_CHECKING(for mpfr.h)
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include "mpfr.h"
]])],[AC_MSG_RESULT(yes)],[
 AC_MSG_RESULT(no)
 AC_MSG_ERROR([mpfr.h can't be found, or is unusable.])
])

AC_CHECK_LIB([mpfr], [mpfr_init],
             [LIBS="-lmpfr $LIBS"],
             [AC_MSG_ERROR([libmpfr not found.])])

AC_MSG_CHECKING(for valid MPFR)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include "mpfr.h"
#if (MPFR_VERSION < MPFR_VERSION_NUM(2,4,2))
# error "min: MPFR 2.4.2"
#endif
]], [[]])],[AC_MSG_RESULT(yes)],[
 AC_MSG_RESULT(no)
 AC_MSG_ERROR([MPFR 2.4.2 min required])
])

dnl Check MPFI Header
AC_MSG_CHECKING(for mpfi.h)
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include "mpfi.h"
]])],[AC_MSG_RESULT(yes)],[
 AC_MSG_RESULT(no)
 AC_MSG_ERROR([mpfi.h can't be found, or is unusable.])
])

AC_CHECK_LIB([mpfi], [mpfi_init],
             [LIBS="-lmpfi $LIBS"],
             [AC_MSG_ERROR([libmpfi not found.])])

AC_MSG_CHECKING(for valid MPFI)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include "mpfi.h"

#define MPFI_VERSION_NUM(a,b,c) (((a) << 16L) | ((b) << 8) | (c))
#define MPFI_VERSION MPFI_VERSION_NUM(MPFI_VERSION_MAJOR,MPFI_VERSION_MINOR,MPFI_VERSION_PATCHLEVEL)

#if (MPFI_VERSION < MPFI_VERSION_NUM(1,5,1))
# error "min: MPFI 1.5.1"
#endif
]], [[]])],[AC_MSG_RESULT(yes)],[
 AC_MSG_RESULT(no)
 AC_MSG_ERROR([MPFI 1.5.1 min required])
])

# Checks for header files.
AC_CHECK_HEADERS([float.h limits.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([dup2 gettimeofday])
AC_CHECK_FUNCS([mpfr_q_sub mpfr_z_sub mpfr_z_div])
AC_CHECK_FUNCS([mpfi_mul_si mpfi_fr_div mpfi_log])

case $AC_PACKAGE_VERSION in
  *-dev)
   AC_DEFINE([WARN_IF_REVERTED_ENDPOINTS], 1,
    [Define to 1 if it is a development version.]);;
esac

AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 src/Makefile
                 tests/Makefile])
AC_OUTPUT
