#include "mpci-impl.h"

/* The precision of the real/imag interval is set to prec,    */
/* the previous value of x is lost.                           */
void
mpci_set_prec (mpci_ptr x, mp_prec_t prec)
{
    mpfi_set_prec(x->real, prec);
    mpfi_set_prec(x->imag, prec);
}
