#include "mpci-impl.h"

void
mpci_fi_div (mpci_ptr rop,
             mpfi_srcptr op1, mpci_srcptr op2)
{
    mpfi_t prod;
    mpfi_t div;
    mpfi_init2 (prod, mpci_get_prec(op2));
    mpfi_init2 (div,  mpci_get_prec(op2));

    mpfi_sqr (div,  op2->real);
    mpfi_sqr (prod, op2->imag);
    mpfi_add (div,  div, prod);

    mpfi_div (prod, op1, div);

    mpfi_mul (rop->real, op2->real, prod);
    mpfi_mul (rop->imag, op2->imag, prod);
    mpfi_neg (rop->imag, rop->imag);

    mpfi_clear (prod);
    mpfi_clear (div);
}
