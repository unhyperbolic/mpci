#include "mpci-impl.h"

void
mpci_fi_sub (mpci_ptr rop,
             mpfi_srcptr op1, mpci_srcptr op2)
{
    mpfi_sub (rop->real, op1, op2->real);
    mpfi_neg (rop->imag,      op2->imag);
}
