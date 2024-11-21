// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define TAMANO_TABLERO 3
// #define NUMERO_BARCOS 4

// // Prototipos de funciones
// void solicitarNombre(char nombre[]); 
// void mostrarReglas(); 
// void inicializarTablero(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]); 


// void colocarBarcosJugador(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
// void colocarBarcosPC(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
// void mostrarTableroJugador(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
// void mostrarTableroPC(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
// void iniciarJuego(char nombre[]);



// void turnoJugador(char tableroPC[TAMANO_TABLERO][TAMANO_TABLERO], int *barcosHundidos, int *barcosRestantes);



// void turnoPC(char tableroJugador[TAMANO_TABLERO][TAMANO_TABLERO], int *barcosHundidos, int *barcosRestantes);
// int validarCoordenadas(int x, int y);
// int validarDisparo(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], int x, int y);


// void mostrarRanking(int barcosHundidosJugador, int barcosHundidosPC, int barcosRestantesJugador, int barcosRestantesPC);

// int main() {
//     char nombre_jugador[50];
//     int opcion;

//     solicitarNombre(nombre_jugador);
//     mostrarReglas();

//     do {
//         iniciarJuego(nombre_jugador);
//         printf("¿Deseas jugar de nuevo? (1 para sí, 0 para salir): ");
//         scanf("%d", &opcion);
//     } while (opcion != 0);

//     printf("Gracias por jugar, %s. ¡Hasta pronto!\n", nombre_jugador);

//     return 0;
// }

// void solicitarNombre(char nombre[]) {
//     printf("Ingresa tu nombre: ");
//     scanf("%s", nombre);
//     printf("¡Hola, %s! Bienvenido a Batalla Naval.\n", nombre);
// }

// void mostrarReglas() {
//     printf("\nEste es el juego Batalla Naval.\n");
//     printf("Reglas:\n");
//     printf("1. Coloca tus barcos en el tablero.\n");
//     printf("2. Intenta hundir los barcos de la computadora disparando en el tablero.\n");
//     printf("3. El juego termina cuando uno de los jugadores hunde todos los barcos del oponente.\n");
//     printf("¡Que comience la batalla!\n\n");
// }

// void inicializarTablero(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
//     for (int i = 0; i < TAMANO_TABLERO; i++) {
//         for (int j = 0; j < TAMANO_TABLERO; j++) {
//             tablero[i][j] = '-';  // Agua
//         }
//     }
// }

// void colocarBarcosJugador(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
//     int x, y;
//     for (int i = 0; i < NUMERO_BARCOS; i++) {  // Colocar barcos del jugador
//         do {
//             printf("Ingresa las coordenadas para tu barco %d (x y): ", i + 1);
//             scanf("%d %d", &x, &y);
//         } while (!validarCoordenadas(x, y) || tablero[x][y] == 'B');  // Validar entrada y evitar colocar en el mismo lugar
//         tablero[x][y] = 'B';  // Colocar barco
//     }
// }

// void colocarBarcosPC(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
//     int x, y;
//     srand(time(NULL));  // Para generar números aleatorios
//     for (int i = 0; i < NUMERO_BARCOS; i++) {  // Colocar barcos de la PC
//         do {
//             x = rand() % TAMANO_TABLERO;
//             y = rand() % TAMANO_TABLERO;
//         } while (tablero[x][y] == 'B');  // Evitar colocar en el mismo lugar
//         tablero[x][y] = 'B';
//     }
// }

// // Mostrar el tablero del jugador (se ven sus barcos)
// void mostrarTableroJugador(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
//     printf("\nTablero del Jugador:\n  ");
    
//     // Mostrar los números del eje X (horizontal)
//     for (int i = 0; i < TAMANO_TABLERO; i++) {
//         printf("%d ", i);
//     }
//     printf("\n");

