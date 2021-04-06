#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char **argv )  {
   int opt;
   int bflag = 0; // Flag para binario

   int operando_1, operando_2;
   char operador;

   opt = getopt(argc, argv, "b");
   if (opt == 'b')
      bflag = 1;
   
   printf("Ingrese la operación a realizar\n> ");
   scanf("%d %c %d", &operando_1, &operador, &operando_2);
   printf("Usted ingresó: %d %c %d", operando_1, operador, operando_2);

  return 0;

}


