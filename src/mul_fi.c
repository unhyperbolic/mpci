#include "mpci-impl.h"

void
mpci_mul_fi (mpci_ptr rop,
             mpci_srcptr op1, mpfi_srcptr op2)
{
    mpfi_mul (rop->real, op1->real, op2);
    mpfi_mul (rop->imag, op1->imag, op2);
}
