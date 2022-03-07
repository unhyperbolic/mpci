#include "mpci-impl.h"

void
mpci_swap (mpci_ptr a, mpci_ptr b)
{
    mpfi_swap(a->real, b->real);
    mpfi_swap(a->imag, b->imag);
}
