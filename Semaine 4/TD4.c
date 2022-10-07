#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nom[20];
    char prenom[20];
    int median;
    int moyenne;
    int final;
} etudiant;

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
    printf("3. Transposée du vecteur\n");

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
        printf("Transposée du vecteur: \n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", vecteur[i]);
        }
        break;
    default:
        printf("Choix invalide");
        break;
    }
}
void exo_47()
{
    system("cls");
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

void exo_texte(){
    FILE *ptr;
    char name[20];
    char str[100];
    printf("Veuillez saisir le nom du fichier: \n");
    scanf("%s", name);
    ptr = fopen(name, "r");
    if (ptr == NULL)
    {
        printf("Impossible d'ouvrir le fichier");
        return;
    }
    int i = 0;
    int z = 0;
    do
    {
        fscanf(ptr, "%c", &str[i]);
        printf("%c", str[i]);
        if (str[i] == '\n')
        {
            z++;
        }
        i++;

    } while (z == 0);
    fclose(ptr);

    
    return 0;
}
int main()
{
    int choix;
    printf("-------------------------------------\n");
    printf("| 1. Exercice 46                    |\n");
    printf("| 2. Exercice 47                    |\n");
    printf("| 3. Texte                          |\n");
    printf("|Choississez l'exercice à exécuter: |\n");
    printf("-------------------------------------\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        exo_46();
        break;
    case 2:
        exo_47();
        break;
    case 46:
        exo_46();
        break;
    case 47:
        exo_47();
        break;
    case 48:
        exo_texte();
        break;
    default:
        printf("Choix invalide");
        break;
    }
}