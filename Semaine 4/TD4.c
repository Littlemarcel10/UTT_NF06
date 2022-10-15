#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nom[20];
    char prenom[20];
    int median;
    float moyenne;
    int final;
} etudiant;

void saisie_matrice(){
    
}

void exo_46()
{
    // Opération sur les tableaux
    int N;
    int choix;
    printf("Veuillez saisir la taille de votre vecteur: \n");
    scanf("%d", &N);
    int vecteur[N];
    int vecteur2[N];
    int i;
    printf("Veuillez saisir les valeurs de votre vecteur: \n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &vecteur[i]);
    }
    printf("Veuillez saisir les valeurs de votre vecteur2: \n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &vecteur2[i]);
    }
    printf("Veuillez choisir l'opération à effectuer: \n");
    printf("1. Addition\n");
    printf("2. Soustraction\n");
    printf("3. Produit scalaire\n");

    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("Addition des vecteurs: \n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", vecteur[i] + vecteur2[i]);
        }
        break;
    case 2:
        printf("Soustraction des vecteurs: \n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", vecteur[i] - vecteur2[i]);
        }
        break;
    case 3:
        //on effectue le produit scalaire
        printf("Produit Scalaire des vecteurs \n");
        int produit_scalaire = 0;
        for (i = 0; i < N; i++)
        {
            produit_scalaire += vecteur[i] * vecteur2[i];
        }
        printf("%d", produit_scalaire);

        break;
    default:
        printf("Choix invalide");
        break;
    }
}
void exo_47()
{
    int N;
    printf("Veuillez saisir le nombre d'étudiants: \n");
    scanf("%d", &N);
    printf("Veuillez saisir les informations des étudiants: \n");
    etudiant tab[N];
    int i, j;
    int note_final;
    int note_median;
    int taille_nom, taille_prenom;
    float note_moyenne;
    for (i = 0; i < N; i++)
    {
        printf("-------------------------\n");
        printf("Etudiant %d:\n", i + 1);
        printf("Nom: ");
        scanf("%s", tab[i].nom);
        fflush(stdin);
        printf("Prenom: ");
        scanf("%s", tab[i].prenom);
        fflush(stdin);
        printf("Médiane: ");
        scanf("%d", &tab[i].median);
        fflush(stdin);
        printf("Note finale: ");
        scanf("%d", &tab[i].final);
        fflush(stdin);
        printf("-------------------------\n");
        taille_nom = strlen(tab[i].nom);
        taille_prenom = strlen(tab[i].prenom);
        for (j = 0; j < taille_nom; j++)
        {
            // on transforme les lettres majuscules en minuscules
            if (tab[i].nom[j] >= 65 && tab[i].nom[j] <= 90)
            {
                tab[i].nom[j] += 32;
            }
        }
        for (j = 0; j < taille_prenom; j++)
        {
            if (tab[i].prenom[j] >= 65 && tab[i].prenom[j] <= 90)
            {
                tab[i].prenom[j] += 32;
            }
        }
    }
    printf("Voulez-voir les informations des étudiants dans l'ordre croissant des nom et prénom? (1: oui, 0: non) \n");
    int choix;
    scanf("%d", &choix);
    if (choix == 1)
    {
        // on va trier le tableau
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (strcmp(tab[i].nom, tab[j].nom) < 0)
                {
                    etudiant temp = tab[i];
                    tab[i] = tab[j];
                    tab[j] = temp;
                }
                //si les noms sont identiques, on compare les prénoms
                else if (strcmp(tab[i].nom, tab[j].nom) == 0)
                {
                    if (strcmp(tab[i].prenom, tab[j].prenom) < 0)
                    {
                        etudiant temp = tab[i];
                        tab[i] = tab[j];
                        tab[j] = temp;
                    }
                }
            }
        }
        // on affiche le tableau
        for (i = 0; i < N; i++)
        {
            note_final = tab[i].final;
            note_median = tab[i].median;
            note_moyenne = (note_median * 0.4 + 0.6 * note_final);
            printf(" ~~~~~~~~~~~~~~\n Nom: %s \n Prenom: %s\n Médian: %d\n Note final: %d\n Moyenne: %.2f\n ~~~~~~~~~~~~~~\n", tab[i].nom, tab[i].prenom, tab[i].median, tab[i].final, note_moyenne);
        }
        return;
    }
}

