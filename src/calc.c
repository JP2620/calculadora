/**
 * @file calc.c
 * @author Juan Ignacio Fernandez (juanfernandez@mi.unc.edu.ar)
 * @brief Codigo principal
 * 
 */
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/calc.h"

int32_t bin_to_dec(const char *argv);
void printf_bin(int32_t value);
int32_t verification_unit(const char *argv);
int32_t verification_opt(const char *argv);
int32_t verification_num(const char *argv);

/**
 * @brief 
 * 
 * @param argc Cantidad de argumentos pasados en la ejecucion del bin
 * @param argv Array con los argumentos pasados en la ejecucion del bin
 * @return int32_t 1-> Error ; 0-> Finalizacion correcta
 */
int32_t main(int32_t argc, char **argv)
{
   // Inicializaciones
   char *resultado_bin;
   int32_t opt;
   int32_t bflag = 0;    // Flag para binario
   char sig = '+';       // Signo resultante
   int32_t overflow = 0; // Flag de desbordamiento

   int32_t (*operacion)(int32_t, int32_t, int32_t *);
   int32_t operando_1, operando_2, resultado, bin_1, bin_2;

   // Verificacion de parametros y procesado de los mismo
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

   if (bflag)
   {
      operando_1 = bin_to_dec(argv[2]);
      operando_2 = bin_to_dec(argv[4]);
   }
   else
   {
      operando_1 = verification_num(argv[2]);
      operando_2 = verification_num(argv[4]);
   }

   // Ejecucion de programa en asm (suma/resta)
   resultado = operacion(operando_1, operando_2, &overflow);

   // Deteccion de overflow
   if (overflow || resultado == -2147483648)
   {
      printf("Error: Resutado fuera del rango\n");
      return 1;
   }

   // Asignacion de signo del resultado
   if (resultado < 0)
   {
      resultado = abs(resultado);
      sig = '-';
   }

   // Print resultado
   if (bflag)
   {
      printf("(%c) ", sig);
      printf_bin(resultado);
      printf("\n");
   }
   else
      printf("(%c) %d\n", sig, resultado);

   return 0;
}

/**
 * @brief Realiza convierte el numero en binario a decimal
 * 
 * @param argv Arreglo que contiene el numero en binario
 * @return int32_t Numero convertido en decimal
 */
int32_t bin_to_dec(const char *argv)
{
   int32_t rem, decimal = 0, base = 1;
   int32_t num = 0, piv = 0, neg = 1;

   if (strlen(argv) > 1 && (argv[0] == '-' || argv[0] == '+'))
   {
      piv = 1;
      if (argv[0] == '-')
         neg = -1;
   }
   else if (argv[0] != '0' && argv[0] != '1')
   {
      printf("Error: Caracter invalido\n");
      exit(1);
   }

   for (int32_t i = strlen(argv) - 1; i >= 0 + piv; i--)
   {
      if (argv[i] != '0' && argv[i] != '1')
      {
         printf("Error: Caracter invalido\n");
         exit(1);
      }
      rem = argv[i] - '0';
      if (rem * (base - '0') > (2147483647 - decimal))
      {
         printf("Error: Numeros fuera del rango\n");
         exit(1);
      }
      decimal = decimal + rem * base;
      base = base * 2;
   }
   return decimal * neg;
}

/**
 * @brief Verifica que unidad de numero se ingresara (b-> binario; d-> decimal; otro->error). Si no es valido termina el programa
 * 
 * @param argv Arreglo que contiene el tipo de unidad (b o d)
 * @return int32_t 1-> binario; 0-> decimal
 */
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

/**
 * @brief Verifica que operacion se desea realizar (+;-). Si no es valido termina el programa
 * 
 * @param argv Arreglo que contiene la operacion a realizar
 * @return int32_t 1-> suma; 2-> resta
 */
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

/**
 * @brief Verifica que operacion se desea realizar (+;-). Si no es valido termina el programa
 * 
 * @param argv Arreglo que contiene la operacion a realizar
 * @return int32_t 1-> suma; 2-> resta
 */
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
         if (argv[i] - '0' > (2147483647 - num * 10))
         {
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
   return num * neg;
}

void printf_bin(int32_t value)
{
   char bin[32];
   int i = -1;
   
   if(value==0){
      printf("0");
      return;
   }
   while (value != 0)
   {
      i++;
      bin[i] = (value % 2) + '0';
      value /= 2;
   }
   for (int j = i; j >= 0; j--)
   {
      printf("%c", bin[j]);
   }
}