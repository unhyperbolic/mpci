#include "mpci-impl.h"

void
mpci_intersect (mpci_ptr a, mpci_srcptr b, mpci_srcptr c)
{
    mpfi_intersect (a->real, b->real, c->real);
    mpfi_intersect (a->imag, b->imag, c->imag);
}
