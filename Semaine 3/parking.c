#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

union vehicule_data{
    int nombre_portes;
    int gabarit;
    int vitesse_max;
};

enum vehicule_type{
    voiture,
    camion,
    moto
};

enum vehicule_marque{
    renaud,
    peugeot,
    citroen,
    bmw,
    audi,
};

struct vehicule
{
    char prorietaire[20];
    char matricule[10];
    int annee;
    enum vehicule_marque modele;
    enum vehicule_type type;
    union vehicule_data data;
};

struct place {
    int date;
    int nb_heures;
    struct vehicule* vehicule;
};

struct parking {
    // 20 places de voiture, 10 de camion, 10 de moto
    struct place places_voiture[20];
    struct place places_camion[10];
    struct place places_moto[10];
};

void reserver(struct parking* p){
    // reserver une place
    // Entrer date, nombre d'heures, type de véhicule, matricule, propriétaire, année, marque
    int date = 0;
    int heure = 0;
    int type = 0;
    char matricule[10];
    char proprietaire[20];
    int annee = 0;
    int marque = 0;

    printf("Entrer la date (1: Lundi - 7: Dimanche) : ");
    scanf("%d", &date);

    printf("Entrer le nombre d'heures de réservation : ");
    scanf("%d", &heure);

    printf("Entrer le type de véhicule (1 pour voiture, 2 pour camion, 3 pour moto) : ");
    scanf("%d", &type);

    printf("Entrer le matricule : ");
    scanf("%s", matricule);

    printf("Entrer le nom du propriétaire : ");
    scanf("%s", proprietaire);

    printf("Entrer l'année de construction : ");
    scanf("%d", &annee);

    printf("Entrer la marque (1 pour Renault, 2 pour Peugeot, 3 pour Citroen, 4 pour BMW, 5 pour Audi) : ");
    scanf("%d", &marque);

    int info = 0;
    if(type == 1){
        // voiture => nombre de portes
        printf("Entrer le nombre de portes : ");
        scanf("%d", &info);
    }else if(type == 2){
        // camion => gabarit
        printf("Entrer le gabarit : ");
        scanf("%d", &info);
    }else if(type == 3){
        // moto => vitesse max
        printf("Entrer la vitesse max : ");
        scanf("%d", &info);
    }

     // Caclul du tarif avec 5€ par heure la semaine et 3€ par heure le week-end
    int tarif = 0;
    if(date >= 1 && date <= 5){
        tarif = heure * 5;
    }else{
        tarif = heure * 3;
    }

    printf("Le tarif est de %d€ \n", tarif);

    // Confirmation de la réservation

    printf("Confirmer la réservation ? (1 pour oui, 0 pour non) : ");
    int confirmation = 0;
    scanf("%d", &confirmation);

    if(confirmation == 0){
        printf("Réservation annulée \n");
        return;
    }

    struct vehicule* vehicule = malloc(sizeof(struct vehicule));
    strcpy(vehicule->matricule, matricule);
    strcpy(vehicule->prorietaire, proprietaire);
    vehicule->annee = annee;
    vehicule->modele = (marque - 1);
    vehicule->type = (type - 1);
    if(type == 1){
        vehicule->data.nombre_portes = info;
    }else if(type == 2){
        vehicule->data.gabarit = info;
    }else if(type == 3){
        vehicule->data.vitesse_max = info;
    }

    struct place* place = malloc(sizeof(struct place));
    place->nb_heures = heure;
    place->vehicule = vehicule;
    place->date = date;

    // Recherche d'une place disponible dans le struct parking
    int i = 0;
    if(vehicule->type == voiture){
        while(i < 20){
            if(p->places_voiture[i].vehicule == NULL){
                p->places_voiture[i] = *place;
                printf("Place réservée \n");
                break;
            }
            i++;
        }
    }else if(vehicule->type == camion){
        while(i < 10){
            if(p->places_camion[i].vehicule == NULL){
                p->places_camion[i] = *place;
                printf("Place réservée \n");
                break;
            }
            i++;
        }
    }else if(vehicule->type == moto){
        while(i < 10){
            if(p->places_moto[i].vehicule == NULL){
                p->places_moto[i] = *place;
                printf("Place réservée \n");
                break;
            }
            i++;
        }
    }

    // Afficher le récapitulatif de la réservation
    printf("Récapitulatif de la réservation : \n");
    printf("Date : %d \n", place->date);
    printf("Nombre d'heures : %d \n", place->nb_heures);
    printf("Matricule : %s \n", place->vehicule->matricule);
    printf("Propriétaire : %s \n", place->vehicule->prorietaire);
    printf("Année : %d \n", place->vehicule->annee);
    printf("Marque : %d \n", place->vehicule->modele);
    printf("Type : %d \n", place->vehicule->type);
}

