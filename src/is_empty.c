#include "mpci-impl.h"

int
mpci_is_empty (mpci_srcptr a)
{
    return mpfi_is_empty (a->real) || mpfi_is_empty (a->imag);
}
