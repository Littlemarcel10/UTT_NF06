#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int nbPlace_moto = 10;
int nbPlace_voiture = 20;
int nbPlace_camion = 10;

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
    union info_sup vehicule_sup;
};
struct place{
    int nb_heures;
    int date;
    struct vehicule *info_vehicule;
    int place_numero[20];
};
struct parking{
    struct place parking_voiture;
    struct place parking_camion;
    struct place parking_moto;
};

void reserver(){
    //procédure pour réserver une place de parking
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
        // On vériifie si la place est libre
        if (nbPlace_moto == 0){
            printf("Il n'y a plus de place pour les motos\n");
        }
        else{
            printf("Il reste %d places pour les motos\n", nbPlace_moto);
        }
        //On demande les informations du véhicule
        int i;
        i= 10 - nbPlace_moto;
        struct place client[i];
        printf("Veuillez saisir le nom du proprietaire: \n");
        char nom[20];
        scanf("%s", nom);
        fflush(stdin);
        strcpy(client., nom);
        printf("Veuillez saisir l'immatriculation du vehicule: \n");
        char immat[20];
        scanf("%s", immat);
        strcpy(client[i].place_vehicule->vehicule_immatriculation, immat);
        printf("Veuillez saisir l'année du véhicule: \n");
        int annee;
        fflush(stdin);
        scanf("%d", &annee);
        client[i].vehicule_annee = annee;
        fflush(stdin);
        printf("Veuillez entrer la marque du véhicule :\n");
        printf("1 - Renault\n");
        printf("2 - Peugeot\n");
        printf("3 -Citroen\n");
        printf("4- BMW\n");
        printf("5- Audi\n");
        int marque;
        scanf("%d", &marque);
        fflush(stdin);
        switch (marque)
        {
        case 1:
            client.vehicule_marque = Renault;
            break;
        case 2:
            client.vehicule_marque = Peugeot;
            break;
        case 3:
            client.vehicule_marque = Citroen;
            break;
        case 4:
            client.vehicule_marque = BMW;
            break;
        case 5:
            client.vehicule_marque = Audi;
            break;
        default:
            printf("Erreur de saisie\n");
            break;
        }
        client.vehicule_type = moto;
        printf("Veuillez saisir la vitesse maximale de la moto: \n");
        int vitesse;
        scanf("%d", &vitesse);
        fflush(stdin);
        client[i].vehicule_sup.vitesse_max = vitesse;
        //On demande la date et le nombre d'heures
        printf("Veuillez saisir la date de la reservation: (prix: 5€/heure en semaine, 3€/heure week-end) \n");
        printf("1 - Lundi\n");
        printf("2 - Mardi\n");
        printf("3 - Mercredi\n");
        printf("4 - Jeudi\n");
        printf("5 - Vendredi\n");
        printf("6 - Samedi\n");
        printf("7 - Dimanche\n");
        int date;
        scanf("%d", &date);
        printf("Veuillez saisir le nombre d'heures de la reservation: \n");
        int nb_heures;
        scanf("%d", &nb_heures);
        //On calcul le prix de la reservation
        int prix;
        if (date == 6 || date == 7){
            prix = nb_heures * 3;
        }
        else{
            prix = nb_heures * 5;
        }
        printf("Le prix de la reservation est de %d€\n", prix);
        //On crée la place
        struct place place_moto[20];
        place_moto[i]->date = date;
        place_moto[i].nb_heures = nb_heures;
        place_moto[i].place_vehicule = &client;
        // On attribue un numéro de place au client
        place_moto[i].place_numero = 10 - nbPlace_moto;

        //On réduit le nombre de place disponible
        nbPlace_moto--;
        break;
        //on effectue la même chose pour les autres types de véhicules
    case 2:
        printf("Vous avez choisi une voiture\n");
        if (nbPlace_voiture == 0){
            printf("Il n'y a plus de place pour les voitures\n");
        }
        else{
            printf("Il reste %d places pour les voitures\n", nbPlace_voiture);
        }
        int i;
        i = nbPlace_voiture;
        struct vehicule client_voiture;
        printf("Veuillez saisir le nom du proprietaire: \n");
        scanf("%s", nom);
        fflush(stdin);
        strcpy(client_voiture.vehicule_proprietaire, nom);
        printf("Veuillez saisir l'imatriculation du vehicule: \n");
        scanf("%s", immat);
        strcpy(client_voiture.vehicule_immatriculation, immat);
        printf("Veuillez saisir l'année du véhicule: \n");
        fflush(stdin);
        scanf("%d", &annee);
        client_voiture.vehicule_annee = annee;
        fflush(stdin);
        printf("Veuillez entrer la marque du véhicule :\n");
        printf("1 - Renault\n");
        printf("2 - Peugeot\n");
        printf("3 -Citroen\n");
        printf("4- BMW\n");
        printf("5- Audi\n");
        scanf("%d", &marque);
        fflush(stdin);
        switch (marque)
        {
        case 1:
            client_voiture.vehicule_marque = Renault;
            break;
        case 2:
            client_voiture.vehicule_marque = Peugeot;
            break;
        case 3:
            client_voiture.vehicule_marque = Citroen;
            break;
        case 4:
            client_voiture.vehicule_marque = BMW;
            break;
        case 5:
            client_voiture.vehicule_marque = Audi;
            break;
        default:
            printf("Erreur de saisie\n");
            break;
        }
        client_voiture.vehicule_type = moto;
        printf("Veuillez saisir le nombre de portes de la voiture: \n");
        int nb_portes;
        scanf("%d", &nb_portes);
        fflush(stdin);
        client_voiture.vehicule_sup.nb_portes = nb_portes;
        //On demande la date et le nombre d'heures
        printf("Veuillez saisir la date de la reservation: (prix: 5€/heure en semaine, 3€/heure week-end) \n");
        printf("1 - Lundi\n");
        printf("2 - Mardi\n");
        printf("3 - Mercredi\n");
        printf("4 - Jeudi\n");
        printf("5 - Vendredi\n");
        printf("6 - Samedi\n");
        printf("7 - Dimanche\n");
        scanf("%d", &date);
        printf("Veuillez saisir le nombre d'heures de la reservation: \n");
        scanf("%d", &nb_heures);
        //On calcul le prix de la reservation
        if (date == 6 || date == 7){
            prix = nb_heures * 3;
        }
        else{
            prix = nb_heures * 5;
        }
        printf("Le prix de la reservation est de %d€\n", prix);
        //On souhaite stocker les informations du client dans une place
        //On crée la place
        struct place place_voiture;
        place_voiture.date = date;
        place_voiture.nb_heures = nb_heures;
        place_voiture.place_vehicule = &client_voiture;

        
        
        //On réduit le nombre de place disponible
        nbPlace_voiture--;

        


        break;
    case 3:
        printf("Vous avez choisi un camion\n");
        break;
    default:
        printf("Erreur de choix\n");
        break;
    }

}
*/
void update(){
    //On indique le nombre de place disponible dans le parking
    printf("Il reste %d places pour les motos\n", nbPlace_moto);
    printf("Il reste %d places pour les voitures\n", nbPlace_voiture);
    printf("Il reste %d places pour les camions\n", nbPlace_camion);

}

