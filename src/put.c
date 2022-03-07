#include "mpci-impl.h"

void
mpci_put (mpci_ptr a, mpci_srcptr b)
{
    mpfi_put (a->real, b->real);
    mpfi_put (a->imag, b->imag);
}
