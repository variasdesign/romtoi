**# Desafío 01: Números romanos (romtoi)**
**Dificultad:** Fácil
**Complejidad:** Intermedio

**Descripción:**
Crear un programa que transforme una cadena de texto con números romanos e imprima el equivalente en cifras arábigas.

**## Requisitos de entrada/salida:**
El programa debe aceptar una cadena de texto con números romanos.

**### Entrada:**
- Un sólo argumento que contenga una cadena de texto de números romanos en mayúsculas.

**### Salida:**
- Imprimir en pantalla el equivalente en cifras arábigas (0123456789).

**Especificaciones adicionales:**
Para la notación moderna de las cifras romanas se utilizan las siguientes normas:

- Las cifras se leen de izquierda a derecha empezando por los símbolos con mayor valor, o conjunto de símbolos de mayor valor.
- Un símbolo seguido de otro de igual o inferior valor, suma (p. ej., X·X·I = 10+10+1 = 21), mientras que si está seguido de otro de mayor valor, ambos símbolos forman un conjunto en el cual debe restarse el valor del primero al valor del siguiente (p. ej., X·IX = 10+(10-1) = 19).
- La unidad (I) y los números con base 10 (X, C y M) pueden repetirse hasta 3 veces consecutivas como sumandos.
- Los números con base 5 (V, L y D), no pueden repetirse seguidos, ya que la suma de esos dos símbolos tiene representación con alguno de los símbolos anteriores.
- La unidad y los símbolos de base 10 también pueden estar restando antes de un símbolo de mayor valor, pero con las siguientes normas:
  1) Sólo pueden aparecer restando sobre los símbolos con base 5 y 10 de valor inmediatamente superior, pero no de otros con valores más altos (p. ej., 'IV', 'IX' o 'XC', pero no 'IL' ni 'IC' ni 'XM').
  2) En el caso de estar restando, no pueden repetirse.
- Los símbolos con base 5 no pueden utilizarse para restar (p. ej., 45 se escribe 'XLV' y no 'VL').

**### Bonus:**
1) Si el único argumento es un número entero devolver su equivalente en Nº romanos.
2) Que el programa acepte una opción de --help y que imprima en pantalla el uso adecuado del programa y qué es lo que hace.
3) Al entregar errores imprimir en pantalla el caso específico que falla, no solo "error"

Archivos permitidos: Todos los que sean necesarios, el makefile no es obligatorio
Librerías permitidas: unistd.h

No es necesaria la adhesión a las normas de 42, pero si debe poderse ejecutar con cc -Werror -Wextra -Wall

Posibles habilidades y conceptos a entrenar:
- Manipulación de cadenas de texto
- Manipulación de argumentos de linea de comandos
- Gestión de errores y casos concretos
- Lógica condicional y aritmética
- Uso de headers
