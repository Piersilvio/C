/*
 * spicoli piersilvio - uniba computer science
 * traffic litgh sync prototype
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* prototype
void wait(s){

	if(s <= 0){
		//busy wait
	}
	s -= 1;
}

void signal(s){

	s += 1;
}*/


// implementation of a counter semaphore
// the structure it acts on
// the list of processes is assumed to be based on priority and back and foreground
// the code below is based on logical and non-technical concepts
// it is considered appropriate to use THE <pthread> and <semaphore.h> LIBRARIES
// implementation of a binary semaphore
// usable if multiple resource instances are generalized

typedef struct{

	_Bool flag_istanze;  // flag instances - check if there is at least one free instance - if occupied then 1, otherwise 0
	int istanze;  // number of instances
	int *lista_attesa; // list of waiting processes - counter

}semaforo;

semaforo s;

void wait(s);
void signal(s);
void verify(s);

int main(){

	verify(s);
	signal(s);

	//critical section

    wait(s);

}

//quando wait() viene richiamata da parte di un processo in ready - suspend
void wait(semaforo *s){

	if(s->istanze <= 0){
		verify(1);		// sleep (); - if the instances are terminated, the process remains in active wait
									// as long as the value of the resource is positive
									// in case there are no resources available
	}else{
		verify(0);
		signal(s); //wakeup();
	}

	s->istanze -= 1;
}

void signal(s){

	if((s->istanze <= 0)){
		verify(0);	//wakeup();- richiama il processo dalla lista di attesa
	}else{
		verify(1);
		wait(s); //sleep();
	}

	s->istanze += 1;
}

_Bool verify(semaforo *s, _Bool flag_istanze){

	if(s->istanze > 0){

		return s->flag_istanze = 0; //se le istanze sono disponibili allora delle istanza sono libere (0)
	}else{

		return s->flag_istanze = 1; //se le istanze non sono disponibili allora sono occupate (1)
	}
}

