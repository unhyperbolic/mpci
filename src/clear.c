#include "mpci-impl.h"

void
mpci_clear (mpci_ptr a)
{
    /* There is no test to check that real and imag are different and thus not
       cleared twice. They should be different if only mpci functions
       have been used... */

    mpfi_clear(a->real);
    mpfi_clear(a->imag);
}
