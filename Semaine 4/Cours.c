#include <stdio.h>
typedef union group{
    short a;
    char car;
    char cac;
} group;

int main(){
    group gr;
    gr.car= 'z'; gr.a=128;
    printf("a=%d, car=%d and cac=%d\n", gr.a,gr.car,gr.cac);
    printf("address of a %d\n", &(gr.a));
    printf("address of car %d\n", &(gr.car));
    return 0;
}