void update(struct parking* p) {    
    // On simplifie : chaque update correpond à une heure de plus
    
    // Enlever les véhicules dont l'heure est dépassée
    int i = 0;
    while(i < 20){
        if(p->places_voiture[i].vehicule != NULL){
            if(p->places_voiture[i].nb_heures == 0){
                p->places_voiture[i].vehicule = NULL;
            }else{
                p->places_voiture[i].nb_heures--;
            }
        }
        i++;
    }

    i = 0;
    while(i < 10){
        if(p->places_camion[i].vehicule != NULL){
            if(p->places_camion[i].nb_heures == 0){
                p->places_camion[i].vehicule = NULL;
            }else{
                p->places_camion[i].nb_heures--;
            }
        }
        i++;
    }

    i = 0;
    while(i < 10){
        if(p->places_moto[i].vehicule != NULL){
            if(p->places_moto[i].nb_heures == 0){
                p->places_moto[i].vehicule = NULL;
            }else{
                p->places_moto[i].nb_heures--;
            }
        }
        i++;
    }
    printf("Update effectué \n");
}

void etat(struct parking* p){
    // Affiche le parking et donne le nombre de places libres

    int i = 0;
    int nb_places_libres = 0;
    while(i < 20){
        if(p->places_voiture[i].vehicule != NULL){
            printf("Place voiture %d : %s \n", (i + 1), p->places_voiture[i].vehicule->matricule);
        }
        if(p->places_voiture[i].vehicule == NULL){
            nb_places_libres++;
        }
        i++;
    }

    i = 0;
    while(i < 10){
        if(p->places_camion[i].vehicule != NULL){
            printf("Place camion %d : %s \n", (i + 1), p->places_camion[i].vehicule->matricule);
        }
        if(p->places_camion[i].vehicule == NULL){
            nb_places_libres++;
        }
        i++;
    }

    i = 0;
    while(i < 10){
        if(p->places_moto[i].vehicule != NULL){          
            printf("Place moto %d : %s \n", (i + 1), p->places_moto[i].vehicule->matricule);
        }
        if(p->places_moto[i].vehicule == NULL){
            nb_places_libres++;
        }
        i++;
    }

    printf("Nombre de places libres : %d \n", nb_places_libres);
}

void retirer(struct parking* p){
    // Retire un véhicule du parking

    printf("Matricule du véhicule à retirer : ");
    char matricule[10];
    scanf("%s", matricule);

    int i = 0;
    while(i < 20){
        if(p->places_voiture[i].vehicule != NULL){
            if(strcmp(p->places_voiture[i].vehicule->matricule, matricule) == 0){
                p->places_voiture[i].vehicule = NULL;
                printf("Véhicule retiré \n");
                break;
            }
        }
        i++;
    }

    i = 0;
    while(i < 10){
        if(p->places_camion[i].vehicule != NULL){
            if(strcmp(p->places_camion[i].vehicule->matricule, matricule) == 0){
                p->places_camion[i].vehicule = NULL;
                printf("Véhicule retiré \n");
                break;
            }
        }
        i++;
    }

    i = 0;
    while(i < 10){
        if(p->places_moto[i].vehicule != NULL){
            if(strcmp(p->places_moto[i].vehicule->matricule, matricule) == 0){
                p->places_moto[i].vehicule = NULL;
                printf("Véhicule retiré \n");
                break;
            }
        }
        i++;
    }

    printf("Véhicule non trouvé \n");
}

void exercice45(){
    time_t t = time(NULL);
    struct parking p = {0};
    
    int choix = 0;
    while(choix != 5){
        printf("1. Réserver une place \n");
        printf("2. Update \n");
        printf("3. Etat du parking \n");
        printf("4. Retirer un véhicule \n");
        printf("5. Quitter \n");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                reserver(&p);
                break;
            case 2:
                update(&p);
                break;
            case 3:
                etat(&p);
                break;
            case 4:
                retirer(&p);
                break;
            case 5:
                break;
            default:
                printf("Choix invalide \n");
                break;
        }
    }
}

int main(){
    exercice45();
    return 0;
}