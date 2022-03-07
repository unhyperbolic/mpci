#include "mpci-impl.h"

void
mpci_arg (mpfi_ptr rop, mpci_srcptr op)
{
    mpfi_t re;
    mpfi_t im;

    if (mpfi_has_zero (op->real) &&
        mpfi_has_zero (op->imag)) {

        mpfr_set_nan (&(rop->left));
        mpfr_set_nan (&(rop->right));
        return;
    }
    
    if (mpfi_is_strictly_neg(op->real) &&
        mpfi_has_zero(op->imag)) {

        mpfi_init2 (re, mpci_get_prec(op));
        mpfi_init2 (im, mpci_get_prec(op));
        
        mpfi_neg (re, op->real);
        mpfi_neg (im, op->imag);

        mpfi_atan2 (rop, im, re);
        mpfi_const_pi (re);
        mpfi_add (rop, rop, re);

        mpfi_clear (re);
        mpfi_clear (im);
    } else {
        mpfi_atan2 (rop, op->imag, op->real);
    }
}
