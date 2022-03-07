#include "mpci-impl.h"

void
mpci_pow_si(mpci_ptr rop,
            mpci_srcptr op1, long op2)
{
    mpci_t s;
    
    if (op2 == -1) {
        mpci_inv (rop, op1);
        return;
    }

    if (op2 == -2) {
        mpci_sqr (rop, op1);
        mpci_inv (rop, rop);
        return;
    }
    
    if (op2 < 0) {
        mpci_pow_si (rop, op1, -op2);
        mpci_inv (rop, rop);
        return;
    }

    if (op2 == 0) {
        mpci_set_si (rop, 1);
        return;
    }

    if (op2 == 1) {
        mpci_set (rop, op1);
        return;
    }

    if (op2 == 2) {
        mpci_sqr(rop, op1);
        return;
    }

    if (op2 % 2) {
        mpci_init2 (s, mpci_get_prec(op1));
        mpci_set (s, op1);
    }

    mpci_pow_si(rop, op1, op2 / 2);
    mpci_sqr(rop, rop);

    if (op2 % 2) {
        mpci_mul(rop, rop, s);
        mpci_clear(s);
    }
}
