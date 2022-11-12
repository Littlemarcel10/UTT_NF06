// Some revisions before the midterm exam .
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void exo1(){
    int tableau[10];
    int indice1, indice2;
    int i, temp;
    for ( i = 0; i < 10; i++)
    {
        tableau[i]= i;
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d\t", tableau[i]);
    }
    printf("\n");
    printf("Veuillez entrer l'indice1 de votre tableau\n");
    scanf("%d", &indice1);
    printf("Veuillez entrer l'indice2 de votre tableau\n");
    scanf("%d", &indice2);
    temp = tableau[indice1];
    tableau[indice1] = tableau[indice2];
    tableau[indice2] = temp;

    for ( i = 0; i < 10; i++)
    {
        printf("%d\t", tableau[i]);
    }

}

typedef struct 
{
    int reel;
    int imaginaire;
}cartesien;

typedef struct 
{
    float module;
    int argument;
}polaire;

typedef struct Clpx
{
    cartesien clpx_cartesien;
    polaire clpx_polaire;
};

void transform(){
    cartesien clpx1;
    polaire clpx2;
    printf("Veuillez entrer la partie reelle de votre complexe\n");
    scanf("%d", &clpx1.reel );
    printf("Partie imaginaire\n");
    scanf("%d", &clpx1.imaginaire);

    int a = clpx1.reel;
    int b = clpx1.imaginaire;

    a = a*a;
    b = b*b;
    int c = a+b;
    float z = sqrt(c);
    
    clpx2.module = z;

    printf("%d \t %d\t %.2f\t", clpx1.reel, clpx1.imaginaire, clpx2.module);



}

void exo2(){
    transform();
}

int main(){
    int choix;
    printf("Veuillez entrer votre choix\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        exo1();
        break;
    
    case 2:
        exo2();
        break;

    default:
        break;
    }
}