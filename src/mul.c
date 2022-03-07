#include "mpci-impl.h"

void
mpci_mul (mpci_ptr rop,
          mpci_srcptr op1, mpci_srcptr op2)
{
    mpfi_t prod;
    mpfi_t re;
    mpfi_t im;
    mpfi_init2(prod, mpci_get_prec(op1));
    mpfi_init2(re,   mpci_get_prec(op1));
    mpfi_init2(im,   mpci_get_prec(op1));
    
    mpfi_mul(re,        op1->real, op2->real);
    mpfi_mul(prod,      op1->imag, op2->imag);
    mpfi_sub(re,        re, prod);

    mpfi_mul(im,        op1->real, op2->imag);
    mpfi_mul(prod,      op1->imag, op2->real);
    mpfi_add(rop->imag, im, prod);

    mpfi_set(rop->real, re);

    mpfi_clear(prod);
    mpfi_clear(re);
    mpfi_clear(im);
}
