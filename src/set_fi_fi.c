#include "mpci-impl.h"

void
mpci_set_fi_fi (mpci_ptr a, mpfi_srcptr b, mpfi_srcptr c)
{
    mpfi_set(a->real, b);
    mpfi_set(a->imag, c);
}
