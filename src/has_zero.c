#include "mpci-impl.h"

int
mpci_has_zero (mpci_srcptr a)
{
    return (mpfi_has_zero(a->real) &&
            mpfi_has_zero(a->imag));
}
