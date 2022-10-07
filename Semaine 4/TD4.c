#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void exo_46(){
    //Opération sur les tableaux
    int N;
    int choix;
    printf("Veuillez saisir la taille de votre vecteur: \n");
    scanf("%d", &N);
    int vecteur[N];
    int vecteur2[N];
    int i;
    printf("Veuillez saisir les valeurs de votre vecteur: \n");
    for(i=0; i<N; i++){
        scanf("%d", &vecteur[i]);
    }
    printf("Veuillez saisir les valeurs de votre vecteur2: \n");
    for(i=0; i<N; i++){
        scanf("%d", &vecteur2[i]);
    }
    printf("Veuillez choisir l'opération à effectuer: \n");
    printf("1. Addition\n");
    printf("2. Soustraction\n");
    printf("3. Transposée du vecteur\n");

    scanf("%d", &choix);
    switch(choix){
        case 1:
            printf("Addition des vecteurs: \n");
            for(i=0; i<N; i++){
                printf("%d ", vecteur[i]+vecteur2[i]);
            }
            break;
        case 2:
            printf("Soustraction des vecteurs: \n");
            for(i=0; i<N; i++){
                printf("%d ", vecteur[i]-vecteur2[i]);
            }
            break;
        case 3:
            printf("Transposée du vecteur: \n");
            for(i=0; i<N; i++){
                printf("%d ", vecteur[i]);
            }
            break;
        default:
            printf("Choix invalide");
            break;
    }
}

int main(){
    int choix;
    printf("Choisissez un exercice: ");
    scanf("%d", &choix);

    switch(choix){
        case 46:
            exo_46();
            break;
        default:
            printf("Choix invalide");
            break;
    }
}