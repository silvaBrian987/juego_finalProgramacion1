#include <iostream>
#include "funciones.h"
using namespace std;

bool PERDIO = false;
bool GANO = false;

int POS_X_Y_SALIDA[] = { 45, 0 };

bool controlarFinJuego() {
	if (PERDIO) {
		limpiarPantalla();
		imprimirAPantalla("PERDISTE\n");
		return true;
	}else if(GANO){
		limpiarPantalla();
		imprimirAPantalla("GANASTE\n");
		return true;
	}
	return false;
}

void moverse() {
	POS_X = JUGADOR[0][0];
	POS_Y = JUGADOR[0][1];

	if (isUP) {
		POS_Y--;
	}
	else if (isDOWN) {
		POS_Y++;
	}
	else if (isRIGHT) {
		POS_X--;
	}
	else if (isLEFT) {
		POS_X++;
	}

	//Actualizo la posicion
	JUGADOR[0][0] = POS_X;
	JUGADOR[0][1] = POS_Y;
}

void dibujarParedVertical(int posX, int posInicio, int posFin) {
	for (int i = posInicio; i <= posFin; i++) {
		PANTALLA[i][posX] = PARED_CHAR;
	}
}

void dibujarParedHorizontal(int posY, int posInicio, int posFin) {
	for (int i = posInicio; i <= posFin; i++) {
		PANTALLA[posY][i] = PARED_CHAR;
	}
}

//Esto es para un mapa de 75x20
void dibujarLaberinto() {
	dibujarParedVertical(25, 5, 15);
	dibujarParedHorizontal(15, 25, 40);
	dibujarParedVertical(40, 5, 15);
	dibujarParedHorizontal(5, 25, 40);

	dibujarParedVertical(27, 7, 13);
	dibujarParedHorizontal(13, 27, 38);
	dibujarParedVertical(38, 7, 13);
	dibujarParedHorizontal(7, 27, 38);
}

void dibujarMapa() {
	//Paredes horizontales
	for (int i = 0; i < PANTALLA_WIDTH; i++) {
		PANTALLA[0][i] = PARED_CHAR;
		PANTALLA[PANTALLA_HEIGHT - 1][i] = PARED_CHAR;
	}

	//Paredes verticales
	for (int i = 0; i < PANTALLA_HEIGHT; i++) {
		PANTALLA[i][0] = PARED_CHAR;
		PANTALLA[i][PANTALLA_WIDTH - 1] = PARED_CHAR;
	}

	//Salida
	PANTALLA[POS_X_Y_SALIDA[1]][POS_X_Y_SALIDA[0]] = FONDO_CHAR;

	dibujarLaberinto();
}

void inicializarJugador() {
	for (int s = 0; s < JUGADOR_MAX_SIZE; s++) {
		for (int ss = 0; ss < 2; ss++) {
			JUGADOR[s][ss] = -1;
		}
	}

	//Posicion inicial
	JUGADOR[0][0] = POS_X;
	JUGADOR[0][1] = POS_Y;
}

void inicializarPantalla() {
	for (int h = 0; h < PANTALLA_HEIGHT; h++) {
		for (int w = 0; w < PANTALLA_WIDTH; w++) {
			PANTALLA[h][w] = FONDO_CHAR;
		}
	}
	dibujarMapa();
}

void refrescarPantalla() {
	limpiarPantalla();
	//imprimirAPantalla(("time = " + to_string(time(0)) + "\n").c_str());
	imprimirAPantalla(("(" + to_string(PANTALLA_WIDTH) + "," + to_string(PANTALLA_HEIGHT) + ") => (" + to_string(POS_X) + "," + to_string(POS_Y) + ")" + "\n").c_str());
	inicializarPantalla();
}

/*
void manejarColicion_bloquear(int& x, int& y) {
	if (y <= 1) y++;
	if (y == PANTALLA_HEIGHT - 1) y--;
	if (x <= 1) x++;
	if (x == PANTALLA_WIDTH - 1) x--;
}
*/

void manejarColicion_bloquear(int& x, int& y) {
	if (PANTALLA[y + 1][x] == PARED_CHAR) {

	}

	if (PANTALLA[y - 1][x] == PARED_CHAR) {

	}

	if (PANTALLA[y][x + 1] == PARED_CHAR) {

	}

	if (PANTALLA[y][x - 1] == PARED_CHAR) {

	}
}

void manejarColicion_portal(int& x, int& y) {
	if (y == 0) y = PANTALLA_HEIGHT - 2;
	if (y == PANTALLA_HEIGHT - 1) y = 1;
	if (x == 0) x = PANTALLA_WIDTH - 2;
	if (x == PANTALLA_WIDTH - 1) x = 1;
}

void manejarColicion_finJuego(int& x, int& y) {
	if (PANTALLA[y][x] == PARED_CHAR) {
		PERDIO = true;
	}

	if (x == POS_X_Y_SALIDA[0] && y == POS_X_Y_SALIDA[1]) {
		GANO = true;
	}
}

void manejarColicion() {
	int x = JUGADOR[0][0];
	int y = JUGADOR[0][1];

	/*
	if (PANTALLA[y - 1][x - 1] == PARED_CHAR) {
		//manejarColicion_portal(x,y);
		//manejarColicion_bloquear(x, y);
	}

	if (PANTALLA[y][x] == PARED_CHAR) {
		manejarColicion_bloquear(x, y);
	}
	*/

	manejarColicion_finJuego(x, y);

	JUGADOR[0][0] = x;
	JUGADOR[0][1] = y;
}
void actualizarJugadorPantalla() {
	int x = 0;
	int y = 0;

	for (int s = 0; s < JUGADOR_MAX_SIZE; s++) {
		x = JUGADOR[s][0];
		y = JUGADOR[s][1];
		if (y != -1 && x != -1) PANTALLA[y][x] = JUGADOR_CHAR;
	}
}

void dibujarPantalla() {
	refrescarPantalla();
	manejarColicion();
	actualizarJugadorPantalla();

	imprimirSaltoLinea();

	//string strScreen;

	for (int h = 0; h < PANTALLA_HEIGHT; h++) {
		for (int w = 0; w < PANTALLA_WIDTH; w++) {
			//strScreen.push_back(PANTALLA[h][w]);
			imprimirAPantalla(PANTALLA[h][w]);
		}
		//strScreen += "\n";
		imprimirSaltoLinea();
	}

	//Dibuja la pantalla
	//imprimirAPantalla(strScreen);
}

void iniciarJuego() {

	//Keycode
	int c;

	//Por ahi lo use para la aceleracion...
	int delta = 5;

	POS_X = (int)(PANTALLA_WIDTH / 2) - 1;
	POS_Y = (int)(PANTALLA_HEIGHT / 2) - 1;

	inicializarJugador();

	while (1) {
		if (controlarFinJuego()) {
			break;
		}

		c = leerTeclado();

		if (c == 27) {
			break;
		}

		if (c != 224) {
			switch (c) {
			case UP:
				moveUP();
				break;
			case DOWN:
				moveDOWN();
				break;
			case RIGHT:
				moveRIGHT();
				break;
			case LEFT:
				moveLEFT();
				break;
			default:
				moverse();
				break;
			}

			//Con esto manejo el refresco de la pantalla
			Sleep(VELOCIDAD_JUEGO);
			dibujarPantalla();
		}
	}

	imprimirAPantalla("\n\n\nFin de programa\n");
	system("pause");
}