#include "mpci-impl.h"

void
mpci_si_div (mpci_ptr rop,
             long op1, mpci_srcptr op2)
{
    mpfi_t prod;
    mpfi_t div;

    if (mpfi_has_zero (op2->real) &&
        mpfi_has_zero (op2->imag)) {

        mpfr_set_nan (&(rop->real->left));
        mpfr_set_nan (&(rop->real->right));
        mpfr_set_nan (&(rop->imag->left));
        mpfr_set_nan (&(rop->imag->right));
        return;
    }
    
    mpfi_init2 (prod, mpci_get_prec(op2));
    mpfi_init2 (div,  mpci_get_prec(op2));

    mpfi_sqr (div,  op2->real);
    mpfi_sqr (prod, op2->imag);
    mpfi_add (div,  div, prod);

    mpfi_si_div (prod, op1, div);

    mpfi_mul (rop->real, op2->real, prod);
    mpfi_mul (rop->imag, op2->imag, prod);
    mpfi_neg (rop->imag, rop->imag);

    mpfi_clear (prod);
    mpfi_clear (div);
}
