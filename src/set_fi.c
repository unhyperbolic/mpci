#include "mpci-impl.h"

void
mpci_set_fi (mpci_ptr a, mpfi_srcptr b)
{
    mpfi_set(a->real, b);
    mpfi_set_si(a->imag, 0);
}
