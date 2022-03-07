#include "mpci-tests.h"

#include "mpci-impl.h"

int
main (int argc, char **argv)
{
    check_data_mpci_fun_mpci_si(mpci_sub_si, "sub_si.dat");
    
    return 0;
}
