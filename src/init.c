#include "mpci-impl.h"

void
mpci_init (mpci_ptr x)
{
    mpfi_init (x->real);
    mpfi_init (x->imag);
}

void
mpci_init2 (mpci_ptr x, mp_prec_t p)
{
    mpfi_init2(x->real, p);
    mpfi_init2(x->imag, p);
}
