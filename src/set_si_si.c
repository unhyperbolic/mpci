#include "mpci-impl.h"

void
mpci_set_si_si (mpci_ptr a, long b, long c)
{
    mpfi_set_si(a->real, b);
    mpfi_set_si(a->imag, c);
}
