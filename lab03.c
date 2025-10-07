///////////////////////////////////////////////////////////
//Alejandro Beltran Huertas
//Sistemas Operativos
// Ejercicio FORK
// 7/10/2025
//Este programa Implementa un canal de comunicación unidireccional entre un proceso padre y su hijo mediante pipe().
//El proceso padre envía un mensaje por el pipe, y el proceso hijo lo recibe y lo muestra en pantalla.
////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // Arreglo con dos descriptores de archivo lectura y escritura
    pid_t pHijo_PID;// Variable para almacenar el ID del proceso hijo

//Se crea el pipe
    if (pipe(pipefd) == -1) { // La función pipe() inicializa los descriptores
        perror("PIPE"); // Si falla, imprime el error correspondiente
        exit(EXIT_FAILURE); // Termina el programa con estado de error
    }

    // Crear un nuevo proceso usando fork()
    pHijo_PID = fork();
    if (pHijo_PID == -1) {  // Validar si fork() falló
        perror("FORK");
        exit(EXIT_FAILURE);
    }

    
    if (pHijo_PID == 0) {
        close(pipefd[1]);  // Cierra el extremo de escritura solo leerá
        char mensaje[100]; // Buffer donde se almacenará el mensaje recibido
        int lecturaBYTES;  // Variable para verificar la cantidad de bytes leídos

        lecturaBYTES = read(pipefd[0], mensaje, sizeof(mensaje));
        if (lecturaBYTES == -1) { // Si la lectura falla, se muestra error
            perror("LECTURA");
            exit(EXIT_FAILURE);
        }
// Muestra el  mensaje recibido por el hijo
        printf("Proceso HIJO: Recibe mensaje --> %s\n", mensaje);
        close(pipefd[0]);  // Cierra el extremo de lectura después de usarlo
        exit(EXIT_SUCCESS); // Termina correctamente el proceso hijo
    }
  else {
        close(pipefd[0]); // Cierra el extremo de lectura solo escribe  
        char mensaje[] = "Hola desde el proceso padre!"; //Mensaje que se va a enviar 

       // Escribir datos en el pipe
        if (write(pipefd[1], mensaje, sizeof(mensaje)) == -1) {
            perror("ESCRITURA");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]); // Cierra el extremo de escritura después de usarlo
        wait(NULL); // Espera a que el proceso hijo termine su ejecución

        printf("Proceso PADRE: Mensaje enviado correctamente.\n");
    }

    return 0;
} //Se acaba el programa



