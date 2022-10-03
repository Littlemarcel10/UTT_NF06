#include <stdio.h>
#include <math.h>
#include <string.h>

//tout ça pour l'exo 38 srx ???
struct complexe_cartesien {
    double x;
    double y;
};
struct complexe_polaire {
    double r;
    double theta;
};
struct Cplx{
    //structure permettant de montrer un nombre complexe sous deux formes
    struct complexe_cartesien cartesien;
    struct complexe_polaire polaire;
};
//Structure pour l'exo 45
enum marque{
    Renault,
    Peugeot,
    Citroen,
    BMW,
    Audi
};
enum type{
    camion, 
    voiture,
    moto
};
union info_sup{
    int nb_portes;
    int longueur;
    int vitesse_max;
};

struct vehicule{
    char vehicule_proprietaire[20];
    char vehicule_immatriculation[20];
    int vehicule_annee;
    enum type vehicule_type;
    enum marque vehicule_marque;
    union info_sup vehicule_info_sup;
};
struct place{
    int nb_heures;
    int date;
    struct vehicule *place_vehicule;
};
struct parking{
    struct place parking_voiture;
    struct place parking_camion;
    struct place parking_moto;
};

void reserver(){
    struct parking parking;
    printf("Reserver\n");
    printf("Quel type de vehicule voulez vous reserver ?\n");
    printf("1 - Moto\n");
    printf("2 - Voiture\n");
    printf("3 - Camion\n");
    int choix;
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("Vous avez choisi une moto\n");

        break;
    case 2:
        printf("Vous avez choisi une voiture\n");
        break;
    case 3:
        printf("Vous avez choisi un camion\n");
        break;
    default:
        printf("Erreur de choix\n");
        break;
    }

}
void update(){

}
void etat(){

}
void retirer(){

}

