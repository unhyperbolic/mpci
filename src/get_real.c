#include "mpci-impl.h"

void
mpci_get_real (mpfi_ptr a, mpci_srcptr b)
{
    mpfi_set(a, b->real);
}
