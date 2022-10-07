#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char nom[20];
    char prenom[20];
    int median;
    int moyenne;
    int final;
}etudiant;

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
void exo_47(){
    int N;
    printf("Veuillez saisir le nombre d'étudiants: \n");
    scanf("%d", &N);
    printf("Veuillez saisir les informations des étudiants: \n");
    etudiant tab[N];
    int i;
    float note_final;
    float note_median;
    float note_moyenne;
    for(i=0; i<N; i++){
        printf("Nom: ");
        scanf("%s", tab[i].nom);
        printf("Prenom: ");
        scanf("%s", tab[i].prenom);
        printf("Médiane: ");
        scanf("%.2f", &tab[i].median);
        printf("Note finale: ");
        scanf("%.2f", &tab[i].final);
        note_final = tab[i].final;
        note_median = tab[i].median;
        note_moyenne = (note_median*0.4 + 0.6*note_final);
        tab[i].moyenne = note_moyenne;
    }
    printf("Voulez-voir les informations des étudiants dans l'ordre croissant des nom et prénom? (1: oui, 0: non) \n");
    int choix;
    scanf("%d", &choix);
    if(choix == 1){
        //on va trier le tableau 
        int j;
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(strcmp(tab[i].nom, tab[j].nom) < 0){
                    etudiant temp = tab[i];
                    tab[i] = tab[j];
                    tab[j] = temp;
                }
            }
        }
        //on affiche le tableau
        for(i=0; i<N; i++){
            printf("Nom: %s, Prenom: %s, Médiane: %.2f, Moyenne: %.2f, Note finale: %.2f\n", tab[i].nom, tab[i].prenom, tab[i].median, tab[i].moyenne, tab[i].final);
        }
        return;
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
        case 47:
            exo_47();
            break;
        default:
            printf("Choix invalide");
            break;
    }
}