void exo_38a(){
    //fonction permettant de passer d'une forme cartésienne à polaire et inversement
    struct Cplx c;
    char choix;
    printf("Voulez-vous entrer un nombre complexe sous forme cartésienne ou polaire ? (c/p) ");
    scanf("%c", &choix);
    while (choix != 'c' && choix != 'p'){
        printf("Veuillez entrer un choix valide (c/p) ");
        scanf("%c", &choix);
    }
    if (choix == 'c'){
        printf("Entrez la partie réelle du nombre complexe : ");
        scanf("%lf", &c.cartesien.x);
        printf("Entrez la partie imaginaire du nombre complexe : ");
        scanf("%lf", &c.cartesien.y);
        c.polaire.r = sqrt(pow(c.cartesien.x, 2) + pow(c.cartesien.y, 2));
        c.polaire.theta = atan(c.cartesien.y / c.cartesien.x);
        printf("Le nombre complexe en forme polaire est : %lf * e^(i * %lf)", c.polaire.r, c.polaire.theta);   
    }
    else if(choix == 'p'){
        printf("Entrez le module du nombre complexe : ");
        scanf("%lf", &c.polaire.r);
        printf("Entrez l'argument du nombre complexe : ");
        scanf("%lf", &c.polaire.theta);
        c.cartesien.x = c.polaire.r * cos(c.polaire.theta);
        c.cartesien.y = c.polaire.r * sin(c.polaire.theta);
        printf("Le nombre complexe en forme cartésienne est : %lf + %lf * i", c.cartesien.x, c.cartesien.y);
    }
}
void SomeCplx(){
    //fonction Somme complexe
    struct Cplx c1, c2, c3;
    char choix;
    printf("Voulez-vous entrer un nombre complexe sous forme cartésienne ou polaire ? (c/p) ");
    scanf("%c", &choix);
    while (choix != 'c' && choix != 'p'){
        scanf("%c", &choix);
    }
    if(choix == 'c'){
        printf("Entrez la partie réelle du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.x);
        printf("Entrez la partie imaginaire du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.y);
        printf("Entrez la partie réelle du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.x);
        printf("Entrez la partie imaginaire du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.y);
        c3.cartesien.x = c1.cartesien.x + c2.cartesien.x;
        c3.cartesien.y = c1.cartesien.y + c2.cartesien.y;
        printf("La somme des deux nombres complexes est : %lf + %lf * i", c3.cartesien.x, c3.cartesien.y);
    }
    else if(choix == 'p'){
        printf("Entrez le module du premier nombre complexe : ");
        scanf("%lf", &c1.polaire.r);
        printf("Entrez l'argument du premier nombre complexe : ");
        scanf("%lf", &c1.polaire.theta);
        printf("Entrez le module du deuxième nombre complexe : ");
        scanf("%lf", &c2.polaire.r);
        printf("Entrez l'argument du deuxième nombre complexe : ");
        scanf("%lf", &c2.polaire.theta);
        c3.polaire.r = c1.polaire.r + c2.polaire.r;
        c3.polaire.theta = c1.polaire.theta + c2.polaire.theta;
        printf("La somme des deux nombres complexes est : %lf * e^(i * %lf)", c3.polaire.r, c3.polaire.theta);
    }
}
void SousCplx(){
    //fonction Soustraction complexe
    struct Cplx c1, c2, c3;
    char choix;
    printf("Voulez-vous entrer un nombre complexe sous forme cartésienne ou polaire ? (c/p) ");
    scanf("%c", &choix);
    while (choix != 'c' && choix != 'p'){
        scanf("%c", &choix);
    }
    if(choix == 'c'){
        printf("Entrez la partie réelle du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.x);
        printf("Entrez la partie imaginaire du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.y);
        printf("Entrez la partie réelle du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.x);
        printf("Entrez la partie imaginaire du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.y);
        c3.cartesien.x = c1.cartesien.x - c2.cartesien.x;
        c3.cartesien.y = c1.cartesien.y - c2.cartesien.y;
        printf("La soustraction des deux nombres complexes est : %lf + %lf * i", c3.cartesien.x, c3.cartesien.y);
    }
    else if(choix == 'p'){
        printf("Entrez le module du premier nombre complexe : ");
        scanf("%lf", &c1.polaire.r);
        printf("Entrez l'argument du premier nombre complexe : ");
        scanf("%lf", &c1.polaire.theta);
        printf("Entrez le module du deuxième nombre complexe : ");
        scanf("%lf", &c2.polaire.r);
        printf("Entrez l'argument du deuxième nombre complexe : ");
        scanf("%lf", &c2.polaire.theta);
        c3.polaire.r = c1.polaire.r - c2.polaire.r;
        c3.polaire.theta = c1.polaire.theta - c2.polaire.theta;
        printf("La soustraction des deux nombres complexes est : %lf * e^(i * %lf)", c3.polaire.r, c3.polaire.theta);
    }
}
void MulCplx(){
    //fonction Multiplication complexe
    struct Cplx c1, c2, c3;
        printf("Veuillez entrer la partie réelle du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.x);
        printf("Veuillez entrer la partie imaginaire du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.y);
        printf("Veuillez entrer la partie réelle du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.x);
        printf("Veuillez entrer la partie imaginaire du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.y);
        c3.cartesien.x = c1.cartesien.x * c2.cartesien.x - c1.cartesien.y * c2.cartesien.y;
        c3.cartesien.y = c1.cartesien.x * c2.cartesien.y + c1.cartesien.y * c2.cartesien.x;
        printf("Le produit des deux nombres complexes est : %lf + %lf * i", c3.cartesien.x, c3.cartesien.y);

    

}
void DivCplx(){
    //division complexe
    struct Cplx c1, c2, c3;
        printf("Veuillez entrer la partie réelle du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.x);
        printf("Veuillez entrer la partie imaginaire du premier nombre complexe : ");
        scanf("%lf", &c1.cartesien.y);
        printf("Veuillez entrer la partie réelle du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.x);
        printf("Veuillez entrer la partie imaginaire du deuxième nombre complexe : ");
        scanf("%lf", &c2.cartesien.y);
        c3.cartesien.x = (c1.cartesien.x * c2.cartesien.x + c1.cartesien.y * c2.cartesien.y) / (c2.cartesien.x * c2.cartesien.x + c2.cartesien.y * c2.cartesien.y);
        c3.cartesien.y = (c1.cartesien.y * c2.cartesien.x - c1.cartesien.x * c2.cartesien.y) / (c2.cartesien.x * c2.cartesien.x + c2.cartesien.y * c2.cartesien.y);
        printf("Le quotient des deux nombres complexes est : %lf + %lf * i", c3.cartesien.x, c3.cartesien.y);
    
}
void equa2nd(){
 // a FAIRE
}

void exo_35()
{
    int tableau[10];
    printf("Swap dans un tableau de valeurs entières\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Valeur %d : ", i);
        scanf("%d", &tableau[i]);
    }
    printf("Veuillez entrer deux indices :\n ");
    int indice1, indice2;
    scanf("%d %d", &indice1, &indice2);
    int temp = tableau[indice1];
    tableau[indice1] = tableau[indice2];
    tableau[indice2] = temp;
    printf("Tableau après swap :\n ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", tableau[i]);
    }
    return;
}
void exo_36(){
    int i, taille, maj, min, chiffre, autre;
    char ch;
    char tableau[100];
    printf("Veuillez entrer une chaine de caractères (100 caractères max) : \n");
    fflush(stdin);
    scanf("%[^\n]", tableau);
    taille = strlen(tableau);
    maj=0;
    min=0;
    chiffre=0;
    autre=0;


    for ( i = 0; i < taille; i++)
    {
        ch = tableau[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            maj++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            min++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            chiffre++;
        }
        else if (ch == ' ')
        {
            autre++;
        }
    }
    printf("Majuscules : %d\n", maj);
    printf("Minuscules : %d\n", min);
    printf("Chiffres : %d\n", chiffre);
    printf("Espaces : %d\n", autre);
    return;
    
}
void exo_37(){
    printf("Faire l'addition, la soustraction, la multiplication et la division de deux matrices\n");
    int matrice1[3][3];
    int matrice2[3][3];
    printf("Matrice 1 :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Valeur %d de la ligne %d : ", j+1, i+1);
            scanf("%d", &matrice1[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrice1[i][j]);
        }
        printf("\n");
    }
    printf("Matrice 2 :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Valeur %d de la ligne %d : ", j+1, i+1);
            scanf("%d", &matrice2[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrice2[i][j]);
        }
        printf("\n");
    }
    printf("Addition :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrice1[i][j] + matrice2[i][j]);
        }
        printf("\n");
    }
    printf("Soustraction :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrice1[i][j] - matrice2[i][j]);
        }
        printf("\n");
    }
    printf("Multiplication :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrice1[i][j] * matrice2[i][j]);
        }
        printf("\n");
    }
    printf("Division :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrice1[i][j] / matrice2[i][j]);
        }
        printf("\n");
    }

    return;
}
void exo_38(){
    MulCplx();
    return;
}
void exo_39(){
    int tableau[100];
    int taille;
    int val, max, i, j;
    printf("Tri dans l'ordre décroissant d'un tableau de valeurs entières\n");
    printf("Veuillez entrer une valeur pour la taille du tableau : ");
    scanf("%d", &taille);
    printf("Veuillez entrer les valeurs du tableau :\n");
    for (i = 0; i < taille; i++)
    {
        printf("Valeur %d : ", i+1);
        scanf("%d", &tableau[i]);
    }
    for (i = 0; i < taille; i++)
    {
        max = i;
        for (j = i+1; j < taille; j++)
        {
            if (tableau[j] > tableau[max])
            {
                max = j;
            }
        }
        val = tableau[i];
        tableau[i] = tableau[max];
        tableau[max] = val;
    }
    printf("Tableau trié :\n");
    for (i = 0; i < taille; i++)
    {
        printf("%d ", tableau[i]);
    }
    return;

}
void exo_40(){
    printf("Transposer une matrice et sa multiplication par un réel\n");
    printf("Veuillez entrer un facteur réel : ");
    float facteur;
    scanf("%f", &facteur);
    printf("Veuillez indiquer la taille de la matrice (ligne) : ");
    int i;
    scanf("%d", &i);
    printf("Veuillez indiquer la taille de la matrice (colonne) : ");
    int j;
    scanf("%d", &j);
    int matrice[i][j];
    int matrice2[j][i];
    int val, k ,l;
    float reel;
    printf("Veuillez entrer les valeurs de la matrice :\n");
    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            printf("Valeur %d de la ligne %d : ", l+1, k+1);
            scanf("%d", &matrice[k][l]);
            matrice2[l][k] = matrice[k][l];
            matrice[k][l] = facteur * matrice[k][l];
            
        }
    }
    printf("Matrice transposée:\n");
    for (k = 0; k < j; k++)
    {
        for (l = 0; l < i; l++)
        {
            printf("|%d|", matrice2[k][l]);
        }
        printf("\n");
    }
    printf("Matrice multipliée par %f :\n", facteur);
    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            printf("|%d|", matrice[k][l]);
        }
        printf("\n");
    }
}
void exo_what(){
printf(" ░░░░░░░░███████████████░░░░░░░░\n");
printf("░░░░░█████████████████████░░░░░\n");
printf("░░░░████████████████████████░░░\n");
printf("░░░██████████████████████████░░\n");
printf("░░█████████████████████████████\n");
printf("░░███████████▀░░░░░░░░░████████\n");
printf("░░███████████░░░░░░░░░░░░░░░███\n");
printf("░████████████░░░░░░░░░░░░░░░░██\n");
printf("░█░░███████░░░░░░░░░░░▄▄░░░░░██\n");
printf("█░░░░█████░░░░░░▄███████░░██░░█\n");
printf("█░░█░░░███░░░░░██▀▀░░░░░░░░██░█\n");
printf("█░░░█░░░░░░░░░░░░▄██▄░░░░░░░███\n");
printf("█░░▄█░░░░░░░░░░░░░░░░░░█▀▀█▄░██\n");
printf("█░░░░░░░░░░░░░░░░░░░░░░█░░░░██░\n");
printf("░███░░░░░░░░░░░░░░░░░░░█░░░░█░░\n");
printf("░░█░█░░░░░░░█░░░░░██▀▄░▄██░░░█░\n");
printf("░░█░█░░░░░░█░░░░░░░░░░░░░░░░░█░\n");
printf("░░░██░░░░░░█░░░░▄▄▄▄▄▄░░░░░░█░░\n");
printf("░░░██░░░░░░░█░░█▄▄▄▄░▀▀██░░█░░░\n");
printf("░░░██░░░░░░░█░░▀████████░░█░░░░\n");
printf("░░█░░█░░░░░░░█░░▀▄▄▄▄██░░█░░░░░\n");
printf("░░█░░░█░░░░░░░█░░░░░░░░░█░░░░░░\n");
printf("░█░░░░░█░░░░░░░░░░░░░░░░█░░░░░░\n");
printf("░░░░░░░░█░░░░░░█░░░░░░░░█░░░░░░\n");
printf("░░░░░░░░░░░░░░░░████████░░░░░░░\n");

}
void exo_41(){
    // Insertion ordonnée
    
}
void exo_45(){
    //Gestion de Parking
    int nbPlace_voiture;
    int nbPlace_moto;
    int nbPlace_camion;
    int nbPlaceOccupe;
    int nbPlaceLibre;
    int nbPlaceReserve;
    int *num_place;
    int choix;
    //On indique le nombre de place initiallement pour chaque type de véhicule
    nbPlace_voiture = 20;
    nbPlace_moto = 10;
    nbPlace_camion = 10;

    printf("Veuillez indiquer l'action à réaliser :\n");
    printf("1. Afficher le nombre de places disponibles\n");
    printf("2. Afficher le nombre de places occupées\n");
    printf("3. Afficher le nombre de places libres\n");    
}
int main()
{

    system("cls");
    int choix;
    printf("Veuillez choisir un exercice parmis ci dessous:\n");
    printf("35. Swap dans un tableau\n");
    printf("36. Compter les caractères d'une chaine\n");
    printf("37. Faire l'addition, la soustraction, la multiplication et la division de deux matrices [3][3]\n");
    printf("38. Nombres complexes\n");
    printf("39. Tri dans l'ordre décroissant d'un tableau de valeurs entières\n");
    printf("40. Transposer une matrice et sa multiplication par un réel\n");
    printf("41. \n");
    printf("45. Gestion de Parking\n");
    printf("69. Easter egg\n");


    scanf("%d", &choix);
    switch (choix)
    {
    case 35:
        system("cls");
        exo_35();
        break;
    case 36:
        system("cls");
        exo_36();
        break;
    case 37:
        system("cls");
        exo_37();
        break;
    case 38:
        system("cls");
        exo_38();
        break;
    case 39:
        system("cls");
        exo_39();
        break;
    case 40:
        system("cls");
        exo_40();
        break;
    case 41:
        system("cls");
        exo_41();
        break;
    case 45:
        system("cls");
        exo_45();
        break;
    case 69:
        system("cls");
        exo_what();
        break;
    default:
        printf("Veuillez choisir un numéro d'exercice valide\n");
    }
    return 0;
}