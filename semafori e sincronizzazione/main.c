/*
 * spicoli piersilvio - uniba computer science
 * traffic litgh sync prototype
 */
#include <stdio.h>
#include <stdlib.h>

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
// implementation of a counter semaphore

typedef struct{

	int istanze;  //number of istance - counter
	int *lista_attesa; //list of processes in state of ready - suspend - counter

}semaforo;

semaforo s;

//declare function
void wait(s);
void signal(s);

int main(){

	signal(s);

	//critical section

    wait(s);

}

// when wait () is called by a process in ready - suspend
void wait(semaforo *s){

	if(s->istanze <= 0){
		s->lista_attesa += 1; 	// sleep (); - if the instances are terminated, the process remains in active wait
								// as long as the value of the resource is positive
	}else{
		signal(s); //wakeup();
	}

	s->istanze -= 1;	//decrement of istance
}

void signal(s){

	if(s->istanze <= 0){
		s->lista_attesa -= 1; 	// wakeup (); - call the process from the waiting list
	}else{
		wait(s); //sleep();
	}

	s->istanze += 1;	//increment of istance
}


