#include "mpci-impl.h"

void
mpci_get_imag (mpfi_ptr a, mpci_srcptr b)
{
    mpfi_set(a, b->imag);
}
