#include "mpci-tests.h"

#include "mpci-impl.h"

int
main (int argc, char **argv)
{
    check_data_mpci_fun_si_mpci (mpci_si_div, "si_div.dat");
    
    return 0;
}
