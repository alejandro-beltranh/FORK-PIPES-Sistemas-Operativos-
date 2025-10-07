///////////////////////////////////////////////////////////
//Alejandro Beltran Huertas
//Sistemas Operativos
// Ejercicio FORK
// 7/10/2025
//Este progrma Crea un proceso hijo con fork() y luego ambos el padre y el hijo ejecutan un bucle que imprime los números del 0 al 4.
//Demuestra cómo los dos procesos corren el mismo código de forma simultánea e independiente, mostrando dos secuencias de impresión.
////////////////////////////////////////////////////////


#include <stdio.h>
#include <unistd.h>  // para poder usar fork()
#include <sys/wait.h> 

// crea un nuevo proceso, una copia del actual
int main(int argc, char *argv[]) {

    int processID = fork();
    if (processID > 0) {
        printf("\n'Proceso padre'.... \n");
//Proceso padre
    }
    else if (processID == 0) { // Proceso hijo
        printf("\n'Proceso hijo' recién creado \n");
    }
    else { // error en la creación del proceso
        printf("\nLlamada al sistema fork() falló\n");
    }

    printf("\n\nImprimiendo ... \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\nFin\n");

    return 0; // Fin del programa

}
