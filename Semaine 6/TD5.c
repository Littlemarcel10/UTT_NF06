#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//On va créer des fichiers
void lecture(){
    FILE *ptr;
    char nom[20];
    int M;
    int n,K;
    printf("Entrez le nom du fichier : ");
    scanf("%s", nom);
    printf("Veuillez indiquer le nombre de vecteurs : ");
    scanf("%d", &n);
    printf("Veuillez indiquer la dimension des vecteurs : ");
    scanf("%d", &M);
    ptr = fopen(nom, "w");
    if(ptr == NULL){
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < M; j++){
            printf("Veuillez entrer la valeur du vecteur %d à la position %d :\n", i+1, j+1);
            scanf("%d", &K);
            fprintf(ptr, "%d ", K);
        }
    fprintf(ptr,"\n");
    }
    fclose(ptr);
    ptr = fopen(nom, "r");
    if(ptr == NULL){
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    int vecteur[M];
    int somme[M];
    int t;
    for(int i = 0; i < M; i++){
        somme[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < M; j++){
            fscanf(ptr, "%d", &vecteur[j]);
            somme[j] += vecteur[j];
        }
    }
    for(int i = 0; i < M; i++){
        printf("%d ", somme[i]);
    }
    fclose(ptr);
    ptr=fopen(nom, "a");

    for(int i = 0; i < M; i++){
        fprintf(ptr, "%d ", somme[i]);
    }
    fclose(ptr);
}
int main(){
    int choix;
    printf("Veuillez choisir une option :\n");
    printf("1. Exercice 50\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            lecture();
            break;
        case 50:
            lecture();
            break;
        default:
            printf("Erreur");
            break;
    }    
}