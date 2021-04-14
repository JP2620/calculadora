#!/bin/bash

assert_equals () {
  if [ "$1" = "$2" ]; then
    echo -e "$Green $Check_Mark Success $Color_Off"
  else
    echo -e "$Red Failed $Color_Off"
    echo -e "$Red Expected -$1- to equal -$2- $Color_Off"
    Errors=$((Errors  + 1))
    exit 1
  fi
}
# Suma
response=$(./bin/calc e 2 + 2)
assert_equals "$response" "Error: Parametro invalido"

response=$(./bin/calc d 2 a 2)
assert_equals "$response" "Error: Operador invalido"

response=$(./bin/calc d 2 + 2a)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d 2 + hola)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d 2a + hola)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d hola + 2)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d 2 +)
assert_equals "$response" "Error: Cantidad de argumentos invalido"

response=$(./bin/calc d 2 + 2 5)
assert_equals "$response" "Error: Cantidad de argumentos invalido"

response=$(./bin/calc d 2147483648 + 2)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc d 2 + 2147483648)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc d 2147483646 + 2)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc d 2 + 2147483646)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc b 11111111111111111111111111111111 + 10)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc b 1 + 11111111111111111111111111111111)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc b 11121 + 1)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc b 1 + 11121)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc b 1111111111111111111111111111111 + 1)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc b 1 + 1111111111111111111111111111111)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc d 2 + 2)
assert_equals "$response" "(+) 4"

response=$(./bin/calc b 10 + 10)
assert_equals "$response" "(+) 100"

response=$(./bin/calc d -2 + 2)
assert_equals "$response" "(+) 0"

response=$(./bin/calc b -10 + 10)
assert_equals "$response" "(+) 0"

response=$(./bin/calc d 10 + -2)
assert_equals "$response" "(+) 8"

response=$(./bin/calc d -10 + -2)
assert_equals "$response" "(-) 12"

response=$(./bin/calc b -1010 + -10)
assert_equals "$response" "(-) 1100"


#resta
response=$(./bin/calc e 2 - 2)
assert_equals "$response" "Error: Parametro invalido"

response=$(./bin/calc d 2 -a 2)
assert_equals "$response" "Error: Operador invalido"

response=$(./bin/calc d 2 - 2a)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d 2 - hola)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d 2a - hola)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d hola - 2)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc d 2 -)
assert_equals "$response" "Error: Cantidad de argumentos invalido"

response=$(./bin/calc d 2 - 2 5)
assert_equals "$response" "Error: Cantidad de argumentos invalido"

response=$(./bin/calc d 2147483648 - 2)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc d 2 - 2147483648)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc d -2147483646 - 2)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc d -2 - 2147483646)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc b 11111111111111111111111111111111 - 10)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc b 1 - 11111111111111111111111111111111)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc b 11121 - 1)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc b 1 - 11121)
assert_equals "$response" "Error: Caracter invalido"

response=$(./bin/calc b -1111111111111111111111111111111 - 1)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc b -1 - 1111111111111111111111111111111)
assert_equals "$response" "Error: Resutado fuera del rango"

response=$(./bin/calc d 2 - 2)
assert_equals "$response" "(+) 0"

response=$(./bin/calc b 10 - 10)
assert_equals "$response" "(+) 0"

response=$(./bin/calc d -2 - 2)
assert_equals "$response" "(-) 4"

response=$(./bin/calc b -10 - 10)
assert_equals "$response" "(-) 100"

response=$(./bin/calc d 10 - -2)
assert_equals "$response" "(+) 12"

response=$(./bin/calc b 1010 - -10)
assert_equals "$response" "(+) 1100"

response=$(./bin/calc d -10 - -2)
assert_equals "$response" "(-) 8"

response=$(./bin/calc b -1010 - -10)
assert_equals "$response" "(-) 1000"