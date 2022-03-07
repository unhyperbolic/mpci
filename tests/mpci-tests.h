#ifndef __MPFCI_TESTS_H__
#define __MPFCI_TESTS_H__

#include <stdio.h>

#include "mpci-impl.h"

typedef void (*mpfi_fun_si)        (mpfi_ptr, long);
typedef void (*mpci_fun_mpci)      (mpci_ptr, mpci_srcptr);
typedef void (*mpci_fun_mpci_mpci) (mpci_ptr, mpci_srcptr, mpci_srcptr);
typedef void (*mpci_fun_mpci_si)   (mpci_ptr, mpci_srcptr, long);
typedef void (*mpci_fun_si_mpci)   (mpci_ptr, long, mpci_srcptr);

void check_data_mpfi_fun_si (
    mpfi_fun_si function,        const char *file_name);
void check_data_mpci_fun_mpci (
    mpci_fun_mpci function,      const char *file_name);
void check_data_mpci_fun_mpci_mpci (
    mpci_fun_mpci_mpci function, const char *file_name);
void check_data_mpci_fun_mpci_si (
    mpci_fun_mpci_si function,   const char *file_name);
void check_data_mpci_fun_si_mpci (
    mpci_fun_si_mpci function,   const char *file_name);

FILE* open_file            (const char* file_name);

void init_reading          (FILE*);
void close_file            (FILE*);
void skip_whitespace_comments (FILE*);

void read_mpfi             (FILE *f, mpfi_ptr a);
void read_mpci             (FILE *f, mpci_ptr a);
void read_si               (FILE *f, long *i);

int  are_mpfi_results_equal (mpfi_srcptr op1, mpfi_srcptr op2);
int  are_mpci_results_equal (mpci_srcptr op1, mpci_srcptr op2);

void print_mpfi_decimal    (mpfi_srcptr op);
void print_mpfi_expected_and_result (
    mpfi_srcptr expected, mpfi_srcptr result);

void print_mpci_decimal    (mpci_srcptr op);
void print_mpci_expected_and_result (
    mpci_srcptr expected, mpci_srcptr result);

#endif
