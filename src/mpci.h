#ifndef __MPFCI_H__
#define __MPFCI_H__

#include "mpfi.h"

/* Definition of main structure */
typedef struct  {
    mpfi_t real;
    mpfi_t imag;
}__mpci_struct;

typedef __mpci_struct mpci_t[1];
typedef __mpci_struct *mpci_ptr;
typedef __gmp_const __mpci_struct *mpci_srcptr;

#ifdef __cplusplus
extern "C" {
#endif

/* Initialization, destruction and assignment     */

/* Initialization */
void      mpci_init      (mpci_ptr);
void      mpci_init2     (mpci_ptr, mp_prec_t);

void      mpci_clear     (mpci_ptr);

/* mpci real/imag have the same precision */
mp_prec_t mpci_get_prec  (mpci_srcptr);
void      mpci_set_prec  (mpci_ptr, mp_prec_t);

/* assignment functions                           */
void      mpci_set       (mpci_ptr, mpci_srcptr);
void      mpci_set_si    (mpci_ptr, long);
void      mpci_set_si_si (mpci_ptr, long, long);
void      mpci_set_fi    (mpci_ptr, mpfi_srcptr);
void      mpci_set_fi_fi (mpci_ptr, mpfi_srcptr, mpfi_srcptr);
/* get real and imaginary part                    */
void      mpci_get_real  (mpfi_ptr, mpci_srcptr);
void      mpci_get_imag  (mpfi_ptr, mpci_srcptr);
    
/* swap two complex intervals                     */
void      mpci_swap      (mpci_ptr, mpci_ptr);


/* Basic arithmetic operations                    */

/* arithmetic operations between two complex interval operands */
void      mpci_add       (mpci_ptr,
                          mpci_srcptr, mpci_srcptr);
void      mpci_sub       (mpci_ptr,
                          mpci_srcptr, mpci_srcptr);
void      mpci_mul       (mpci_ptr,
                          mpci_srcptr, mpci_srcptr);
void      mpci_div       (mpci_ptr,
                          mpci_srcptr, mpci_srcptr);

/* arithmetic operations between a complex interval and an interval */
void      mpci_add_fi    (mpci_ptr,
                          mpci_srcptr, mpfi_srcptr);
void      mpci_sub_fi    (mpci_ptr,
                          mpci_srcptr, mpfi_srcptr);
void      mpci_fi_sub    (mpci_ptr,
                          mpfi_srcptr, mpci_srcptr);
void      mpci_mul_fi    (mpci_ptr,
                          mpci_srcptr, mpfi_srcptr);
void      mpci_div_fi    (mpci_ptr,
                          mpci_srcptr, mpfi_srcptr);
void      mpci_fi_div    (mpci_ptr,
                          mpfi_srcptr, mpci_srcptr);

/* arithmetic operations between a complex interval and a long integer */
void      mpci_add_si    (mpci_ptr,
                          mpci_srcptr, long);
void      mpci_sub_si    (mpci_ptr,
                          mpci_srcptr, long);
void      mpci_si_sub    (mpci_ptr,
                          long, mpci_srcptr);
void      mpci_mul_si    (mpci_ptr,
                          mpci_srcptr, long);
void      mpci_div_si    (mpci_ptr,
                          mpci_srcptr, long);
void      mpci_si_div    (mpci_ptr,
                          long, mpci_srcptr);
void      mpci_pow_si    (mpci_ptr,
                          mpci_srcptr, long);

/* arithmetic operations taking a single interval operand */
void      mpci_neg       (mpci_ptr, mpci_srcptr);
void      mpci_conj      (mpci_ptr, mpci_srcptr);
void      mpci_sqr       (mpci_ptr, mpci_srcptr);
/* the inv function generate the whole complex plane interval
   if 0 is in the interval defining the divisor   */
void      mpci_inv       (mpci_ptr, mpci_srcptr);
void      mpci_sqrt      (mpci_ptr, mpci_srcptr);
void      mpci_abs       (mpfi_ptr, mpci_srcptr);

/* multiply by powers of 2 or i                   */
void      mpci_mul_2si    (mpci_ptr, mpci_srcptr, long);
void      mpci_mul_imagsi (mpci_ptr, mpci_srcptr, long);
void      mpci_fi_mul_imagsi (mpci_ptr, mpfi_srcptr, long);

/* arg, log, exp                                  */
void      mpci_arg        (mpfi_ptr, mpci_srcptr);
void      mpci_log        (mpci_ptr, mpci_srcptr);
void      mpci_exp        (mpci_ptr, mpci_srcptr);
    
/* Comparison functions                           */
int       mpci_has_zero   (mpci_srcptr);

int       mpci_nan_p      (mpci_srcptr);
int       mpci_inf_p      (mpci_srcptr);
int       mpci_bounded_p  (mpci_srcptr);

/* Set operations                                 */
/* "Rectangular hulls" */
void      mpci_put        (mpci_ptr, mpci_srcptr);

/* Inclusion tests */
/* tests if the first argument is inside the interval */
int       mpci_is_strictly_inside (mpci_srcptr, mpci_srcptr);
int       mpci_is_inside  (mpci_srcptr, mpci_srcptr);

/* set operations */
int       mpci_is_empty   (mpci_srcptr);
void      mpci_intersect  (mpci_ptr, mpci_srcptr, mpci_srcptr);
void      mpci_union      (mpci_ptr, mpci_srcptr, mpci_srcptr);

#ifdef __cplusplus
}
#endif

#endif
