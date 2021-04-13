#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/calc.h"

int bin_to_dec(int bin);
int dec_to_bin(int decimal);

int main(int argc, char **argv)
{
   // Inicializaciones
   int opt;
   int bflag = 0;    // Flag para binario
   char sig = '+';   // Signo resultante
   int overflow = 0; // Flag de desbordamiento

   int (*operacion)(int, int, int *);
   int operando_1, operando_2, resultado, bin_1, bin_2;
   char operador;

   // Parseo
   opt = getopt(argc, argv, "b");
   if (opt == 'b')
      bflag = 1;
   printf("Ingrese la operación a realizar\n> ");
   scanf("%d %c %d", &operando_1, &operador, &operando_2);
   printf("Usted ingresó: %d %c %d\n", operando_1, operador, operando_2);

   // Conversion de entrada
   if (bflag)
   {
      operando_1 = bin_to_dec(operando_1);
      operando_2 = bin_to_dec(operando_2);
   }

   // TODO: Estaria desperdiciando 2 numeros para detectar overflow. Ver si es mejor sacar esto
   if (operando_1 > abs(2147483646) || operando_2 > abs(2147483646))
   {
      printf("Error: Numeros fuera del rango\n");
      return 1;
   }

   // Ejecución de operaciones
   if (operador == '+')
      operacion = calc_sum;
   else if (operador == '-')
      operacion = calc_resta;
   else
      return 1;
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

   printf("El resultado es: (%c) %d\n", sig, resultado);
   return 0;
}

int bin_to_dec(int bin)
{
   int rem, decimal = 0, base = 1;
   while (bin > 0)
   {
      rem = bin % 10;
      decimal = decimal + rem * base;
      bin = bin / 10;
      base = base * 2;
   }
   return decimal;
}

int dec_to_bin(int decimal)
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