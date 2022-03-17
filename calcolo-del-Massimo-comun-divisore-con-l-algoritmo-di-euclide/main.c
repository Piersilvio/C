/*
    spicoli piersilvio - uniba computer science
    calcolo del mcd con algoritmo di euclide
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mcd(int, int);

int mcd(int n1, int n2){

    int r = 0;

    r = n1 % n2; //calcolo il resto

    while(r > 0){

        n1 = n2;
        n2 = r;
        r = n1 % n2; //calcolo il resto
    }

    if(n1 < 0)
        n1 = abs(n1);

    return n2;
}

int main(){

    int a, b, ris;

    printf(":: inserire i due numeri -> ");
    scanf("%d %d", &a, &b);

    ris = mcd(a,b);

    printf(":: il mcd fra %d e %d è -> %d", a, b, ris);

    return 0;
}
