#include "mpci-impl.h"

void
mpci_add_fi (mpci_ptr rop,
             mpci_srcptr op1, mpfi_srcptr op2)
{
    mpfi_add (rop->real, op1->real, op2);
    mpfi_set (rop->imag, op1->imag);
}
