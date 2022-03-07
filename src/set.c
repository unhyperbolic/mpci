#include "mpci-impl.h"

void
mpci_set (mpci_ptr a, mpci_srcptr b)
{
    mpfi_set(a->real, b->real);
    mpfi_set(a->imag, b->imag);
}
