#include "mpci-impl.h"

int
mpci_nan_p (mpci_srcptr a)
{
    return (mpfi_nan_p (a->real)) || (mpfi_nan_p (a->imag));
}

int
mpci_inf_p (mpci_srcptr a)
{
    return (mpfi_inf_p (a->real)) || (mpfi_inf_p (a->imag));
}

int
mpci_bounded_p (mpci_srcptr a)
{
    return (mpfi_bounded_p (a->real)) && (mpfi_bounded_p (a->imag));
}

