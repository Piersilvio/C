
/*
 * Calcolo Numerico
 * Metodo di ritrovamento di uno zero di una funzione lineare a singola variabile
 * per mezzo dell'algoritmo delle bisezioni successive
 *
 * spicoli piersilvio - Uniba Informatica
 */

/*
 * N ← 1
While N ≤ NMAX # limite alle iterazioni per impedire loop infiniti
  c ← (a + b)/2 # new midpoint
  If f(c) = 0 or (b – a)/2 < TOL then # soluzione individuata
    Output(c)
    Stop
  EndIf
  N ← N + 1 # incremento del contatore
  If sign(f(c)) = sign(f(a)) then a ← c else b ← c # nuovo intervallo
EndWhile
Output("Operazione non riuscita.") # massimo numero di iterazioni superato
 */

#include <stdio.h>
#include <stdlib.h>

//funzione che calcola l'estremo della nuova bisezione al variare del segno di f.
float x(float, float);
float x(float a, float b)
{
    float result = 0;

    result = (1/2)*(a + b);

    return result;
}

//funzione che calcola la funzione x^3-x+3 in punti a e b
float funzione(float);
float funzione(float c)
{
    float result;
    result = ((c*c*c) - c - 2);

    return result;
}

int segno(float);
int segno(float num)
{
    int result;
    if(num < 0)
        return result = 1;
    else if(num > 0)
        return result = 0;
}

int main()
{
    //var. locali
    float a, b, delta, bisezione, zero, dist, f_x, f_a;
    int s_x, s_a, trovato = 0; //non trovato


    printf("Calcolo dello zero di f(x) = x^3-x+3\n");
    do{
        printf("Estremo sinistro - 'a':  ");
        scanf("%f", &a);
    }while(a < 0);

    do{
        printf("Estremo destro - 'b':  ");
        scanf("%f", &b);
    }while(b < 0);

    printf("Grado di tolleranza di errore: ");
    scanf("%f", &delta);

    do {
        bisezione  = x(a, b);
        dist = b - bisezione;
        if(dist < delta)
        {
            trovato = 1;
            break;
        }else
        {
            //valuto il segno nel punto a rispetto ad x
            f_x = funzione(bisezione);
            f_a = funzione(a);
            s_x = segno(f_x);
            s_a = segno(f_a);

            if(s_x != s_a)
            {
                b = bisezione;
            }else
            {
                a = bisezione;
            }
        }
    }while(trovato == 0);

    zero = bisezione;

    printf("zero di x^3-x+3 -> %f", zero);

    return 0;
}
