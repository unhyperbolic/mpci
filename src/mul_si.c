#include "mpci-impl.h"

void
mpci_mul_si (mpci_ptr rop,
             mpci_srcptr op1, long op2)
{
    mpfi_mul_si (rop->real, op1->real, op2);
    mpfi_mul_si (rop->imag, op1->imag, op2);
}
