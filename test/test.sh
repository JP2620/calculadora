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

response=$(./bin/calc d 2147483647 + 2)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc d 2 + 2147483647)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc b 111111111111111111111111111111111 + 10)
assert_equals "$response" "Error: Numeros fuera del rango"

response=$(./bin/calc d 2 + 2)
assert_equals "$response" "(+) 4"
