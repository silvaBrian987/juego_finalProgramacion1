#include "funciones.h"

void moveUP(){
	isUP = true;
	isDOWN = false;
	isRIGHT = false;
	isLEFT = false;
}

void moveDOWN(){
	isUP = false;
	isDOWN = true;
	isRIGHT = false;
	isLEFT = false;
}

void moveRIGHT(){
	isUP = false;
	isDOWN = false;
	isRIGHT = true;
	isLEFT = false;
}

void moveLEFT(){
	isUP = false;
	isDOWN = false;
	isRIGHT = false;
	isLEFT = true;
}

void moverse(){
	if (isUP){
		POS_Y--;
	}
	else if (isDOWN){
		POS_Y++;
	}
	else if (isRIGHT){
		POS_X--;
	}
	else if (isLEFT){
		POS_X++;
	}

	//Actualizo la posicion
	SNAKE[0][0] = POS_Y;
	SNAKE[0][1] = POS_X;
}

void dibujarMapa(){
	//Paredes horizontales
	for (int i = 0; i < PANTALLA_WIDTH; i++){
		PANTALLA[0][i] = PARED_CHAR;
		PANTALLA[PANTALLA_HEIGHT - 1][i] = PARED_CHAR;
	}

	//Paredes verticales
	for (int i = 0; i < PANTALLA_HEIGHT; i++){
		PANTALLA[i][0] = PARED_CHAR;
		PANTALLA[i][PANTALLA_WIDTH - 1] = PARED_CHAR;
	}
}

void inicializarSerpiente(){
	for (int s = 0; s < SNAKE_MAX_SIZE; s++){
		for (int ss = 0; ss < 2; ss++){
			SNAKE[s][ss] = -1;
		}
	}

	//Posicion inicial
	SNAKE[0][0] = POS_Y;
	SNAKE[0][1] = POS_X;
}

void inicializarPantalla(){
	for (int h = 0; h < PANTALLA_HEIGHT; h++){
		for (int w = 0; w < PANTALLA_WIDTH; w++){
			PANTALLA[h][w] = '_';
		}
	}
	dibujarMapa();
}

void refrescarPantalla(){
	limpiarPantalla();
	imprimirAPantalla("time = " + to_string(time(0)) + "\n");
	imprimirAPantalla("(" + to_string(PANTALLA_WIDTH) + "," + to_string(PANTALLA_HEIGHT) + ") => (" + to_string(POS_X) + "," + to_string(POS_Y) + ")" + "\n");
	inicializarPantalla();
}

void manejarColicion_bloquear(){
	if (POS_Y == 0) POS_Y++;
	if (POS_Y == PANTALLA_HEIGHT - 1) POS_Y--;
	if (POS_X == 0) POS_X++;
	if (POS_X == PANTALLA_WIDTH - 1) POS_X--;
}

void manejarColicion_portal(){
	if (POS_Y == 0) POS_Y = PANTALLA_HEIGHT - 2;
	if (POS_Y == PANTALLA_HEIGHT - 1) POS_Y = 1;
	if (POS_X == 0) POS_X = PANTALLA_WIDTH - 2;
	if (POS_X == PANTALLA_WIDTH - 1) POS_X = 1;
}

void manejarColicion(){
	if (PANTALLA[POS_Y - 1][POS_X - 1] == PARED_CHAR){
		//cout << "ESTAS POR CHOCAR, WACHIN" << endl;
	}

	if (PANTALLA[POS_Y][POS_X] == PARED_CHAR){
		manejarColicion_portal();
		//manejarColicion_bloquear();
	}
}

void actualizarSerpientePantalla(){
	int x = 0;
	int y = 0;

	for (int s = 0; s < SNAKE_MAX_SIZE; s++){
		y = SNAKE[s][0];
		x = SNAKE[s][1];
		if (y != -1 && x != -1) PANTALLA[y][x] = SNAKE_CHAR;
	}
}

void dibujarPantalla(){
	refrescarPantalla();
	manejarColicion();

	imprimirSaltoLinea();

	actualizarSerpientePantalla();
	string strScreen;

	for (int h = 0; h < PANTALLA_HEIGHT; h++){
		for (int w = 0; w < PANTALLA_WIDTH; w++){
			strScreen.push_back(PANTALLA[h][w]);
		}
		strScreen += "\n";
	}

	//Dibuja la pantalla
	imprimirAPantalla(strScreen);
}
void iniciarJuego(){

	//Keycode
	int c;

	//Por ahi lo use para la aceleracion...
	int delta = 5;

	POS_X = (int)(PANTALLA_WIDTH / 2) - 1;
	POS_Y = (int)(PANTALLA_HEIGHT / 2) - 1;

	inicializarSerpiente();

	while (1){
		c = leerTeclado();

		if (c == 27){
			break;
		}

		if (c != 224){
			switch (c){
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

			dibujarPantalla();
		}
	}

	imprimirAPantalla("Fin de programa\n");
}