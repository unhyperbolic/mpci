#include "mpci-tests.h"

#include "mpci-impl.h"

int
main (int argc, char **argv)
{
    check_data_mpci_fun_mpci_si (mpci_mul_si, "mul_si.dat");
    
    return 0;
}
