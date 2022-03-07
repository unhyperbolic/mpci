#include "mpci-impl.h"

void
mpci_inv (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_t sqr;
    mpfi_t div;
    mpfi_init2 (sqr, mpci_get_prec(op));
    mpfi_init2 (div, mpci_get_prec(op));

    mpfi_sqr (div, op->real);
    mpfi_sqr (sqr, op->imag);
    mpfi_add (div, div, sqr);

    mpfi_div (rop->real, op->real, div);
    mpfi_div (rop->imag, op->imag, div);
    mpfi_neg (rop->imag, rop->imag);
    
    mpfi_clear (sqr);
    mpfi_clear (div);
}
