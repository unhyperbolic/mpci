#include "mpci-impl.h"

void
mpci_div_fi (mpci_ptr rop,
             mpci_srcptr op1, mpfi_srcptr op2)
{
    mpfi_div (rop->real, op1->real, op2);
    mpfi_div (rop->imag, op1->imag, op2);
}
