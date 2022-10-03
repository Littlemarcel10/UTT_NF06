// On intègre les bibliothèques à notre code
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

void exo_16(){
    int valeur;
            int racine;
            int nombre;
            printf("Exercice 16:\n");
            printf("voici la liste des nombres premiers entre 1 et 50: \n");
            for (valeur = 1; valeur <= 50; valeur++)
            {
                nombre = 0;
                for (racine = 1; racine <= valeur; racine++)
                {
                    if (valeur % racine == 0)
                    {
                        nombre++;
                    }
                }
                if (nombre == 2)
                {
                    printf("%d\n", valeur);
                }
            }

            printf("nous allons tester si votre entier est premier ou non\n");
            printf("Veuillez entrer un entier: ");
            scanf("%d", &valeur);
            racine = sqrt(valeur);
            for (int i = 2; i <= racine; i++)
            {
                if (valeur % i == 0)
                {
                    printf("Votre entier n'est pas premier\n");
                    break;;
                }
            }
            printf("Votre entier est premier");
}

void exo_17(){
    int tableau[10];
            int max = 0;
            printf("Cette fonction va permettre de découvrir la valeur max d'un tableau d'entiers\n");
            for (int i = 0; i < 10; i++)
            {
                printf("Veuillez entrer un entier: ");
                scanf("%d", &tableau[i]);
                if (tableau[i] > max)
                {
                    max = tableau[i];
                }
            }
            printf("La valeur max est: %d", max);
}
void exo_18(){
    int n;
            printf("Exercice 18:\n");
            printf("Veuillez entrer un entier: ");
            scanf("%d", &n);
            //on va regarder chaque caractère de notre entier et regarder si il y a la présence d'un 0
            while (n != 0)
            {
                if (n % 10 == 0)
                {
                    printf("Il y a un 0 dans votre entier");
                    break;;
                }
                n = n / 10;
            }
            printf("Il n'y a pas de 0 dans votre entier");
}
void exo_19(){
     printf("Exercice 19:\n");
            printf("Résolution de l'équation ax² + bx + c = d\n");
            int a, b, c, d;
            float e;
            printf("Veuillez entrer la valeur de a: ");
            scanf("%d", &a);
            printf("Veuillez entrer la valeur de b: ");
            scanf("%d", &b);
            printf("Veuillez entrer la valeur de c: ");
            scanf("%d", &c);
            printf("Veuillez entrer la valeur de d: ");
            scanf("%d", &d);
            int delta = b * b - 4 * a * c;
            e = sqrt(delta);
            printf("%f\n", e);
            if (delta < 0)
            {
                printf("L'équation n'a pas de solution");
            }
            else if (delta == 0)
            {
                printf("L'équation a une solution double: %d", -b / (2 * a));
            }
            else
            {
                printf("L'équation a deux solutions: %d et %d", (-b + e) / (2 * a), (-b - e) / (2 * a));
            }
}
void exo_20(){
    int terme_1;
            int terme_2;
            int rang;
            int boucle;
            int valeurtab[100];
            printf("Exercice 20:\n");
            printf("Veuillez entrer le rang du nème terme de fibonacci que vous voulez: ");
            scanf("%d", &rang);
            terme_1 = 0;
            terme_2 = 1;
            for (boucle = 0; boucle < rang; boucle++)
            {
                valeurtab[boucle] = terme_1;
                printf("%d\n", terme_1);
                int temp = terme_1;
                terme_1 = terme_2;
                terme_2 = temp + terme_2;
            }
            printf("Le %dème terme de fibonacci est: %d", rang, valeurtab[rang - 1]);

}
void exo_21(){
     char palindrome[100];
            printf("Veuillez écrire un mot: (100 caractères max)\n");
            scanf("%s", palindrome);
            int taille = strlen(palindrome);
            int i = 0;
            int j = taille - 1;
            while (i < j)
            {
                if (palindrome[i] != palindrome[j])
                {
                    printf("Ce mot n'est pas un palindrome");
                    break;;
                }
                i++;
                j--;
            }
            printf("Ce mot est un palindrome");
}
void exo_22(){

}
void exo_23(){
    printf("Trop complique a mes yeux pour l'instant");
}
void exo_24(){
    float N;
    float variance;
    float moyenne;
    float somme = 0;
    float somme_carre = 0;
    // On va déterminer la variance de N réels SANS tableau
    printf("Veuillez entrer la valeur de N: ");
    scanf("%f", &N);
    for (int i = 0; i < N; i++)
    {
        float valeur;
        printf("Veuillez entrer la valeur %d: ", i + 1);
        scanf("%f", &valeur);
        somme = somme + valeur;
        somme_carre = somme_carre + valeur * valeur;
    }
    moyenne = somme / N;
    variance = somme_carre / N - moyenne * moyenne;
    printf("La moyenne est: %.2f \n", moyenne);
    printf("La variance est: %.4f", variance);

}
void exo_25(){

}
void exo_26(){
    //On va comparer deux chaînes de caractères
    char chaine_1[100];
    char chaine_2[100];
    printf("Veuillez entrer la première chaîne de caractères: ");
    scanf("%s", chaine_1);
    printf("Veuillez entrer la deuxième chaîne de caractères: ");
    scanf("%s", chaine_2);
    int taille_1 = strlen(chaine_1);
    int taille_2 = strlen(chaine_2);
    int i = 0;
    int j = 0;
    if (taille_1 != taille_2){
        printf("Les deux chaînes ne sont pas identiques");
        return;
    }
    while (i < taille_1 && j < taille_2)
    {
        if (chaine_1[i] != chaine_2[j])
        {
            printf("Les deux chaînes ne sont pas identiques");
            return;
        }
        i++;
        j++;
    }
    printf("Les deux chaînes sont identiques");

}
void exo_27(){
    char chaine[300];
    char sous_chaine[300];
    int p1;
    int p2;
    int nombre;
    int i = 0;
    printf("Veuillez entrer une chaîne de caractères: ");
    scanf("%s", chaine);
    printf("Veuillez entrer une position de départ: ");
    scanf("%d", &p1);
    printf("Veuillez entrer une position de fin: ");
    scanf("%d", &p2);
    p1 = p1 -1;
    while (p2 <= p1)
    {
        printf("Veuillez entrer une position de fin supérieure à la position de départ: ");
        scanf("%d", &p2);

    }
    nombre= p2 - p1;
    while (i < nombre)
    {
        sous_chaine[i] = chaine[p1 + i];
        i++;
    }
    sous_chaine[i] = '\0';
    printf("La sous-chaîne est: %s", sous_chaine);

}
void exo_28(){
    //On va voir le nombre d'occurences d'un chaine de caractères dans une autre
    char chaine[800];
    char sous_chaine[300];
    int i;
    int j;
    int compteur = 0;
    printf("Veuillez entrer une chaîne de caractères: ");
    scanf("%s", chaine);
    printf("Veuillez entrer une sous-chaîne de caractères (le mot a trouver dans la première chaine): ");
    scanf("%s", sous_chaine);
    int taille_chaine = strlen(chaine);
    int taille_sous_chaine = strlen(sous_chaine);
    for (i = 0; i < taille_chaine; i++)
    {
        for (j = 0; j < taille_sous_chaine; j++)
        {
            if (chaine[i + j] != sous_chaine[j])
            {
                break;
            }
        }
        if (j == taille_sous_chaine)
        {
            compteur++;
        }
    }
    if (compteur != 0)
    {
        printf("Le mot a été trouvé %d fois", compteur);
    }
    else
    {
        printf("Le mot n'a pas été trouvé");
    }
}
void exo_29(){
    system("cls");
    int entier;
    int chaines[100];
    float racine;
    float carre;
    int choix_2;
    int taille;

    printf("Veuillez choisir une option: \n");
    printf("1. Calculer la racine carree d'un entier et le carre d'un entier\n");
    printf("2. Montrer le nombre PI\n");
    printf("3. Montrer si votre entier est positif ou negatif\n");
    printf("4. Donner la taille de votre chaine de caracteres\n");

    scanf("%d", &choix_2);
    switch (choix_2)
    {
    {
    case 1/* constant-expression */:
        /* code */
        printf("Veuillez entrer un entier: ");
        scanf("%d", &entier);
        racine = sqrt(entier);
        carre = entier * entier;
        printf("La racine carree de %d est: %.2f \n", entier, racine);
        printf("Le carre de %d est: %.2f \n", entier, carre);

        break;
    
    case 2:
        /* code */
        printf("PI vaut: %.2f \n", PI);
        break;
    case 3:
        /* code */
        printf("Veuillez entrer un entier: ");
        scanf("%d", &entier);
        if (entier > 0)
        {
            printf("Votre entier est positif");
        }
        else if (entier < 0)
        {
            printf("Votre entier est negatif");
        }
        else
        {
            printf("Votre entier est nul");
        }
        break;
    case 4:
        /* code */
        printf("Veuillez entrer une chaine de caracteres: ");
        scanf("%s", chaines);
        taille = strlen(chaines);
        printf("La taille de votre chaine est: %d", taille);
        break;
    
    default:
        printf("Veuillez entrer un nombre entre 1 et 4");
        break;
    }


}
}
void exo_30(){
    printf("Nombre d'occurances d'un caractere dans une chaine de caracteres avec une fonction récursive\n");
    char chaine[300];
    char caractere;
    int i = 0;
    int compteur = 0;
    printf("Veuillez entrer une chaine de caracteres: ");
    scanf("%s", chaine);
    printf("Veuillez entrer un caractere: ");
    scanf("%c", caractere);
    int taille_chaine = strlen(chaine);
    for ( i = 0; i < taille_chaine; i++)
    {
        if (chaine[i] == caractere)
        {
            compteur++;
        }
    }
    
    printf("Le caractere %c a ete trouve %d fois", caractere, compteur);
}
// On créer le menu de notre programme

