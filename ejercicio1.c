//Ejercicio 7
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main ( int argc , char * argv []) {
	int i ;
	int hijos[5];
	for ( i=0; i <5; i++){
		hijos[i]=fork();
		if(hijos[i]==0) {
			if (i == 0) execl("/usr/bin/xeyes", "xeyes" , (char*)0);
			if (i == 1) execl("/usr/bin/xload", "xload" , (char*)0);
			if (i == 2) execl("/usr/bin/xlogo", "xlogo" , ( char *) 0) ;
			if (i == 3) execl("/usr/bin/xcalc", "xcalc" , ( char *) 0) ;
			if (i == 4) execl("/usr/bin/xclock","xclock", "-update", "1",(char*)0);
		}
	}

	int status , hijo_matado ;
	pid_t pid ;
	while (1) {
		
		pid = wait(&status);
		// Buscamos que hijo ha muerto
		for( i=0; i<5; i++) {
			if( hijos[i] == pid){
				hijo_matado = i;
				break ;
			}
		}
		// Volvemos a crear un hijo
		hijos[hijo_matado] = fork();
		// El nuevo hijo crea el proceso que habia muerto
		if(hijos[hijo_matado] == 0) {
			if ( hijo_matado == 0) execl ( "/usr/bin/xeyes" , "xeyes " , ( char *) 0) ;
			if ( hijo_matado == 1) execl ( "/usr/bin/xload" , "xload " , ( char *) 0) ;
			if ( hijo_matado == 2) execl ( "/usr/bin/xlogo" , "xlogo " , ( char *) 0) ;
			if ( hijo_matado == 3) execl ( "/usr/bin/xcalc" , "xcalc " , ( char *) 0) ;
			if ( hijo_matado == 4) execl ( "/usr/bin/xclock" , "xclock" , "-update", "1",(char*)0) ;
		}
	}
	return 0;
}
