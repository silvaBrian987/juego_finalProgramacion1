#include <iostream>
#include "funciones.h"
using namespace std;

#define PANTALLA_HEIGHT 20
#define PANTALLA_WIDTH 75

char PANTALLA[PANTALLA_HEIGHT][PANTALLA_WIDTH];
int POS_X = 0;
int POS_Y = 0;

bool esArriba = true;
bool esDerecha = true;

void dibujarMapa(){
	//Paredes horizontales
	for (int i = 0; i < PANTALLA_WIDTH; i++){
		PANTALLA[0][i] = 'A';
		PANTALLA[PANTALLA_HEIGHT - 1][i] = 'A';
	}

	//Paredes verticales
	for (int i = 0; i < PANTALLA_HEIGHT; i++){
		PANTALLA[i][0] = 'A';
		PANTALLA[i][PANTALLA_WIDTH - 1] = 'A';
	}
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
	system("CLS");
	//ClearScreen();
	//RedrawWindow(NULL, NULL, NULL, NULL);
	//limpiarPantalla();
	cout << "(" << PANTALLA_WIDTH << "," << PANTALLA_HEIGHT << ") => (" << POS_X << "," << POS_Y << ")" << endl;
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
	if (PANTALLA[POS_Y - 1][POS_X - 1] == 'A'){
		//limpiarPantalla();
		//cout << "ESTAS POR CHOCAR, WACHIN" << endl;
	}

	if (PANTALLA[POS_Y][POS_X] == 'A'){
		//limpiarPantalla();
		//cout << "VO' SO' BOLUDO? TE DIJE QUE TE IBAS A CHOCAR" << endl;
		//manejarColicion_portal();
		manejarColicion_bloquear();
	}
}

void *dibujarPantalla(void *arg){
	refrescarPantalla();
	//cout << "arg = " << (long) arg << endl;
	manejarColicion();

	cout << endl;

	PANTALLA[POS_Y][POS_X] = '*';

	for (int h = 0; h < PANTALLA_HEIGHT; h++){
		for (int w = 0; w < PANTALLA_WIDTH; w++){
			cout << PANTALLA[h][w];
		}
		cout << endl;
	}

	return NULL;
}

void iniciarJuego(){
	//Objeto Multihilos
	/*
	pthread_t pth;
	pthread_create(&pth, NULL, dibujarPantalla, (void *) "1");
	*/

	//Keycode
	int c;

	//Por ahi lo use para la aceleracion...
	int delta = 5;

	POS_X = (int)(PANTALLA_WIDTH / 2) - 1;
	POS_Y = (int)PANTALLA_HEIGHT - 5;

	//inicializarPantalla();

	while (1){
		c = _getch();
		//cout << "keycode = " << c << endl;

		if (c == 27){
			break;
		}

		if (c != 224){
			switch (c){
			case UP:
				POS_Y--;
				//POS_Y < 0 ? POS_Y = PANTALLA_HEIGHT - 2 : POS_Y = POS_Y;
				break;
			case DOWN:
				POS_Y++;
				//POS_Y >= PANTALLA_HEIGHT -1 ? POS_Y = PANTALLA_HEIGHT - 2 : POS_Y = POS_Y;
				break;
			case RIGHT:
				POS_X--;
				//POS_X < 0 ? POS_X = PANTALLA_WIDTH - 2 : POS_X = POS_X;
				break;
			case LEFT:
				POS_X++;
				//POS_X >= PANTALLA_WIDTH - 1 ? POS_X = PANTALLA_WIDTH - 2 : POS_X = POS_X;
				break;
			default:
				//cout << "Gil, que es esto?" << endl;
				break;
			}

			dibujarPantalla(NULL);
		}
	}

	cout << "Fin de programa" << endl;
}