//     // Mostrar el tablero con los números del eje Y (vertical)
//     for (int i = 0; i < TAMANO_TABLERO; i++) {
//         printf("%d ", i);  // Mostrar los números del eje Y
//         for (int j = 0; j < TAMANO_TABLERO; j++) {
//             printf("%c ", tablero[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// // Mostrar el tablero de la PC (sin mostrar sus barcos, solo agua o disparos acertados)
// void mostrarTableroPC(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
//     printf("\nTablero de la PC:\n  ");
    
//     // Mostrar los números del eje X (horizontal)
//     for (int i = 0; i < TAMANO_TABLERO; i++) {
//         printf("%d ", i);
//     }
//     printf("\n");

//     // Mostrar el tablero con los números del eje Y (vertical)
//     for (int i = 0; i < TAMANO_TABLERO; i++) {
//         printf("%d ", i);  // Mostrar los números del eje Y
//         for (int j = 0; j < TAMANO_TABLERO; j++) {
//             if (tablero[i][j] == 'X' || tablero[i][j] == 'O') {
//                 printf("%c ", tablero[i][j]);  // Mostrar disparos acertados o fallidos
//             } else {
//                 printf("- ");  // Ocultar barcos (agua o lugares no disparados)
//             }
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// void iniciarJuego(char nombre[]) {
//     char tableroJugador[TAMANO_TABLERO][TAMANO_TABLERO];
//     char tableroPC[TAMANO_TABLERO][TAMANO_TABLERO];
//     int barcosHundidosJugador = 0, barcosHundidosPC = 0;
//     int barcosRestantesJugador = NUMERO_BARCOS, barcosRestantesPC = NUMERO_BARCOS;

//     inicializarTablero(tableroJugador);
//     inicializarTablero(tableroPC);

//     colocarBarcosJugador(tableroJugador);
//     colocarBarcosPC(tableroPC);

//     while (barcosHundidosJugador < NUMERO_BARCOS && barcosHundidosPC < NUMERO_BARCOS) {
//         printf("\n=== Tu turno ===\n");
//         mostrarTableroPC(tableroPC);  // Mostrar el tablero de la PC sin revelar sus barcos
//         turnoJugador(tableroPC, &barcosHundidosJugador, &barcosRestantesPC);

//         printf("\n=== Turno de la PC ===\n");
//         turnoPC(tableroJugador, &barcosHundidosPC, &barcosRestantesJugador);
//         mostrarTableroJugador(tableroJugador);  // Mostrar el tablero del jugador

//         // Mostrar el estado de los barcos restantes
//         printf("\nBarcos restantes: Jugador: %d, PC: %d\n", barcosRestantesJugador, barcosRestantesPC);
//         printf("Barcos hundidos: Jugador: %d, PC: %d\n", barcosHundidosJugador, barcosHundidosPC);
//     }

//     if (barcosHundidosJugador == NUMERO_BARCOS) {
//         printf("¡Felicidades, %s! Hundiste todos los barcos de la computadora.\n", nombre);
//     } else {
//         printf("¡Lo siento, %s! La computadora hundió todos tus barcos.\n", nombre);
//     }

//     mostrarRanking(barcosHundidosJugador, barcosHundidosPC, barcosRestantesJugador, barcosRestantesPC);
// }

// void turnoJugador(char tableroPC[TAMANO_TABLERO][TAMANO_TABLERO], int *barcosHundidos, int *barcosRestantes) {
//     int x, y;
//     do {
//         printf("Ingresa las coordenadas para disparar (x y): ");
//         scanf("%d %d", &x, &y);
//     } while (!validarCoordenadas(x, y) || !validarDisparo(tableroPC, x, y));  // Validar coordenadas y si ya se disparó

//     if (tableroPC[x][y] == 'B') {
//         printf("¡Tocado y hundido!\n");
//         tableroPC[x][y] = 'X';  // Barco hundido
//         (*barcosHundidos)++;
//         (*barcosRestantes)--;
//     } else {
//         printf("Fallaste.\n");
//         tableroPC[x][y] = 'O';  // Agua
//     }
// }