int main()
{
    system("cls");
    int choix;
    printf("\n\n\nVeuillez ecrire le numero de l'exercice (de 16 a 34) que vous voulez executer: ");
    scanf("%d", &choix);

    switch (choix)
    {
        {
        // Si l'utilisateur écrit 16, on exécute l'exercice 16, ainsi de suite.
        // Si le numéro ne correspond à aucun exercice, on affiche un message d'erreur. (qui est la dernière option du switch)
        case 16 /* constant-expression */:
            
            exo_16();
            break;

        case 17 /* constant-expression */:
            exo_17();
            break;

        case 18 /* constant-expression */:
            exo_18();

            break;

        case 19 /* constant-expression */:
            exo_19();
            break;

        case 20 /* constant-expression */:
            exo_20();
            break;
        
        case 21 /* constant-expression */:
           exo_21();

            break;
        
        case 22:
            printf("Pas encore fe");
            break;
        
        case 23:
            exo_23();
            break;
        case 24:
            exo_24();
            break;
        case 26:
            exo_26();
            break;

        case 27:
            exo_27();
            break;
        
        case 28:
            exo_28();
            break;
        
        case 29:
            exo_29();
            break;

        case 30:
            exo_30();
            break;
        default:
            printf("Veuillez entrer un numero d'exercice valide ou l'exercice n'est pas encore disponible");
            break;
        }
    }
}
