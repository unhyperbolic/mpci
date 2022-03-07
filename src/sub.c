#include "mpci-impl.h"

void
mpci_sub (mpci_ptr rop,
          mpci_srcptr op1, mpci_srcptr op2)
{
    mpfi_sub(rop->real, op1->real, op2->real);
    mpfi_sub(rop->imag, op1->imag, op2->imag);    
}
