#include "mpci-impl.h"

void
mpci_union (mpci_ptr a, mpci_srcptr b, mpci_srcptr c)
{
    mpfi_union (a->real, b->real, c->real);
    mpfi_union (a->imag, b->imag, c->imag);
}
