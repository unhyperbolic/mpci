#include "mpci-impl.h"

void
mpci_abs (mpfi_ptr rop, mpci_srcptr op)
{
    mpfi_t s;
    mpfi_init2 (s, mpci_get_prec(op));
    
    mpfi_sqr  (rop, op->real);
    mpfi_sqr  (s, op->imag);
    mpfi_add  (rop, rop, s);
    mpfi_sqrt (rop, rop);
    
    mpfi_clear(s);
}
