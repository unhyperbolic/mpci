#include "mpci-impl.h"

void
mpci_log (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_t re;
    mpfi_t sqr;
    mpfi_init2 (re,  mpci_get_prec(op));
    mpfi_init2 (sqr, mpci_get_prec(op));
    
    mpfi_sqr (re,  op->real);
    mpfi_sqr (sqr, op->imag);
    mpfi_add (re, re, sqr);
    mpfi_log (re, re);

    mpci_arg (rop->imag, op);
    mpfi_mul_2si (rop->real, re, -1);

    mpfi_clear (re);
    mpfi_clear (sqr);
}
