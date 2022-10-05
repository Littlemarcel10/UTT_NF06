#include <stdio.h>
typedef union group{
    short a;
    char car;
    char cac;
} group;
typedef struct{
    char nom[20];
    int quantite;
} produit;

void exemple_1(){
    group gr;
    gr.car= 'z'; gr.a=128;
    printf("a=%d, car=%d and cac=%d\n", gr.a,gr.car,gr.cac);
    printf("address of a %d\n", &(gr.a));
    printf("address of car %d\n", &(gr.car));
    return 0;
}

void add(){
    int a, i;
    printf("Combien de produit voulez vous ajouter? ");
    scanf("%d", &a);
    produit tab[a];
    for(i=0; i<a; i++){
        printf("Nom du produit: ");
        scanf("%s", tab[i].nom);
        printf("Quantite: ");
        scanf("%d", &tab[i].quantite);
    }
    return 0;
}

//Exercise: Supermarket management
void exemple_2(){
    add();
    return 0;
}

int main(){
    exemple_2();
    return 0;
}