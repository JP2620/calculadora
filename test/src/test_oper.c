#include "../include/minunit.h"
#include "../../include/calc.h"


MU_TEST(test_sum_int)
{
    int resultado;
    resultado = calc_sum(4, 9);
    mu_assert_int_eq(resultado, 13);
    
    resultado = calc_sum(300000, 100000);
    mu_assert_int_eq(resultado, 400000);

    resultado = calc_sum(0, 300);
    mu_assert_int_eq(resultado, 300);

    resultado = calc_sum(-300, 100);
    mu_assert_int_eq(-200, resultado);

    resultado = calc_sum(-300, 400);
    mu_assert_int_eq(100, resultado);
}

MU_TEST(test_sum_bin)
{

}

MU_TEST(test_res_int)
{
    int resultado;
    resultado = calc_resta(4, 9);
    mu_assert_int_eq(resultado, -5);
    
    resultado = calc_resta(300000, 100000);
    mu_assert_int_eq(resultado, 200000);

    resultado = calc_resta(0, 300);
    mu_assert_int_eq(resultado, -300);

    resultado = calc_resta(-300, 100);
    mu_assert_int_eq(-400, resultado);

    resultado = calc_resta(-300, 400);
    mu_assert_int_eq(-700, resultado);

    resultado = calc_resta(-300, 0);
    mu_assert_int_eq(-300, resultado);
}

MU_TEST(test_res_bin)
{
    
}
