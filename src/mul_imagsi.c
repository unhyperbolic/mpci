#include "mpci-impl.h"

void
mpci_mul_imagsi (mpci_ptr rop, mpci_srcptr op1, long op2)
{
    mpfi_t tmp;
    
    switch (op2 % 4) {
    case 0:
        mpci_set (rop, op1);
        break;
    case -2:
    case 2:
        mpci_neg (rop, op1);
        break;
    case -3:
    case 1:
        mpfi_init2 (tmp,       mpci_get_prec (op1));
        mpfi_set   (tmp,       op1->real);
        mpfi_neg   (rop->real, op1->imag);
        mpfi_set   (rop->imag, tmp);
        mpfi_clear (tmp);
        break;
    case -1:
    case 3:
        mpfi_init2 (tmp,       mpci_get_prec (op1));
        mpfi_set   (tmp,       op1->real);
        mpfi_set   (rop->real, op1->imag);
        mpfi_neg   (rop->imag, tmp);
        mpfi_clear (tmp);
        break;
    }
}
