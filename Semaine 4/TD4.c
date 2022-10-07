#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void exo_46(){
    
}

int main(){
    int choix;
    printf("Choisissez un exercice: ");
    scanf("%d", &choix);

    switch(choix){
        case 46:
            exo_46();
            break;
        default:
            printf("Choix invalide");
            break;
    }
}