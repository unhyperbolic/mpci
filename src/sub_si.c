#include "mpci-impl.h"

void
mpci_sub_si (mpci_ptr rop,
             mpci_srcptr op1, long op2)
{
    mpfi_sub_si (rop->real, op1->real, op2);
    mpfi_set    (rop->imag, op1->imag);
}
