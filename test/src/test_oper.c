#include "../include/minunit.h"
#include "../../include/cdecl.h"

void PRE_CDECL calc_sum( int, int, int * ) POST_CDECL;

MU_TEST(test_sum_int)
{
    int resultado;
    calc_sum(4, 9, &resultado);
    mu_assert_int_eq(resultado, 13);
    
    calc_sum(300000, 100000, &resultado);
    mu_assert_int_eq(resultado, 400000);

    calc_sum(0, 300, &resultado);
    mu_assert_int_eq(resultado, 300);

    calc_sum(-300, 100, &resultado);
    mu_assert_int_eq(-200, resultado);

    calc_sum(-300, 400, &resultado);
    mu_assert_int_eq(100, resultado);
}

MU_TEST(test_sum_bin)
{

}

MU_TEST(test_res_int)
{

}

MU_TEST(test_res_bin)
{
    
}
