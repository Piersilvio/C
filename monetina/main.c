/*
*   piersilvio spicoli uniba - computer science
*
*   Create the algorithm and program for
* 	simulate the toss of a coin. Allow
* 	the user to choose how many times to launch the
* 	coin and for each launch the program will have to
* 	display Heads or Tails and count the number
* 	of occurrences for the appearance of each face
* 	of the dime. Use a separate function that
* 	will receive no arguments and will return the
* 	result of tossing the coin (cross or
* 	head)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_face();

int n = 0, i, random;
int cont_head = 0, cont_crux = 0;

int main(){

		setbuf(stdout, NULL);
		srand(time(NULL));

		printf("how many times do you want to launch? \n");
		scanf("%d", &n);

		for(i = 0; i < n; i++){

			random = rand_face();

			if(random == 1) //if 1 -> head 0 -> crux
				cont_head += 1;
			else
				cont_crux += 1;

		}

		printf("number of occurrences: %d \n", n);
		printf("number of occurrences for 'crux': %d \n", cont_crux);
		printf("number of occurrences per 'head': %d \n", cont_head);

	return 0;
}

int rand_face(){ return rand()%2; }
