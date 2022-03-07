#include "mpci-impl.h"

void
mpci_exp (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_t re;
    mpfi_t im;
    mpfi_init2 (re,  mpci_get_prec(op));
    mpfi_init2 (im,  mpci_get_prec(op));

    mpfi_exp (re, op->real);
    mpfi_set (im, op->imag);
    
    mpfi_cos (rop->real, im);
    mpfi_mul (rop->real, rop->real, re);
    mpfi_sin (rop->imag, im);
    mpfi_mul (rop->imag, rop->imag, re);
    
    mpfi_clear (re);
    mpfi_clear (im);
}
