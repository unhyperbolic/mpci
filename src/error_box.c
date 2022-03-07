#include "mpci-impl.h"

void mpci_error_box (mpci_ptr rop, mpfi_srcptr size)
{
    mpfr_t p;
    mpfr_t n;
    mpfr_init2(p, mpfi_get_prec(size));
    mpfr_init2(n, mpfi_get_prec(size));
    mpfi_get_right(p, size);
    mpfr_neg(n, p, MPFR_RNDD);
    
    mpfi_interv_fr(rop->real, n, p);
    mpfi_interv_fr(rop->imag, n, p);
}

void mpci_error_box2 (mpci_ptr rop, mpfr_srcptr size)
{
    mpfr_t n;

    mpfr_init2 (n, mpfr_get_prec(size));

    /* Compute -size (rounding down) */
    mpfr_neg   (n, size, MPFR_RNDD);
    
    /* Set real and imaginary part of complex interval to be
     * [-size, size] */
    mpfi_interv_fr (rop->real, n, size);
    mpfi_interv_fr (rop->imag, n, size);
    
    mpfr_clear (n);
}
