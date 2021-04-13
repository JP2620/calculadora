#include "../include/minunit.h"
#include "test_oper.c"

MU_TEST_SUITE(calc_test_suite)
{
    MU_RUN_TEST(test_sum_int);
    MU_RUN_TEST(test_res_int);
}

int main()
{
    MU_RUN_SUITE(calc_test_suite);
    MU_REPORT();

    // Para que rebote el build jenkins, tiene que devolver 1
    if (minunit_fail > 0)
        return 1;
    else
        return 0;
}
