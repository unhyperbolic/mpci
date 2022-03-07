#include "mpci-impl.h"

int
mpci_is_strictly_inside (mpci_srcptr a, mpci_srcptr b)
{
    return (
        mpfi_is_strictly_inside (a->real, b->real) &&
        mpfi_is_strictly_inside (a->imag, b->imag));
}

int
mpci_is_inside (mpci_srcptr a, mpci_srcptr b)
{
    return (
        mpfi_is_inside (a->real, b->real) &&
        mpfi_is_inside (a->imag, b->imag));
}

