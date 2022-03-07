#include "mpci-tests.h"

int
main (int argc, char **argv)
{
    unsigned long prec;
    mpfr_t a;

    
    if (argc == 3) {
        sscanf(argv[1], "%lu", &prec);
        mpfr_init2(a, prec);

        mpfr_strtofr(a, argv[2], 0, 0, MPFR_RNDN);

        mpfr_printf("%Re\n", a);
        
        mpfr_printf("%Ra\n", a);
        
    }

    return 0;
}
