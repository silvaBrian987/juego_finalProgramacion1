#include <string>
#include <time.h>
#include <curses.h>
#include "funciones.h"

using namespace std;

void moverse(){
	POS_X = SNAKE[0][0];
	POS_Y = SNAKE[0][1];

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
	SNAKE[0][0] = POS_X;
	SNAKE[0][1] = POS_Y;
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
	SNAKE[0][0] = POS_X;
	SNAKE[0][1] = POS_Y;
}

void inicializarPantalla(){
	for (int h = 0; h < PANTALLA_HEIGHT; h++){
		for (int w = 0; w < PANTALLA_WIDTH; w++){
			PANTALLA[h][w] = FONDO_CHAR;
		}
	}
	dibujarMapa();
}

void refrescarPantalla(){
	clear();
	addstr(("time = " + to_string(time(0)) + "\n").c_str());
	addstr(("(" + to_string(PANTALLA_WIDTH) + "," + to_string(PANTALLA_HEIGHT) + ") => (" + to_string(POS_X) + "," + to_string(POS_Y) + ")" + "\n").c_str());
	refresh();
	inicializarPantalla();
}

void manejarColicion_bloquear(int x, int y){
	if (y < 2) y++;
	if (y == PANTALLA_HEIGHT - 1) y--;
	if (x < 2) x++;
	if (x == PANTALLA_WIDTH - 1) x--;
}

void manejarColicion_portal(int x, int y){
	if (y == 0) y = PANTALLA_HEIGHT - 2;
	if (y == PANTALLA_HEIGHT - 1) y = 1;
	if (x == 0) x = PANTALLA_WIDTH - 2;
	if (x == PANTALLA_WIDTH - 1) x = 1;
}

void manejarColicion(){
	int x = SNAKE[0][0];
	int y = SNAKE[0][1];

	if (PANTALLA[y - 1][x - 1] == PARED_CHAR){
		//cout << "ESTAS POR CHOCAR, WACHIN" << endl;
	}

	if (PANTALLA[y][x] == PARED_CHAR){
		//manejarColicion_portal(x,y);
		manejarColicion_bloquear(x,y);
	}

	SNAKE[0][0] = x;
	SNAKE[0][1] = y;
}

void actualizarSerpientePantalla(){
	int x = 0;
	int y = 0;

	for (int s = 0; s < SNAKE_MAX_SIZE; s++){
		x = SNAKE[s][0];
		y = SNAKE[s][1];
		if (y != -1 && x != -1) PANTALLA[y][x] = SNAKE_CHAR;
	}
}

void dibujarPantalla(){
	refrescarPantalla();
	actualizarSerpientePantalla();
	manejarColicion();

	addch('\n');

	string strScreen;

	for (int h = 0; h < PANTALLA_HEIGHT; h++){
		for (int w = 0; w < PANTALLA_WIDTH; w++){
			strScreen.push_back(PANTALLA[h][w]);
			//printw(PANTALLA[h][w]);
			addch(PANTALLA[h][w]);
		}
		//strScreen += "\n";
		addch('\n');
	}

	//Dibuja la pantalla
	//addstr(strScreen.c_str());
	//mvaddch(POS_X, POS_Y, SNAKE_CHAR);
	refresh();
}

void iniciarJuego(){
	//Inicia ncurses
	initscr();

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
			//for (long i = 0; i < 100000000; i++){}
			Sleep(150);
			dibujarPantalla();
		}
	}

	addstr("Fin de programa\n");
	refresh();
	endwin();
}