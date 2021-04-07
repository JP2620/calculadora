#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/calc.h"


int main( int argc, char **argv )  {
   // Inicializaciones
   int opt;
   int bflag = 0; // Flag para binario

   void (*operacion)(int, int, int*);
   int operando_1, operando_2, resultado;
   char operador;

   // Parseo
   opt = getopt(argc, argv, "b");
   if (opt == 'b')
      bflag = 1;   
   printf("Ingrese la operación a realizar\n> ");
   scanf("%d %c %d", &operando_1, &operador, &operando_2);
   printf("Usted ingresó: %d %c %d\n", operando_1, operador, operando_2);


   // Ejecución de operaciones
   if (operador == '+')
      operacion = calc_sum;
   else if (operador == '-')
      operacion = calc_resta;
   else 
      return 1;
   operacion(operando_1, operando_2, &resultado);
   printf("El resultado es: %d\n", resultado);
   return 0;

}


