#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int N;
typedef enum {prete, disponible} etatLivre;
typedef struct {
    char auteur[20];
    char titre[100];
    char cote[9];
    int annee;
    char editeur[20];
    etatLivre EnPret;
    int date;
} BibLivres;

void saisir(){
    BibLivres livre;
    printf("Saisir l'auteur : ");
    scanf("%s", livre.auteur);
    fflush(stdin);
    printf("Saisir le titre : ");
    fgets(livre.titre, 100, stdin);
    printf("Saisir la cote : ");
    scanf("%s", livre.cote);
    printf("Saisir l'annee : ");
    scanf("%d", &livre.annee);
    printf("Saisir l'editeur : ");
    scanf("%s", livre.editeur); 

    printf("Voici un récapilulatif de votre saisie : \n");
    printf("Auteur : %s\n", livre.auteur);
    printf("Titre : %s\n", livre.titre);
    printf("Cote : %s\n", livre.cote);
    printf("Annee : %d\n", livre.annee);
    printf("Editeur : %s\n", livre.editeur);

}
void save(){
    
    printf("Combien de livres voulez-vous enregistrer ? ");
    scanf("%d", &N);
    BibLivres *livre = malloc(N*sizeof(BibLivres));
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20];
    scanf("%s", nomFichier);
    FILE *fichier = fopen(nomFichier, "w");
    fprintf(fichier, "Il y a %d livres enregistrés : \n", N);
    for(int i=0; i<N; i++){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
        printf("Informations du livre %d : \n", i+1);
        printf("Saisir l'auteur : ");
        scanf("%s", livre[i].auteur);
        fflush(stdin);
        printf("Saisir le titre : ");
        fgets(livre[i].titre, 100, stdin);
        printf("Saisir la cote : ");
        scanf("%s", livre[i].cote);
        printf("Saisir l'annee : ");
        scanf("%d", &livre[i].annee);
        printf("Saisir l'editeur : ");
        scanf("%s", livre[i].editeur);
        printf("Saissir l'etat du livre (0 pour prete, 1 pour disponible) : ");
        scanf("%d", &livre[i].EnPret); 
        fprintf(fichier, "%s\n%s%s\n%d\n%s\n%d\n",livre[i].auteur, livre[i].titre, livre[i].cote, livre[i].annee, livre[i].editeur, livre[i].EnPret);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
    fclose(fichier);
}
void lire(){
    printf("lire\n");
    char c;
    //On veut lire le fichier avec un pointeur de type BibLivres et l'allocation dynamique
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20];
    scanf("%s", nomFichier);
    FILE *fichier = fopen(nomFichier, "r");
    BibLivres *livre = malloc(sizeof(BibLivres));
    c = getc(fichier);
    while(c != EOF){
        printf("%c", c);
        c = getc(fichier);
    }
    fclose(fichier);

}
void search(){
    //On va rechercher un livre par son titre
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20],c;
    char ligne[200];
    int z=0;
    scanf("%s", nomFichier);
    fflush(stdin);
    FILE *fichier = fopen(nomFichier, "r");
    BibLivres *livre = malloc(3*sizeof(BibLivres));
    printf("Test\n");
    int i= 0;
    printf("Test\n");
    fscanf(fichier, "%[^\n]\n", ligne);
    while( feof(fichier) == 0 && livre[i].auteur != NULL){
        //On utilise fgets pour obtenir le titre du livre
        fscanf(fichier, "%s", livre[i].auteur);
        printf("Auteur : %s\n", livre[i].auteur);
        
        fgets(ligne, 100, livre[i].titre);
        printf("Titre : %s\n", ligne);

        fscanf(fichier, "%s", livre[i].cote);
        printf("Cote : %s\n", livre[i].cote);
        fscanf(fichier, "%d", &livre[i].annee);
        printf("Annee : %d\n", livre[i].annee);
        fscanf(fichier, "%s", livre[i].editeur);
        printf("Editeur : %s\n", livre[i].editeur);
        fscanf(fichier, "%d", &livre[i].EnPret);
        printf("Etat : %d\n", livre[i].EnPret);
        i++;

    }
    printf("%s\n", livre[11].titre);
    printf("Test2\n");
    printf("Veuillez saisir le titre du livre que vous recherchez : \n");
    char titre[100];
    scanf("%s", titre);
    fflush(stdin);
    for(int j=0; j<i; j++){
        if(strcmp(livre[j].titre, titre) == 0){
            printf("Livre n°%d \n %s\n %s\n %s\n %d\n %s\n",j+1, livre[j].auteur, livre[j].titre, livre[j].cote, livre[j].annee, livre[j].editeur);
            z++;
        }
    }
    if (z==0){
        printf("Aucun livre ne correspond à votre recherche.\n");
    }
    
    fclose(fichier);
}
void modif(){
    //On va modifier les informations d'un livre
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20],c;
    char ligne[200];
    int z=0;
    int i=0;
    scanf("%s", nomFichier);
    fflush(stdin);
    FILE *fichier = fopen(nomFichier, "r");
    BibLivres *livre = (BibLivres*) malloc(3*sizeof(BibLivres));
    fscanf(fichier, "%[^\n]\n", ligne);
    while( feof(fichier) == 0 && livre[i].auteur != NULL){
        fscanf(fichier, "%s", livre[i].auteur);
        printf("Auteur : %s\n", livre[i].auteur);
        fscanf(fichier,"%[^\n]c\n", livre[i].titre);
        printf("Titre : %s\n", livre[i].titre);
        fscanf(fichier, "%s", livre[i].cote);
        printf("Cote : %s\n", livre[i].cote);
        fscanf(fichier, "%d", &livre[i].annee);
        printf("Annee : %d\n", livre[i].annee);
        fscanf(fichier, "%s", livre[i].editeur);
        printf("Editeur : %s\n", livre[i].editeur);
        fscanf(fichier, "%d", &livre[i].EnPret);
        printf("Etat : %d\n", livre[i].EnPret);
        i++;

    }
    fclose(fichier);
    printf("Veuillez saisir le titre du livre que vous souhaitez modifier : \n");
    char titre[100];
    scanf("%s", titre);
    fflush(stdin);
    int h=0;
    for(int j=0; j<i; j++){
        if(strcmp(livre[j].titre, titre) == 0){
            printf("Que voulez-vous modifier ?\n");
            printf("1. Statut\n");
            scanf("%d", &h);
            fflush(stdin);
            if (h==1){
                if (livre[j].EnPret==0){
                    livre[j].EnPret=1;
                }
                else{
                    livre[j].EnPret=0;
                }
                
            }
            
        fopen(nomFichier, "w");
        fprintf(fichier, "Il y a %d livres enregistrés : \n", N);
        for (i=0; i<N; i++){
            fprintf(fichier, "%s\n", livre[i].auteur);
            fprintf(fichier, "%s\n", livre[i].titre);
            fprintf(fichier, "%s\n", livre[i].cote);
            fprintf(fichier, "%d\n", livre[i].annee);
            fprintf(fichier, "%s\n", livre[i].editeur);
            fprintf(fichier, "%d\n", livre[i].EnPret);
        }
        fclose(fichier);
        }
    }
}
//On va créer des fichiers
void exo_50(){
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
void exo_51(){
    system("cls");
    search();
}
int main(){
    int choix;
    printf("Veuillez choisir une option :\n");
    printf("1. Exercice 50\n");
    printf("2. Exercice 51\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            exo_50();
            break;
        case 50:
            exo_50();
            break;
        case 2:
            exo_51();
            break;
        default:
            printf("Erreur");
            break;
    }    
}