///////////////////////////////////////////////////////////
//Alejandro Beltran Huertas
//Sistemas Operativos 
// Ejercicio FORK
// 7/10/2025
//Este programa utiliza la llamada al sistema fork() para crear un proceso hijo.
//Muestra cómo fork() devuelve valores distintos en el proceso padre y el hijo, e imprime los identificadores de ambos.
//Ambos procesos ejecutan el mismo bloque final, por eso el mensaje se repite.
////////////////////////////////////////////////////////



#include <stdio.h>
#include <unistd.h> //Biblioteca que contiene la función fork(), getpid() y getppid()

int main(int argc, char *argv[]) {
    int processID = fork();  // Crea un nuevo proceso duplicando el proceso actual

	// fork() devuelve diferentes valores dependiendo del proceso:
    // si es mayor a  0  estamos en el proceso padre 
    //si es  igual a 0 estamos en el proceso hijo
    // si es menor a 0  error al crear el proceso	

    if (processID > 0) {
	//proceso padre

        printf("fork() devuelve un valor +ve. Este es el 'proceso padre' con ID: %d\n", getpid());
    }
    else if (processID == 0) {
	//el proceso hijo
        printf("fork() devuelve un valor 0. Este es un 'proceso hijo' recién creado con ID: %d\n", getpid());
        printf("El 'proceso padre' de este 'proceso hijo' tiene el ID: %d\n", getppid());
    }
    else {
	// Muestra si hay un error al crear el proceso
        printf("fork() devuelve un valor -ve, por lo que la llamada al sistema fork() falló\n");
    }

    printf("\nEsta es una única impresión. Si la llamada al sistema fork() ha tenido éxito,\n");
    printf("tanto el 'proceso padre' como el 'proceso hijo' se ejecutarán simultáneamente,\n");
    printf("y esta impresión aparecerá dos veces.\n");

    return 0;
//Fin del programa
}

