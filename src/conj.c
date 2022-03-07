#include "mpci-impl.h"

void
mpci_conj (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_set (rop->real, op->real);
    mpfi_neg (rop->imag, op->imag);
}
