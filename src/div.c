#include "mpci-impl.h"

void
mpci_div (mpci_ptr rop,
          mpci_srcptr op1, mpci_srcptr op2)
{
    mpfi_t re;
    mpfi_t im;
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
    
    mpfi_init2(re,   mpci_get_prec(op1));
    mpfi_init2(im,   mpci_get_prec(op1));
    mpfi_init2(prod, mpci_get_prec(op1));
    mpfi_init2(div,  mpci_get_prec(op1));

    mpfi_mul(re,   op1->real, op2->real);
    mpfi_mul(prod, op1->imag, op2->imag);
    mpfi_add(re,   re, prod);

    mpfi_mul(im,   op1->imag, op2->real);
    mpfi_mul(prod, op1->real, op2->imag);
    mpfi_sub(im,   im, prod);

    mpfi_sqr(div,  op2->real);
    mpfi_sqr(prod, op2->imag);
    mpfi_add(div,  div, prod);

    mpfi_div(rop->real, re, div);
    mpfi_div(rop->imag, im, div);
    
    mpfi_clear(re);
    mpfi_clear(im);
    mpfi_clear(prod);
    mpfi_clear(div);
}
