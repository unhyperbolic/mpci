#include "mpci-tests.h"

#include <stdlib.h>

extern int nextchar;

void
check_data_mpci_fun_mpci_mpci (mpci_fun_mpci_mpci function,
                               const char *file_name)
{
    FILE *fp;
    mpci_t op1, op2, orig_op1, orig_op2;
    mpci_t result, expected;

    fp = open_file (file_name);

    init_reading (fp);

    while (nextchar != EOF) {
        mpci_init(op1);
        mpci_init(op2);
        mpci_init(expected);
        
        read_mpci (fp, op1);
        read_mpci (fp, op2);
        read_mpci (fp, expected);

        mpci_init2 (result, mpci_get_prec (op1));
        mpci_init2 (orig_op1, mpci_get_prec (op1));
        mpci_init2 (orig_op2, mpci_get_prec (op2));

        mpci_set (orig_op1, op1);
        mpci_set (orig_op2, op2);

        function (result, op1, op2);

        if (!are_mpci_results_equal(op1, orig_op1)) {
            printf ("Operator 1 was modified!!!\n");
            exit (1);
        }

        if (!are_mpci_results_equal(op2, orig_op2)) {
            printf ("Operator 2 was modified!!!\n");
            exit (1);
        }

        if (!are_mpci_results_equal(result, expected)) {
            printf ("Unexpected result!!!\n");
            printf ("Inputs:\n");
            printf ("op1=");
            print_mpci_decimal (op1);
            printf ("\nop2=");
            print_mpci_decimal (op2);
            printf ("\n");

            print_mpci_expected_and_result (expected, result);
            
            exit (1);
        }

        mpci_set (result, op1);

        function (result, result, op2);

        if (!are_mpci_results_equal(result, expected)) {
            printf ("Unexpected result (when operator1 = result)!!!\n");
            printf ("Inputs:\n");
            printf ("op1=");
            print_mpci_decimal (op1);
            printf ("\nop2=");
            print_mpci_decimal (op2);
            printf ("\n");

            print_mpci_expected_and_result (expected, result);
            
            exit (1);
        }

        if (!are_mpci_results_equal(op2, orig_op2)) {
            printf ("Operator 2 was modified (when operator1 = result)!!!\n");
            exit (1);
        }

        mpci_set (result, op2);

        function (result, op1, result);

        if (!are_mpci_results_equal(result, expected)) {
            printf ("Unexpected result (when operator2 = result)!!!\n");
            printf ("Inputs:\n");
            printf ("op1=");
            print_mpci_decimal (op1);
            printf ("\nop2=");
            print_mpci_decimal (op2);
            printf ("\n");

            print_mpci_expected_and_result (expected, result);
            
            exit (1);
        }

        if (!are_mpci_results_equal(op1, orig_op1)) {
            printf ("Operator 1 was modified (when operator2 = result)!!!\n");
            exit (1);
        }

        mpci_clear (op1);
        mpci_clear (op2);
        mpci_clear (orig_op1);
        mpci_clear (orig_op2);
        mpci_clear (result);
        mpci_clear (expected);
    }

    close_file (fp);
}
