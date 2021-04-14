#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/calc.h"

int32_t bin_to_dec(int32_t bin);
int32_t dec_to_bin(int32_t decimal);
int32_t verification_unit(const char *argv);
int32_t verification_opt(const char *argv);
int32_t verification_num(const char *argv);

int32_t main(int32_t argc, char **argv)
{
   // Inicializaciones
   
   int32_t opt;
   int32_t bflag = 0;    // Flag para binario
   char sig = '+';   // Signo resultante
   int32_t overflow = 0; // Flag de desbordamiento

   int32_t (*operacion)(int32_t, int32_t, int32_t *);
   int32_t operando_1, operando_2, resultado, bin_1, bin_2;

   if (argc != 5)
   {
      printf("Error: Cantidad de argumentos invalido\n");
      return 1;
   }

   bflag = verification_unit(argv[1]);

   if (verification_opt(argv[3]) == 1)
   {
      operacion = calc_sum;
   }
   else
   {
      operacion = calc_resta;
   }

   operando_1 = verification_num(argv[2]);
   operando_2 = verification_num(argv[4]);

   // Conversion de entrada
   if (bflag)
   {
      operando_1 = bin_to_dec(operando_1);
      operando_2 = bin_to_dec(operando_2);
   }

   // // TODO: Estaria desperdiciando 2 numeros para detectar overflow. Ver si es mejor sacar esto
   // if (operando_1 > abs(2147483646) || operando_2 > abs(2147483646))
   // {
   //    printf("Error: Numeros fuera del rango\n");
   //    return 1;
   // }

   resultado = operacion(operando_1, operando_2, &overflow);

   if (resultado < 0)
   {
      resultado *= (-1);
      sig = '-';
   }

   if (overflow)
   {
      printf("Error: Resutado fuera del rango\n");
      return 1;
   }

   // Conversion de entrada
   if (bflag)
      resultado = dec_to_bin(resultado);

   printf("(%c) %d\n", sig, resultado);
   return 0;
}

int32_t bin_to_dec(int32_t bin)
{
   int32_t rem, decimal = 0, base = 1;
   while (bin > 0)
   {
      rem = bin % 10;
      decimal = decimal + rem * base;
      bin = bin / 10;
      base = base * 2;
   }
   return decimal;
}

int32_t dec_to_bin(int32_t decimal)
{
   if (decimal == 0)
   {
      return 0;
   }
   else
   {
      return (decimal % 2 + 10 * dec_to_bin(decimal / 2));
   }
}

int32_t verification_unit(const char *argv)
{
   int32_t bflag = 0;
   if (strlen(argv) == 1)
   {
      if (argv[0] == 'b')
         bflag = 1;
      else if (argv[0] != 'd')
      {
         printf("Error: Parametro invalido\n");
         exit(1);
      }
   }
   else
   {
      printf("Error: Parametro invalido\n");
      exit(1);
   }
   return bflag;
}

int32_t verification_opt(const char *argv)
{
   if (strlen(argv) == 1)
   {
      if (argv[0] == '+')
         return 1;
      else if (argv[0] == '-')
         return 2;
      else
      {
         printf("Error: Operador invalido\n");
         exit(1);
      }
   }
   else
   {
      printf("Error: Operador invalido\n");
      exit(1);
   }
}

int32_t verification_num(const char *argv)
{
   int32_t num = 0;
   int32_t piv = 0;
   int32_t neg = 1;

   if (argv[0] == '-' || argv[0] == '+')
   {
      piv = 1;
      if (argv[0] == '-')
         neg = -1;
   }

   for (int32_t i = 0 + piv; i < strlen(argv); i++)
   {
      if (argv[i] >= '0' && argv[i] <= '9')
      {
         if(argv[i] - '0' > (2147483647 - num * 10)){
            printf("Error: Numeros fuera del rango\n");
            exit(1);
         }
         num = num * 10 + (int)(argv[i] - '0');
      }
      else
      {
         printf("Error: Caracter invalido\n");
         exit(1);
      }
   }
   return num*neg;
}