void exo_47b(){
    etudiant *tab_etudiant;
    int N;
    printf("Veuillez saisir le nombre d'étudiants: \n");
    scanf("%d", &N);
    tab_etudiant = (etudiant*)calloc(N,sizeof(etudiant));
    printf("Veuillez saisir les informations des étudiants: \n");
    int i, j;
    int note_final;
    int note_median;
    int taille_nom, taille_prenom;
    float note_moyenne;
    for (i=0; i<N; i++){
        printf("~~~~~~~~~~\n");
        printf("Nom de l'étudiant %d :", i+1);
        scanf("%s", tab_etudiant[i].nom);
        fflush(stdin);
        printf("Prénom de l'étudiant %d :", i+1);
        scanf("%s", tab_etudiant[i].prenom);
        fflush(stdin);
        printf("Médian:");
        scanf("%d", &tab_etudiant[i].median);
        printf("Final:");
        scanf("%d", &tab_etudiant[i].final);
        tab_etudiant[i].moyenne = 0.4*tab_etudiant[i].median+ 0.6*tab_etudiant[i].final;

        taille_nom = strlen(tab_etudiant[i].nom);
        taille_prenom = strlen(tab_etudiant[i].prenom);
        for (j = 0; j < taille_nom; j++)
        {
            // on transforme les lettres majuscules en minuscules
            if (tab_etudiant[i].nom[j] >= 65 && tab_etudiant[i].nom[j] <= 90)
            {
                tab_etudiant[i].nom[j] += 32;
            }
        }
        for (j = 0; j < taille_prenom; j++)
        {
            if (tab_etudiant[i].prenom[j] >= 65 && tab_etudiant[i].prenom[j] <= 90)
            {
                tab_etudiant[i].prenom[j] += 32;
            }
        }
    }
     for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (strcmp(tab_etudiant[i].nom, tab_etudiant[j].nom) < 0)
                {
                    etudiant temp = tab_etudiant[i];
                    tab_etudiant[i] = tab_etudiant[j];
                    tab_etudiant[j] = temp;
                }
                //si les noms sont identiques, on compare les prénoms
                else if (strcmp(tab_etudiant[i].nom, tab_etudiant[j].nom) == 0)
                {
                    if (strcmp(tab_etudiant[i].prenom, tab_etudiant[j].prenom) < 0)
                    {
                        etudiant temp = tab_etudiant[i];
                        tab_etudiant[i] = tab_etudiant[j];
                        tab_etudiant[j] = temp;
                    }
                }
            }
        }
        // on affiche le tableau
        system("cls");
        printf("Tableau trié des étudiants:\n");
        for (i = 0; i < N; i++)
        {
            printf("~~~~~~~~~~~~~~\nNom: %s \nPrenom: %s\nMédian: %d\nNote final: %d\nMoyenne: %.2f\n", tab_etudiant[i].nom, tab_etudiant[i].prenom, tab_etudiant[i].median, tab_etudiant[i].final, tab_etudiant[i].moyenne);
            if (tab_etudiant[i].moyenne < 10){
                printf("PTDR il a F le con\n~~~~~~~~~~~~~~\n");
                
            }
            else{
                printf("~~~~~~~~~~~~~~\n");
            }
        }
    //on procède au tri des étudiants

    free(tab_etudiant);
}

void exo_48(){
    //Faire des calculs de matrices avec des tableaux dynamiques
    int **matrice;
    int **matrice2;
    int **matrice3;
    int i, j;
    int ligne, colonne, taille;
    int choix;
    printf("Veuillez saisir la taille de la matrice\n");
    scanf("%d", &taille);
    colonne = taille;
    ligne = taille;
    matrice = (int**)calloc(taille, sizeof(int*));
    for (i = 0; i < taille; i++){
        matrice[i] = (int*)calloc(taille, sizeof(int));
    }
    matrice2 = (int**)calloc(taille,sizeof(int*));
    for (i = 0; i < taille; i++){
        matrice2[i] = (int*)calloc(taille, sizeof(int));
    }
    matrice3 = (int**)calloc(taille,sizeof(int*));
    for (i = 0; i < taille; i++){
        matrice3[i] = (int*)calloc(taille, sizeof(int));
    }
    printf("Veuillez saisir les valeurs de la matrice: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("Valeur de la case [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrice[i][j]);
        }
    }
    
    printf("La matrice est: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("Action à réaliser : \n1.Addition\n2.Soustraction\n3.Transposée\n4.Multiplication\n");
    scanf("%d", &choix);
    if (choix == 1){
        
    printf("Veuillez saisir les valeurs de la matrice 2: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("Valeur de la case [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrice2[i][j]);
            matrice3[i][j] = matrice[i][j] + matrice2[i][j];
        }
    }
    printf("La matrice est: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("%d ", matrice3[i][j]);
        }
        printf("\n");
    }
    }
    else if(choix == 2){
        printf("Veuillez saisir les valeurs de la matrice 2: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("Valeur de la case [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrice2[i][j]);
            matrice3[i][j] = matrice[i][j] - matrice2[i][j];
        }
    }
    printf("La matrice est: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("%d ", matrice3[i][j]);
        }
        printf("\n");
    }
    }
    else if(choix ==3){
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            matrice3[i][j] = matrice[j][i];
            printf("%d ", matrice3[i][j]);
        }
        printf("\n");
    }
    }
    else if(choix==4){
        printf("Veuillez saisir les valeurs de la matrice 2: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("Valeur de la case [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrice2[i][j]);
        }
    }
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            for (int k = 0; k < taille; k++){
                matrice3[i][j] += matrice[i][k] * matrice2[k][j];
            }
        }
    }
    printf("La matrice est: \n");
    for (i = 0; i < ligne; i++){
        for (j = 0; j < colonne; j++){
            printf("%d ", matrice3[i][j]);
        }
        printf("\n");
    }
    }
    
}

int main()
{   
    
    system("cls");
    int choix, stop = 1;
    system("cls");
    printf("-------------------------------------\n");
    printf("| 1. Exercice 46                    |\n");
    printf("| 2. Exercice 47                    |\n");
    printf("| 3. Exercice 48                    |\n");
    printf("|Choississez l'exercice à exécuter: |\n");
    printf("-------------------------------------\n");
    scanf("%d", &choix);
        switch (choix)
    {
    case 1:
        exo_46();
        break;
    case 2:
        exo_47b();
        break;
    case 3:
        exo_48();
        break;
    case 46:
        exo_46();
        break;
    case 47:
        exo_47();
        break;
    case 48:
        exo_48();
        break;
    default:
        printf("Choix invalide");
        break;
    }
    
    
    
}