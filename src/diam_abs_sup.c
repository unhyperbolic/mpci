#include "mpci-impl.h"

void mpci_diam_abs_sup (mpfr_ptr rop, mpci_srcptr op)
{
    mpfr_t tmp;
    
    mpfr_init2    (tmp, mpci_get_prec (op));

    /* Compute absolute diameters of intervals for real and imaginary part */
    mpfi_diam_abs (tmp, op->real);
    mpfi_diam_abs (rop, op->imag);

    /* And return the maximum */
    mpfr_max      (rop, rop, tmp, MPFR_RNDU);

    mpfr_clear    (tmp);
}
