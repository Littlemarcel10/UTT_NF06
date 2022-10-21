#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//test ctypes simple
void hello()
{
    printf("Hello World");
}
//On fait une DDL et on l'utilise dans le fichier python
int ajoute_entiers(int a, int b)
{
    printf("Ca marche peut etre");
    return a+b;
}
double moyenne(double a, double b) {
    return (a + b)/2;
}