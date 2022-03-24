/*
 * piersilvio spicoli
 * università degli studi di bari - aldo moro
 *
 * fibonacci series
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

  setbuf(stdout, NULL);
  int i,N,primo,secondo,terzo; //'N' variables

  printf("How many numbers in the sequence you want to display? ");
  scanf("%d", &N);

  primo = 1;
  secondo = 1;

  printf("%d\n",primo);
  printf("%d\n",secondo);

  for(i = 2;i < N;i++) {
      terzo = primo + secondo;
      primo = secondo;
      secondo = terzo;
      printf("%d\n",terzo);
  }

  system("pause");
  return 0;
}
