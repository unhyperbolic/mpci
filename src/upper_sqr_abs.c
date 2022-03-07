#include "mpci-impl.h"

void mpci_upper_sqr_abs (mpfr_ptr rop, mpci_srcptr op)
{
    /* Uses |a + b * I|^2 = a^2 + b^2 */

    int prec = mpci_get_prec (op);

    mpfr_t re;    /* maximum of square of real part */
    mpfr_t im;    /* maximum of square of imaginary part */
    mpfr_t tmp;

    mpfr_init2  (re,  prec);
    mpfr_init2  (im,  prec);
    mpfr_init2  (tmp, prec);

    /* Square the left and right end point of the interval
     * for the real part (rounding up) and take the maximum */
    mpfr_sqr    (tmp, &(op->real->left),  MPFR_RNDU);
    mpfr_sqr    (re,  &(op->real->right), MPFR_RNDU);
    mpfr_max    (re,  re,  tmp,           MPFR_RNDU);

    /* Similar for the imaginary part */
    mpfr_sqr    (tmp, &(op->imag->left),  MPFR_RNDU);
    mpfr_sqr    (im,  &(op->imag->right), MPFR_RNDU);
    mpfr_max    (im,  im,  tmp,           MPFR_RNDU);

    /* And add them together */
    mpfr_add    (rop, re,  im,            MPFR_RNDU);

    mpfr_clear  (re);
    mpfr_clear  (im);
    mpfr_clear  (tmp);
}
