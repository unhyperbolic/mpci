#include "mpci-impl.h"

void mpci_upper_abs (mpfr_ptr rop, mpci_srcptr op)
{
    /* Compute |z|^2 */
    mpci_upper_sqr_abs (rop, op);

    /* And take its square root (rounding up) */
    mpfr_sqrt          (rop, rop, MPFR_RNDU);
}
