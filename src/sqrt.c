#include "mpci-impl.h"

void
mpci_sqrt (mpci_ptr rop, mpci_srcptr op)
{
    mpfi_t re;
    mpfi_t arg;
    mpfi_init2 (re,  mpci_get_prec(op));
    mpfi_init2 (arg, mpci_get_prec(op));

    mpci_abs  (re, op);
    mpfi_sqrt (re, re);

    mpci_arg  (arg, op);
    mpfi_mul_2si (arg, arg, -1);

    mpfi_cos (rop->real, arg);
    mpfi_mul (rop->real, rop->real, re);
    mpfi_sin (rop->imag, arg);
    mpfi_mul (rop->imag, rop->imag, re);
    
    mpfi_clear (re);
    mpfi_clear (arg);
}
