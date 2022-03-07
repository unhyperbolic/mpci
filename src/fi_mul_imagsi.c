#include "mpci-impl.h"

void
mpci_fi_mul_imagsi (mpci_ptr rop, mpfi_srcptr op1, long op2)
{
    switch(op2 % 4) {
    case 0:
        mpci_set_fi(rop, op1);
        break;
    case -2:
    case 2:
        mpfi_neg(rop->real, op1);
        mpfi_set_si(rop->imag, 0);
        break;
    case -3:
    case 1:
        mpfi_set(rop->imag, op1);
        mpfi_set(rop->real, 0);
        break;
    case -1:
    case 3:
        mpfi_neg(rop->imag, op1);
        mpfi_set(rop->real, 0);
        break;
    }
}
