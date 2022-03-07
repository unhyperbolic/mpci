#include "mpci-tests.h"

#include <stdlib.h>

extern int nextchar;

void
check_data_mpci_fun_mpci (mpci_fun_mpci function, const char *file_name)
{
    FILE *fp;
    mpci_t op;
    mpci_t result, expected;

    fp = open_file (file_name);

    init_reading (fp);

    while (nextchar != EOF) {
        mpci_init(op);
        mpci_init(expected);
        
        read_mpci (fp, op);
        read_mpci (fp, expected);

        mpci_init2 (result, mpci_get_prec (op));

        function (result, op);

        if (!are_mpci_results_equal(result, expected)) {
            printf ("Unexpected result!!!\n");
            printf ("Inputs:\n");
            printf ("op= ");
            print_mpci_decimal (op);
            printf ("\n");

            print_mpci_expected_and_result (expected, result);
            
            exit (1);
        }

        mpci_clear (op);
        mpci_clear (result);
        mpci_clear (expected);
    }

    close_file (fp);
}
