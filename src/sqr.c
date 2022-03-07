#include "mpci-impl.h"

void
mpci_sqr (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_t prod;
    mpfi_t re;
    mpfi_init2 (prod, mpci_get_prec(op));
    mpfi_init2 (re,   mpci_get_prec(op));

    mpfi_sqr (re,   op->real);
    mpfi_sqr (prod, op->imag);
    mpfi_sub (re, re, prod);

    mpfi_mul (rop->imag, op->real, op->imag);
    mpfi_mul_2ui (rop->imag, rop->imag, 1);
    mpfi_set (rop->real, re);

    mpfi_clear (prod);
    mpfi_clear (re);
}