// void turnoPC(char tableroJugador[TAMANO_TABLERO][TAMANO_TABLERO], int *barcosHundidos, int *barcosRestantes) {
//     int x, y;
//     do {
//         x = rand() % TAMANO_TABLERO;
//         y = rand() % TAMANO_TABLERO;
//     } while (tableroJugador[x][y] == 'O' || tableroJugador[x][y] == 'X');  // Evitar disparar en lugares ya atacados

//     printf("La PC disparó en (%d, %d)\n", x, y);

//     if (tableroJugador[x][y] == 'B') {
//         printf("La PC ha hundido uno de tus barcos.\n");
//         tableroJugador[x][y] = 'X';
//         (*barcosHundidos)++;
//         (*barcosRestantes)--;
//     } else {
//         printf("La PC falló.\n");
//         tableroJugador[x][y] = 'O';
//     }
// }

// void mostrarRanking(int barcosHundidosJugador, int barcosHundidosPC, int barcosRestantesJugador, int barcosRestantesPC) {
//     printf("\n=== Ranking ===\n");
//     printf("Barcos hundidos por el jugador: %d\n", barcosHundidosJugador);
//     printf("Barcos hundidos por la PC: %d\n", barcosHundidosPC);
//     printf("Barcos restantes del jugador: %d\n", barcosRestantesJugador);
//     printf("Barcos restantes de la PC: %d\n", barcosRestantesPC);
// }

// int validarCoordenadas(int x, int y) {
//     return (x >= 0 && x < TAMANO_TABLERO && y >= 0 && y < TAMANO_TABLERO);
// }

// int validarDisparo(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], int x, int y) {
//     if (tablero[x][y] == 'O' || tablero[x][y] == 'X') {
//         printf("Ya disparaste en esa posición. Intenta nuevamente.\n");
//         return 0;
//     }
//     return 1;
// }


#include <stdio.h>
#include <string.h> 
#include <ctype.h>   

int verifyName(const char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isspace((unsigned char)name[i])) {
            return 0; //No es inválido si al menos un carácter no es espacio
        }
    }
    return 1; //Si todos los caracteres son espacios o la cadena está vacía
}

void requestName(char name[])
{
    printf("Enter your name: ");
    fgets(name, 50, stdin); //Guarda el nombre del jugador en name
    name[strcspn(name, "\n")] = '\0'; //Se elimina el salto de linea
    while (verifyName(name))
    {
        printf("Invalid name. It cannot be empty or only spaces. Please try again: ");
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = '\0';
    }
     
    printf("Hi %s! Welcome to Battleship.\n\n", name);
}

void showRules()
{
    printf("\n");
    printf("\n");
    printf("  ____          _    _    _          _____  _      _        \n");
    printf(" |  _ \\        | |  | |  | |        / ____|| |    (_)      \n");
    printf(" | |_) |  __ _ | |_ | |_ | |  ___  | (___  | |__   _  _ __  \n");
    printf(" |  _ <  / _` || __|| __|| | / _ \\  \\___ \\ | '_ \\ | || '_ \\ \n");
    printf(" | |_) || (_| || |_ | |_ | ||  __/  ____) || | | || || |_) |\n");
    printf(" |____/  \\__,_| \\__| \\__||_| \\___| |_____/ |_| |_||_|| .__/ \n");
    printf("                                                     | |    \n");
    printf("                                                     |_|    \n");
    printf("\n");
    printf("\n");

    printf("Rules:\n");
    printf("1. Place your ships on the board.\n");
    printf("2. Attempt to sink the computer's ships by shooting at the board.\n");
    printf("3. The game ends when one player sinks all the opponent's ships.\n");
    printf("=======================\n");
    printf("Let the battle begin!\n");
}

int main () {
    char nombreJugador[100];

    requestName(nombreJugador);
    showRules();
}