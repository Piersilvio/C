
/* Recursive function that calculates the factorial of a number> = 0
   the factorial n! is defined as:

   n! = 1 if n = 0
   n! = n * (n-1)! if n> 0

   spicoli piersilvio - uniba informatica

   nb * factorial calculable up to the value of 25

*/

#include <stdio.h>
#include <stdlib.h>

long long int fattoriale(long long int); //dichiarazione

long long int fattoriale(long long int n){

  if(n < 0)
    return -1;
  else if(n == 1)
    return 1;
  else
    return n*fattoriale(n - 1);
}

int main()
{
  long long int n, a, b;

  printf("Inserire un intero >= 0 : ");
  scanf("%lli", &n);
  printf("Il fattoriale di %d e' %lli\n", n, fattoriale(n));

  printf("\n\n");

  return 0;
}
