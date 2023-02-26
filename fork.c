#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char *argv[]){

	
	switch(fork()){
	
	case -1:
		printf("Error al crear los procesos\n");
		exit(1);
	case 0:
		printf("Hola soy el hijo\n");

	default:
		sleep(1);
		printf("Hola, soy el padre\n");

	}

 //Fin 

	return 0;
}
