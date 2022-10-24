#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int N;
typedef enum
{
    prete,
    disponible
} etatLivre;
typedef struct
{
    int jour;
    int mois;
    int annee;
} date;
typedef struct
{
    char auteur[20];
    char titre[100];
    char cote[9];
    int annee;
    char editeur[20];
    etatLivre EnPret;
    date datePret;
} BibLivres;

void saisir()
{ // Void de test
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
void save()
{ // void de première saisie d'informations

    printf("Combien de livres voulez-vous enregistrer ? ");
    scanf("%d", &N);
    BibLivres *livre = malloc(N * sizeof(BibLivres));
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20];
    scanf("%s", nomFichier);
    FILE *fichier = fopen(nomFichier, "w");
    fprintf(fichier, "Il y a %d livres enregistrés : \n", N);
    for (int i = 0; i < N; i++)
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Informations du livre %d : \n", i + 1);
        printf("Saisir l'auteur : ");
        scanf("%s", livre[i].auteur);
        fflush(stdin);
        printf("Saisir le titre : ");
        scanf("%s[^\n]", livre[i].titre);
        printf("Saisir la cote : ");
        scanf("%s", livre[i].cote);
        printf("Saisir l'annee : ");
        scanf("%d", &livre[i].annee);
        printf("Saisir l'editeur : ");
        scanf("%s", livre[i].editeur);
        printf("Saissir l'etat du livre (0 pour prete, 1 pour disponible) : ");
        scanf("%d", &livre[i].EnPret);
        printf("Saisir la date de pret (jour, mois, annee) : ");
        scanf("%d %d %d", &livre[i].datePret.jour, &livre[i].datePret.mois, &livre[i].datePret.annee);
        if (i > 0)
        {
            fprintf(fichier, "\n");
        }
        fprintf(fichier, "%s | %s | %s | %d | %s | %d | %d | %d | %d", livre[i].auteur, livre[i].titre, livre[i].cote, livre[i].annee, livre[i].editeur, livre[i].datePret.jour, livre[i].datePret.mois, livre[i].datePret.annee, livre[i].EnPret);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    fclose(fichier);
}
void lire()
{
    printf("lire\n");
    char c;
    // On veut lire le fichier avec un pointeur de type BibLivres et l'allocation dynamique
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20];
    scanf("%s", nomFichier);
    FILE *fichier = fopen(nomFichier, "r");
    BibLivres *livre = malloc(sizeof(BibLivres));
    c = getc(fichier);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fichier);
    }
    fclose(fichier);
}
void search()
{
    // On va rechercher un livre par son titre
    N = 0;
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20], c;
    char ligne[200];
    int z = 0;
    scanf("%s", nomFichier);
    fflush(stdin);
    FILE *fichier = fopen(nomFichier, "r");
    BibLivres *livre = malloc(3 * sizeof(BibLivres));
    int i = 0;
    fscanf(fichier, "%[^\n]", ligne);
    while (feof(fichier) == 0 && livre[i].auteur != NULL)
    {
        // On utilise fgets pour obtenir le titre du livre
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Informations du livre %d : \n", i + 1);
        fscanf(fichier, "%s", livre[i].auteur);
        printf("Auteur : %s\n", livre[i].auteur);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%s", livre[i].titre);
        printf("Titre : %s\n", livre[i].titre);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%s", livre[i].cote);
        printf("Cote : %s\n", livre[i].cote);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].annee);
        printf("Annee : %d\n", livre[i].annee);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%s", livre[i].editeur);
        printf("Editeur : %s\n", livre[i].editeur);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].datePret.jour);
        printf("Date de pret (jour) : %d\n", livre[i].datePret.jour);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].datePret.mois);
        printf("Date de pret (mois) : %d\n", livre[i].datePret.mois);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].datePret.annee);
        printf("Date de pret (annee) : %d\n", livre[i].datePret.annee);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].EnPret);
        printf("Etat : %d\n", livre[i].EnPret); // Ce n'est pas la peine pour le dernier champ
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        i++;
        N++;
    }
    printf("Veuillez saisir le titre du livre que vous recherchez : \n");
    char titre[100];
    scanf("%s", titre);
    fflush(stdin);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(livre[j].titre, titre) == 0)
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Informations du livre %d : \n", j + 1);
            printf("Auteur : %s\n", livre[j].auteur);
            printf("Titre : %s\n", livre[j].titre);
            printf("Cote : %s\n", livre[j].cote);
            printf("Annee : %d\n", livre[j].annee);
            printf("Editeur : %s\n", livre[j].editeur);
            printf("Date de pret (jour) : %d\n", livre[j].datePret.jour);
            printf("Date de pret (mois) : %d\n", livre[j].datePret.mois);
            printf("Date de pret (annee) : %d\n", livre[j].datePret.annee);
            printf("Etat : %d\n", livre[j].EnPret);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            z++;
        }
    }
    if (z == 0)
    {
        printf("Aucun livre ne correspond à votre recherche.\n");
    }

    fclose(fichier);
}
void modif()
{
    N = 0;
    // On va modifier les informations d'un livre
    printf("Veuillez écrire le nom du fichier.txt : ");
    char nomFichier[20], c;
    char ligne[200];
    int z = 0;
    int i = 0;
    scanf("%s", nomFichier);
    fflush(stdin);
    FILE *fichier = fopen(nomFichier, "r");
    BibLivres *livre = (BibLivres *)malloc(3 * sizeof(BibLivres));
    fscanf(fichier, "%[^\n]", ligne);
    while (feof(fichier) == 0 && livre[i].auteur != NULL)
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Informations du livre %d : \n", i + 1);
        fscanf(fichier, "%s", livre[i].auteur);
        printf("Auteur : %s\n", livre[i].auteur);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%s", livre[i].titre);
        printf("Titre : %s\n", livre[i].titre);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%s", livre[i].cote);
        printf("Cote : %s\n", livre[i].cote);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].annee);
        printf("Annee : %d\n", livre[i].annee);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%s", livre[i].editeur);
        printf("Editeur : %s\n", livre[i].editeur);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].datePret.jour);
        printf("Date de pret (jour) : %d\n", livre[i].datePret.jour);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].datePret.mois);
        printf("Date de pret (mois) : %d\n", livre[i].datePret.mois);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].datePret.annee);
        printf("Date de pret (annee) : %d\n", livre[i].datePret.annee);
        fscanf(fichier, "%s", ligne); // On utilise cette ligne pour lire les séparateurs dans notre fichier texte
        fscanf(fichier, "%d", &livre[i].EnPret);
        printf("Etat : %d\n", livre[i].EnPret); // Ce n'est pas la peine pour le dernier champ
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        i++;
        N++;
    }

    printf("Veuillez saisir le titre du livre que vous souhaitez modifier : \n");
    char titre[100];
    scanf("%s", titre);
    fflush(stdin);
    int h = 0;
    int modif = 0;
    for (int j = 0; j < i; j++)
    {
        if (strcmp(livre[j].titre, titre) == 0)
        {
            modif = 1;
            printf("Que voulez-vous modifier ?\n");
            printf("1. Statut\n");
            scanf("%d", &h);
            fflush(stdin);
            if (h == 1)
            {
                if (livre[j].EnPret == 0)
                {
                    livre[j].EnPret = 1;
                }
                else if (livre[j].EnPret == 1)
                {
                    livre[j].EnPret = 0;
                }
            }
            printf("Veuillez indiquer la nouvelle date de pret : \n");
            printf("Jour : ");
            scanf("%d", &livre[j].datePret.jour);
            fflush(stdin);
            printf("Mois : ");
            scanf("%d", &livre[j].datePret.mois);
            fflush(stdin);
            printf("Annee : ");
            scanf("%d", &livre[j].datePret.annee);
            fflush(stdin);
            fclose(fichier);
            fopen(nomFichier, "w");
            fprintf(fichier, "Il y a %d livres enregistrés : \n", N);
            for (i = 0; i < N; i++)
            {
                if (i > 0)
                {
                    fprintf(fichier, "\n");
                }
                fprintf(fichier, "%s | %s | %s | %d | %s | %d | %d | %d | %d", livre[i].auteur, livre[i].titre, livre[i].cote, livre[i].annee, livre[i].editeur, livre[i].datePret.jour, livre[i].datePret.mois, livre[i].datePret.annee, livre[i].EnPret);
            }
            fclose(fichier);
        }
        
    }
    if (modif == 0)
    {
        printf("Le livre que vous avez saisi n'existe pas !\n");
    }
}
// On va créer des fichiers
void exo_50() // exo des vecteurs
{
    FILE *ptr;
    char nom[20];
    int M;
    int n, K;
    printf("Entrez le nom du fichier : ");
    scanf("%s", nom);
    printf("Veuillez indiquer le nombre de vecteurs : ");
    scanf("%d", &n);
    printf("Veuillez indiquer la dimension des vecteurs : ");
    scanf("%d", &M);
    ptr = fopen(nom, "w");
    if (ptr == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("Veuillez entrer la valeur du vecteur %d à la position %d :\n", i + 1, j + 1);
            scanf("%d", &K);
            fprintf(ptr, "%d ", K);
        }
        fprintf(ptr, "\n");
    }
    fclose(ptr);
    ptr = fopen(nom, "r");
    if (ptr == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    int vecteur[M];
    int somme[M];
    int t;
    for (int i = 0; i < M; i++)
    {
        somme[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fscanf(ptr, "%d", &vecteur[j]);
            somme[j] += vecteur[j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        printf("%d ", somme[i]);
    }
    fclose(ptr);
    ptr = fopen(nom, "a");

    for (int i = 0; i < M; i++)
    {
        fprintf(ptr, "%d ", somme[i]);
    }
    fclose(ptr);
}
void exo_51()
{
    int restart = 1;
    system("cls");
    printf("Exercice 51\n");
    int choix;
    fflush(stdin);
    while (restart == 1)
    {
        
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Veuillez choisir l'action que vous souhaitez effectuer : \n");
    printf("1. Ajouter un(ou des) livre\n");
    printf("2. chercher un livre\n");
    printf("3. Modifier un livre\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    scanf("%d", &choix);
    fflush(stdin);
        switch (choix)
        {
        case 1:
            save();
            break;
        case 2:
            search();
            break;
        case 3:
            modif();
            break;
        default:
            printf("Veuillez choisir une action valide.\n");
            break;
        }
        printf("Voulez-vous effectuer une autre action ?\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        scanf("%d", &restart);
    }
}
int main()
{
    int choix;
    printf("Veuillez choisir une option :\n");
    printf("1. Exercice 50\n");
    printf("2. Exercice 51\n");
    scanf("%d", &choix);
    switch (choix)
    {
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