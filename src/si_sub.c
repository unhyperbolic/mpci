#include "mpci-impl.h"

void
mpci_si_sub (mpci_ptr rop,
             long op1, mpci_srcptr op2)
{
    mpfi_si_sub (rop->real, op1, op2->real);
    mpfi_neg    (rop->imag,      op2->imag);
}
