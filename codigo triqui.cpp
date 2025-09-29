#include <iostream>  
using namespace std;

int main() {
    char triqui[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char jugador1 = 'X';
    char jugador2 = 'O';
    int turno = 1;   
    int ganador = 0;
    int jugadas = 0;
    int posicion, fila, columna;
    char ficha;

    // Si empata o gana
    while (jugadas < 9 && ganador == 0) {
        // Mostrar tablero
        cout << "Tablero:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << triqui[i][j] << " ";
            }
            cout << endl;
        }

        // Turno y ficha (X,O)
        if (turno == 1) {
            ficha = jugador1;
            cout << "Turno del Jugador 1 (" << jugador1 << ")\n";
        } else {
            ficha = jugador2;
            cout << "Turno del Jugador 2 (" << jugador2 << ")\n";
        }

        // Pedir jugada
        cout << "Ingrese posicion (1-9): ";
        cin >> posicion;

        // movimiento fuera del rango 
        if (posicion < 1 || posicion > 9) {
            cout << "toca estrenar el cerebro, lea.\n";
            continue;
        }

        // Convertir a fila y columna 
        int contador = 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (contador == posicion) {
                    fila = i;
                    columna = j;
                }
                contador++;
            }
        }

        // casilla libre (ahora se chequea que no sea X u O)
        if (triqui[fila][columna] == 'X' || triqui[fila][columna] == 'O') {
            cout << "por desconcentrado es que pierden el pelo.\n";
            continue;
        }

        // Colocar ficha
        triqui[fila][columna] = ficha;
        jugadas++;

        // condicion para ganar 
        for (int i = 0; i < 3; i++) { 
            if (triqui[0][0]==ficha && triqui[0][1]==ficha && triqui[0][2]==ficha) ganador = turno;
            if (triqui[1][0]==ficha && triqui[1][1]==ficha && triqui[1][2]==ficha) ganador = turno;
            if (triqui[2][0]==ficha && triqui[2][1]==ficha && triqui[2][2]==ficha) ganador = turno;
            if (triqui[0][0]==ficha && triqui[1][0]==ficha && triqui[2][0]==ficha) ganador = turno;
            if (triqui[0][1]==ficha && triqui[1][1]==ficha && triqui[2][1]==ficha) ganador = turno;
            if (triqui[0][2]==ficha && triqui[1][2]==ficha && triqui[2][2]==ficha) ganador = turno;
        }
        if (triqui[0][0]==ficha && triqui[1][1]==ficha && triqui[2][2]==ficha) ganador = turno;
        if (triqui[0][2]==ficha && triqui[1][1]==ficha && triqui[2][0]==ficha) ganador = turno;

        // Cambiar turno solo si no hay ganador
        if (ganador == 0) {
            if (turno == 1) turno = 2;
            else turno = 1;
        }
    }

    // Mostrar resultado final
    if (ganador == 1) {
        cout << "Jugador 1 (" << jugador1 << ") gana!\n";
    } else if (ganador == 2) {
        cout << "Jugador 2 (" << jugador2 << ") gana!\n";
    } else {
        cout << "felicitaciones mochos, ninguno gano.\n";
    }
 
    return 0;
}
