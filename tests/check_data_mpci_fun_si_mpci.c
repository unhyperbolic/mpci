#include "mpci-tests.h"

#include <stdlib.h>

extern int nextchar;

void
check_data_mpci_fun_si_mpci (mpci_fun_si_mpci function,
                             const char *file_name)
{
    FILE  *fp;
    long   op1;
    mpci_t op2;

    mpci_t result, expected;

    fp = open_file (file_name);

    init_reading (fp);

    while (nextchar != EOF) {
        mpci_init(op2);
        mpci_init(expected);
        
        read_si   (fp, &op1);
        read_mpci (fp, &op2);
        read_mpci (fp, expected);

        mpci_init2 (result, mpci_get_prec (op2));

        function (result, op1, op2);

        if (!are_mpci_results_equal(result, expected)) {
            printf ("Unexpected result!!!\n");
            printf ("Inputs:\n"); 
            printf ("\nop1=%d\n", op1);
            printf ("op2=");
            print_mpci_decimal (op2);
            printf ("\n");

            print_mpci_expected_and_result (expected, result);
            
            exit (1);
        }

        mpci_clear (op2);
        mpci_clear (result);
        mpci_clear (expected);
    }

    close_file (fp);
}
