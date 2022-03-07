#include "mpci-impl.h"

void
mpci_div_si (mpci_ptr rop,
             mpci_srcptr op1, long op2)
{

    if (op2 == 0) {
        mpfr_set_nan (&(rop->real->left));
        mpfr_set_nan (&(rop->real->right));
        mpfr_set_nan (&(rop->imag->left));
        mpfr_set_nan (&(rop->imag->right));
        return;
    }
    
    mpfi_div_si (rop->real, op1->real, op2);
    mpfi_div_si (rop->imag, op1->imag, op2);
}
