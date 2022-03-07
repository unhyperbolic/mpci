#include "mpci-tests.h"

#include "mpfi_io.h"

int are_mpci_results_equal (mpci_srcptr op1, mpci_srcptr op2)
{
    if (mpci_nan_p (op1)) {
        return mpci_nan_p (op2);
    }

    if (!mpfr_equal_p (&(op1->real->left),  &(op2->real->left))) {
        return 0;
    }

    if (!mpfr_equal_p (&(op1->real->right), &(op2->real->right))) {
        return 0;
    }

    if (!mpfr_equal_p (&(op1->imag->left),  &(op2->imag->left))) {
        return 0;
    }

    if (!mpfr_equal_p (&(op1->imag->right), &(op2->imag->right))) {
        return 0;
    }

    return 1;
}

int are_mpfi_results_equal (mpfi_srcptr op1, mpfi_srcptr op2)
{
    if (mpfi_nan_p (op1)) {
        return mpfi_nan_p (op2);
    }

    if (!mpfr_equal_p (&(op1->left),  &(op2->left))) {
        return 0;
    }

    if (!mpfr_equal_p (&(op1->right), &(op2->right))) {
        return 0;
    }

    return 1;
}

void print_mpci_decimal (mpci_srcptr op) {
    mpfi_out_str (stdout, 10, 0, op->real);
    printf (" + ");
    mpfi_out_str (stdout, 10, 0, op->imag);
    printf (" * I");
}

void print_mpci_expected_and_result (mpci_srcptr expected,
                                     mpci_srcptr result)
{
    printf ("Expected result:\n    ");
    if (mpci_nan_p (expected)) {
        printf("nan\n");
    } else {
        print_mpci_decimal (expected);
    }

    printf ("\nActual result:\n    ");
    print_mpci_decimal (result);
    printf ("\nActual result (prec and endpoints in hex):\n");
    printf("    %d ", mpci_get_prec (result));
    mpfr_printf("%Ra %Ra %Ra %Ra\n",
                &(result->real->left),
                &(result->real->right),
                &(result->imag->left),
                &(result->imag->right));
}

void print_mpfi_expected_and_result (mpfi_srcptr expected,
                                     mpfi_srcptr result)
{
    printf ("Expected result:\n    ");
    if (mpfi_nan_p (expected)) {
        printf("nan\n");
    } else {
        mpfi_out_str (stdout, 10, 0, expected);
    }

    printf ("\nActual result:\n    ");
    mpfi_out_str (stdout, 10, 0, result);
    printf ("\nActual result (prec and endpoints in hex):\n");
    printf("    %d ", mpfi_get_prec (result));
    mpfr_printf("%Ra %Ra\n",
                &(result->left),
                &(result->right));
}
