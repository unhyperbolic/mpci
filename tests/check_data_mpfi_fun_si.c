#include "mpci-tests.h"

#include <stdlib.h>

extern int nextchar;

void
check_data_mpfi_fun_si (mpfi_fun_si function,
                        const char *file_name)
{
    FILE  *fp;
    long   op;

    mpfi_t result, expected;

    fp = open_file (file_name);

    init_reading (fp);

    while (nextchar != EOF) {
        mpfi_init(expected);
        
        read_si   (fp, &op);
        read_mpfi (fp, expected);

        mpfi_init2 (result, mpfi_get_prec (expected));

        function (result, op);

        if (!are_mpfi_results_equal(result, expected)) {
            printf ("Unexpected result!!!\n");
            printf ("Inputs:\n"); 
            printf ("op=%d\n", op);

            print_mpfi_expected_and_result (expected, result);
            
            exit (1);
        }

        mpfi_clear (result);
        mpfi_clear (expected);
    }

    close_file (fp);
}