void info(){
    struct place place_moto[20];
    //On affiche les informations du véhicule d'une place
    int place;
    int choix;
    printf("Veuillez saisir le type de véhicule: \n");
    scanf("%d", &choix);
    switch (choix)
    {
        case 1:
        // Cas de la moto
        printf("Veuillez saisir le numéro de la place: \n");
        scanf("%d", &place);
        //On verifie que la place existe
        if (place > 10){
            printf("Cette place n'existe pas\n");
        }
        else{
            //On affiche les informations du véhicule
            printf("Le proprietaire est %s\n", place_moto[place].place_vehicule->vehicule_proprietaire);
            printf("L'immatriculation est %s\n", place_moto[place].place_vehicule->vehicule_immatriculation);
            printf("L'année est %d\n", place_moto[place].place_vehicule->vehicule_annee);
            printf("La marque est %d\n", place_moto[place].place_vehicule->vehicule_marque);
            printf("Le type est %d\n", place_moto[place].place_vehicule->vehicule_type);
            printf("Le nombre d'heures est %d\n", place_moto[place].nb_heures);
            printf("La date est %d\n", place_moto[place].date);
        }
        
        
    fflush(stdin);

    }
}
*/
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
void test_reserver(){
    int i;
        i= 10 - nbPlace_moto;
        struct place client;
        printf("Veuillez saisir le nom du proprietaire: \n");
        char nom[20];
        scanf("%s", nom);
        fflush(stdin);
        strcpy(client., nom);
        printf("Veuillez saisir l'immatriculation du vehicule: \n");
        char immat[20];
        scanf("%s", immat);
        strcpy(client.place_vehicule->vehicule_immatriculation, immat);
        printf("Veuillez saisir l'année du véhicule: \n");
        int annee;
        fflush(stdin);
        scanf("%d", &annee);
        client[i].vehicule_annee = annee;
        fflush(stdin);
        printf("Veuillez entrer la marque du véhicule :\n");
        printf("1 - Renault\n");
        printf("2 - Peugeot\n");
        printf("3 -Citroen\n");
        printf("4- BMW\n");
        printf("5- Audi\n");
        int marque;
        scanf("%d", &marque);
        fflush(stdin);
        switch (marque)
        {
        case 1:
            client[i].vehicule_marque = Renault;
            break;
        case 2:
            client[i].vehicule_marque = Peugeot;
            break;
        case 3:
            client[i].vehicule_marque = Citroen;
            break;
        case 4:
            client[i].vehicule_marque = BMW;
            break;
        case 5:
            client[i].vehicule_marque = Audi;
            break;
        default:
            printf("Erreur de saisie\n");
            break;
        }
        client[i].vehicule_type = moto;
        printf("Veuillez saisir la vitesse maximale de la moto: \n");
        int vitesse;
        scanf("%d", &vitesse);
        fflush(stdin);
        client[i].vehicule_sup.vitesse_max = vitesse;
        //On demande la date et le nombre d'heures
        printf("Veuillez saisir la date de la reservation: (prix: 5€/heure en semaine, 3€/heure week-end) \n");
        printf("1 - Lundi\n");
        printf("2 - Mardi\n");
        printf("3 - Mercredi\n");
        printf("4 - Jeudi\n");
        printf("5 - Vendredi\n");
        printf("6 - Samedi\n");
        printf("7 - Dimanche\n");
        int date;
        scanf("%d", &date);
        printf("Veuillez saisir le nombre d'heures de la reservation: \n");
        int nb_heures;
        scanf("%d", &nb_heures);
        //On calcul le prix de la reservation
        int prix;
        if (date == 6 || date == 7){
            prix = nb_heures * 3;
        }
        else{
            prix = nb_heures * 5;
        }
        printf("Le prix de la reservation est de %d€\n", prix);
        //On crée la place
        struct place place;
        place.date = date;
        place.nb_heures = nb_heures;
        place.place_vehicule = &client;
        // On attribue un numéro de place au client
        place.place_numero = 10 - nbPlace_moto;

        //On réduit le nombre de place disponible
        nbPlace_moto--;
        break;
        //on effectue la même chose pour les autres types de véhicules
}
void exo_45(){
    //Gestion de Parking
    int nbPlace_voiture;
    int nbPlace_moto;
    int nbPlace_camion;
    int nbPlaceOccupe;
    int nbPlaceLibre;
    int *num_place;
    int choix;
    int *choix2 = 1;
    //On indique le nombre de place initiallement pour chaque type de véhicule
    
    while (choix2 == 1)
    {
        

    printf("Veuillez indiquer l'action à réaliser :\n");
    printf("1. Réserver une place\n");
    printf("2. Vérifier le nombre de places disponibles\n");
    printf("3. Vérifier les informations d'une place\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        test_reserver();
        break;
    case 2:
        update();
        break;
    case 3:
        test_info();
        break;
    default:
        printf("cas 2\n");
        break;
    }
    printf("Voulez-vous réaliser de nouveau une action ? (1 = oui, 0 = non)\n");
    scanf("%d", &choix2);
    fflush(stdin);
    }
    
    
    
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