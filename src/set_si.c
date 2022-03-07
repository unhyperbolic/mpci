#include "mpci-impl.h"

void
mpci_set_si (mpci_ptr a, long b)
{
    mpfi_set_si(a->real, b);
    mpfi_set_si(a->imag, 0);
}
