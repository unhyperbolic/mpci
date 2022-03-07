#include "mpci-impl.h"

/* Returns the largest precision of real/imag part of x */
/* Reminder: the real/imag part's precision are supposed to be the same */
mp_prec_t
mpci_get_prec (mpci_srcptr x)
{
    mp_prec_t prec_real, prec_imag;
    
    prec_real = mpfi_get_prec(x->real);
    prec_imag = mpfi_get_prec(x->imag);

    return (prec_real>prec_imag ? prec_real : prec_imag);
}
