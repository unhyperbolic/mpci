#ifndef __COMPLEXMPFI_IMPL_H__
#define __COMPLEXMPFI_IMPL_H__

#include "mpci.h"

void mpci_error_box (mpci_ptr rop, mpfi_srcptr size);

/* Returns [-r, r] + [-r, r] * I */
void mpci_error_box2 (mpci_ptr rop, mpfr_srcptr size);

/* Computes |z| of a complex interval, rounded up, i.e.,
   it is guarenteed that the result is >= than |z| */
void mpci_upper_abs     (mpfr_ptr rop, mpci_srcptr op);

/* Computes |z|^2, similar to mpci_upper_abs */
void mpci_upper_sqr_abs (mpfr_ptr rop, mpci_srcptr op);

/* Returns the maximum of the absolute diameter of the
   real and of the complex interval */
void mpci_diam_abs_sup  (mpfr_ptr rop, mpci_srcptr op);

#endif
