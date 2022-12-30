#include <stdio.h>
#define PI 3.1416

void exo1(){
    // "print Hello world!"
    printf("Hello world!\n");
    //print today's date
    printf("Today's date is 16/09/2022\n");
    //print week number
    printf("Week number is 37\n");
    //print e-mail address
    printf("My e-mail address is: gaudry.carlier@utt.fr\n");
}

void exo2(){
    int i = 1;
    int j = 5;

    //Division de j par i

    printf("Division de j par i: %d\n", j/i);
}

void exo3(){
    //print the weight in octet of each type
    printf("The weight in octet of int is: %d\n", sizeof(int));
    printf("The weight in octet of float is: %d\n", sizeof(float));
    printf("The weight in octet of double is: %d\n", sizeof(double));
    printf("The weight in octet of char is: %d\n", sizeof(char));

}

void exo4(){
    unsigned short A =104;
    unsigned short B = 0;
    float C= 6.5;
    //on convertit la valeur de C en unsigned short
    A = (unsigned short) C;
    A = ~A;
    B = A^(A+2);
    C = (float) (A<<B);
    A = A&(unsigned short) C;
}

void exo5(){
    int mask;
    int n;
    int p;
    int x;
    int result;
    mask = 1;
    mask = mask << p;
    mask = mask -1;
    mask = mask << (n-1);
    x = 10000;
    n= 2;
    p= 3;
    result =  mask;


    //Inverser une partie d'un nombre binaire

}

void exo6a(){
    //demander à l'utilisateur la première valeur
    int valeur1;
    int valeur2;
    int reste;
    int quotient;

    printf("Veuillez entrer la première valeur: ");
    scanf( "%d", &valeur1 );
    //demander à l'utilisateur la deuxième valeur
    printf("Veuillez entrer la deuxième valeur: ");
    scanf( "%d", &valeur2 );
    //calcul de la somme et affichage de la valeur
    printf("La somme des deux valeurs est: %d\n", valeur1+valeur2);
    //calcul du produit et affichage de la valeur
    printf("Le produit des deux valeurs est: %d\n", valeur1*valeur2);
    //calcul de la différence et affichage de la valeur
    printf("La différence des deux valeur est: %d\n", valeur1-valeur2);
    //calcul du quotient et affichage de la valeur
    quotient = valeur1 / valeur2;
    reste = valeur1 % valeur2;
    printf("Le quotient entre la valeur 1 et 2  est || %d ||et le reste est || %d || \n", quotient, reste );

}

void exo6b(){
    int A;
    int B;
    char C;
    char D;
    int intermediaire;
    char intermediaire2;
    printf("Veuillez entrer la valeur de A (entier): ");
    scanf( "%d", &A );
    printf("Veuillez entrer la valeur de B(entier): ");
    scanf( "%d", &B );
    intermediaire = A;
    A = B;
    B = intermediaire;
    printf("La valeur de A est: %d\n", A);
    printf("La valeur de B est: %d\n", B);
    printf("Veuillez entrer la valeur de C(charactère): ");
    scanf( " %c", &C );
    printf("Veuillez entrer la valeur de D(charactère): ");
    scanf( " %c", &D );
    intermediaire2 = C;
    C = D;
    D = intermediaire2;
    printf("La valeur de C est: %c\n", C);
    printf("La valeur de D est: %c\n", D);

}

void exo6c(){
    char A;
    char B;
    printf("Veuillez entrer la valeur de A(charactère): ");
    scanf("%c\n", &A);
    printf("Veuillez entrer la valeur de B(charactère): ");
    scanf("%c\n", &B);

    printf("La somme des deux valeurs est: %d\n", sizeof(A+B) );
    printf("La différence des deux valeurs est: %d\n", sizeof(A-B) );
}

void exo6d(){
    int valeur1;
    int valeur2;

    printf("Veuillez entrer la première valeur: ");
    scanf( "%d", &valeur1 );
    //demander à l'utilisateur la deuxième valeur
    printf("Veuillez entrer la deuxième valeur: ");
    scanf( "%d", &valeur2 );
    if (valeur1 > valeur2){
        printf("La valeur 1 est plus grande que la valeur 2\n");
        printf("La valeur 1 est vmax\n");
        printf("La valeur 2 est vmin\n");
    }
    else if (valeur1 < valeur2){
        printf("La valeur 1 est plus petite que la valeur 2\n");
        printf("La valeur 2 est vmax\n");
        printf("La valeur 1 est vmin\n");
    }
    else{
        printf("Les deux valeurs sont égales\n");
    }
}

void exo7(){
    float aire;
    float Base;
    float Hauteur;
    printf("Calcul de l'aire d'un triangle\n");
    printf("Veuillez entrer la valeur de la base: ");
    scanf( "%f", &Base );
    printf("Veuillez entrer la valeur de la hauteur: ");
    scanf( "%f", &Hauteur );
    aire = (Base*Hauteur)/2;
    printf("L'aire du triangle est: %f\n", aire);


}

void exo8(){
    float rayon;
    float base;
    float hauteur;
    float volume;
    
    printf("Calcul du volume d'un cône\n");
    printf("Veuillez entrer la valeur du rayon: ");
    scanf( "%f", &rayon );
    printf("Veuillez entrer la valeur de la hauteur: ");
    scanf( "%f", &hauteur );
    base = (rayon*rayon)*PI;
    volume = (base*hauteur)/3;
    printf("Le volume du cône est: %.2f\n", volume);


}

void exo9(){
    int binaires;
    int décimal;
    int binaires2;
    int décimal2 = 0;
    int binaires_nombre;
    int reste;
    int base = 1;
    int a[10], i;
    printf("Conversion binaire en décimal\n");
    printf("Veuillez entrer la valeur décimal: ");
    scanf( "%d", &décimal );
    for(i=0; décimal>0; i++)
    {
        a[i]=décimal%2;
        décimal= décimal/2;
    }
    printf("La valeur binaire est: ");
    for(i=i-1 ;i>=0 ;i--)
    {
        printf("%d",a[i]);
    }
    printf("\nVeuillez entrer la valeur binaire: ");
    scanf( "%d", &binaires2 );

    while (binaires2 > 0)
    {
        reste = binaires2 % 10;
        décimal2 = décimal2 + reste * base;
        binaires2 = binaires2 / 10 ;
        base = base * 2;
    }
    printf("La valeur décimal est: %d\n", décimal2);

    

}

void exo10(){
    int décimal;
    int octal;
    int a[10], i;

    printf("Convertir un entier de la base décimal à la base octale\n");
    printf("Veuillez entrer la valeur décimal: ");
    scanf( "%d", &décimal );
    for(i=0; décimal>0; i++)
    {
        a[i]=décimal%8;
        décimal= décimal/8;
    }
    printf("La valeur octale est: ");
    for(i=i-1 ;i>=0 ;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");


}

void exo11(){
    int décimal;
    int hexadécimal;
    int a[10], i;
    printf("Convertir un entier de la base décimal à la base hexadécimal\n");
    printf("Veuillez entrer la valeur décimal: ");
    scanf( "%d", &décimal );
    for(i=0; décimal>0; i++)
    {
        a[i]=décimal%16;
        décimal= décimal/16;
    }
    printf("La valeur hexadécimal est: ");
    for(i=i-1 ;i>=0 ;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");

}

void exo12(){

}

void exo13(){

}

void exo14(){

}

void exo15(){

}



int main(){
    exo2();
    return 0;
}


