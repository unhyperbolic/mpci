#include "mpci-impl.h"

void
mpci_neg (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_neg (rop->real, op->real);
    mpfi_neg (rop->imag, op->imag);
}
