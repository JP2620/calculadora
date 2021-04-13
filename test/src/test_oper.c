#include "../include/minunit.h"
#include "../../include/calc.h"

MU_TEST(test_sum_int)
{
    int resultado;
    int overflow = 0;
    resultado = calc_sum(4, 9, &overflow);
    mu_assert_int_eq(resultado, 13);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_sum(300000, 100000, &overflow);
    mu_assert_int_eq(resultado, 400000);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_sum(0, 300, &overflow);
    mu_assert_int_eq(resultado, 300);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_sum(-300, 100, &overflow);
    mu_assert_int_eq(-200, resultado);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_sum(-300, 400, &overflow);
    mu_assert_int_eq(100, resultado);
    mu_assert_int_eq(overflow, 0);

    overflow = 0;
    resultado = calc_sum(2147483646, 3, &overflow);
    mu_assert_int_eq(overflow, 1);

    overflow = 0;
    resultado = calc_sum(2147483646, 2147483646, &overflow);
    mu_assert_int_eq(overflow, 1);

    overflow = 0;
    resultado = calc_sum(-2147483646, -10, &overflow);
    mu_assert_int_eq(overflow, 1);
}

MU_TEST(test_res_int)
{
    int resultado;
    int overflow = 0;
    resultado = calc_resta(4, 9, &overflow);
    mu_assert_int_eq(resultado, -5);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_resta(300000, 100000, &overflow);
    mu_assert_int_eq(resultado, 200000);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_resta(0, 300, &overflow);
    mu_assert_int_eq(resultado, -300);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_resta(-300, 100, &overflow);
    mu_assert_int_eq(-400, resultado);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_resta(-300, 400, &overflow);
    mu_assert_int_eq(-700, resultado);
    mu_assert_int_eq(overflow, 0);

    resultado = calc_resta(-300, 0, &overflow);
    mu_assert_int_eq(-300, resultado);
    mu_assert_int_eq(overflow, 0);

    overflow = 0;
    resultado = calc_resta(-2147483646, 3, &overflow);
    mu_assert_int_eq(overflow, 1);

    overflow = 0;
    resultado = calc_resta(-2147483646, 2147483646, &overflow);
    mu_assert_int_eq(overflow, 1);

    overflow = 0;
    resultado = calc_resta(2147483646, -10, &overflow);
    mu_assert_int_eq(overflow, 1);
}