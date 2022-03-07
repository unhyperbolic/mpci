#include "mpci-impl.h"

void
mpci_add (mpci_ptr rop,
          mpci_srcptr op1, mpci_srcptr op2)
{
    mpfi_add(rop->real, op1->real, op2->real);
    mpfi_add(rop->imag, op1->imag, op2->imag);    
}
