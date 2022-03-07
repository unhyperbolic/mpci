#include "mpci-impl.h"

void
mpcfi_mul_2si (mpci_ptr rop, mpci_srcptr op1, long op2)
{
    mpfi_mul_2si(rop->real, op1->real, op2);
    mpfi_mul_2si(rop->imag, op1->imag, op2);
}
