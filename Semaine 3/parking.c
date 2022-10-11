#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int nbPlace_moto = 10;
int nbPlace_voiture = 20;
int nbPlace_camion = 10;
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
    struct place parking_moto[20];
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
        struct parking client;
        printf("Veuillez saisir le nom du proprietaire: \n");
        char nom[20];
        char nom2[20];
        scanf("%s", nom);
        fflush(stdin);
        client.parking_moto[i].info_vehicule->vehicule_proprietaire , nom;
        nom2, client.parking_moto[i].info_vehicule->vehicule_proprietaire;
        printf("%s\n",nom2);
        /*printf("Veuillez saisir l'immatriculation du vehicule: \n");
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
        nbPlace_moto--;*/
        break;
        //on effectue la même chose pour les autres types de véhicules
    case 2:
       /* printf("Vous avez choisi une voiture\n");
        if (nbPlace_voiture == 0){
            printf("Il n'y a plus de place pour les voitures\n");
        }
        else{
            printf("Il reste %d places pour les voitures\n", nbPlace_voiture);
        }
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

        
*/

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
    //On indique le nombre de place disponible dans le parking
    printf("Il reste %d places pour les motos\n", nbPlace_moto);
    printf("Il reste %d places pour les voitures\n", nbPlace_voiture);
    printf("Il reste %d places pour les camions\n", nbPlace_camion);

}

void info(){
    struct parking client;
    fflush(stdin);
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
            printf("Le proprietaire est %s\n", client.parking_moto[place].info_vehicule->vehicule_proprietaire);
            /*printf("L'immatriculation est %s\n", place_moto[place].place_vehicule->vehicule_immatriculation);
            printf("L'année est %d\n", place_moto[place].place_vehicule->vehicule_annee);
            printf("La marque est %d\n", place_moto[place].place_vehicule->vehicule_marque);
            printf("Le type est %d\n", place_moto[place].place_vehicule->vehicule_type);
            printf("Le nombre d'heures est %d\n", place_moto[place].nb_heures);
            printf("La date est %d\n", place_moto[place].date);*/
        }
        
        
    fflush(stdin);

    }
}

int main(){
    reserver();
    return 0;
}