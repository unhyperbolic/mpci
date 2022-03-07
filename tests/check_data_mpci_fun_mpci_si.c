#include "mpci-tests.h"

#include <stdlib.h>

extern int nextchar;

void
check_data_mpci_fun_mpci_si (mpci_fun_mpci_si function,
                             const char *file_name)
{
    FILE  *fp;
    mpci_t op1;
    long   op2;

    mpci_t result, expected;

    fp = open_file (file_name);

    init_reading (fp);

    while (nextchar != EOF) {
        mpci_init(op1);
        mpci_init(expected);
        
        read_mpci (fp, op1);
        read_si   (fp, &op2);
        read_mpci (fp, expected);

        mpci_init2 (result, mpci_get_prec (op1));

        function (result, op1, op2);

        if (!are_mpci_results_equal(result, expected)) {
            printf ("Unexpected result!!!\n");
            printf ("Inputs:\n");
            printf ("op1=");
            print_mpci_decimal (op1);
            printf ("\nop2=%d\n", op2);

            print_mpci_expected_and_result (expected, result);
            
            exit (1);
        }

        mpci_clear (op1);
        mpci_clear (result);
        mpci_clear (expected);
    }

    close_file (fp);
}
