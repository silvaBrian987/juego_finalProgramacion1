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
	/*
	dibujarParedVertical(25, 5, 15);
	dibujarParedHorizontal(15, 25, 40);
	dibujarParedVertical(40, 5, 15);
	dibujarParedHorizontal(5, 25, 40);

	dibujarParedVertical(27, 7, 13);
	dibujarParedHorizontal(13, 27, 38);
	dibujarParedVertical(38, 7, 13);
	dibujarParedHorizontal(7, 27, 38);
	*/
	PANTALLA[0][0] = '*'; PANTALLA[0][1] = '*'; PANTALLA[0][2] = '*'; PANTALLA[0][3] = '*'; PANTALLA[0][4] = '*'; PANTALLA[0][5] = '*'; PANTALLA[0][6] = '*'; PANTALLA[0][7] = '*'; PANTALLA[0][8] = '*'; PANTALLA[0][9] = '*'; PANTALLA[0][10] = '*'; PANTALLA[0][11] = '*'; PANTALLA[0][12] = '*'; PANTALLA[0][13] = '*'; PANTALLA[0][14] = '*'; PANTALLA[0][15] = '*'; PANTALLA[0][16] = '*'; PANTALLA[0][17] = '*'; PANTALLA[0][18] = '*'; PANTALLA[0][19] = '*'; PANTALLA[0][20] = '*'; PANTALLA[0][21] = '*'; PANTALLA[0][22] = '*'; PANTALLA[0][23] = '*'; PANTALLA[0][24] = '*'; PANTALLA[0][25] = '*'; PANTALLA[0][26] = '*'; PANTALLA[0][27] = '*'; PANTALLA[0][28] = '*'; PANTALLA[0][29] = '*'; PANTALLA[0][30] = '*'; PANTALLA[0][31] = '*'; PANTALLA[0][32] = '*'; PANTALLA[0][33] = '*'; PANTALLA[0][34] = '*'; PANTALLA[0][35] = '*'; PANTALLA[0][36] = '*'; PANTALLA[0][37] = '*'; PANTALLA[0][38] = '*'; PANTALLA[0][39] = '*'; PANTALLA[0][40] = '*'; PANTALLA[0][41] = '*'; PANTALLA[0][42] = '*'; PANTALLA[0][43] = '*'; PANTALLA[0][44] = '*'; PANTALLA[0][45] = '_'; PANTALLA[0][46] = '*'; PANTALLA[0][47] = '*'; PANTALLA[0][48] = '*'; PANTALLA[0][49] = '*'; PANTALLA[0][50] = '*'; PANTALLA[0][51] = '*'; PANTALLA[0][52] = '*'; PANTALLA[0][53] = '*'; PANTALLA[0][54] = '*'; PANTALLA[0][55] = '*'; PANTALLA[0][56] = '*'; PANTALLA[0][57] = '*'; PANTALLA[0][58] = '*'; PANTALLA[0][59] = '*'; PANTALLA[0][60] = '*'; PANTALLA[0][61] = '*'; PANTALLA[0][62] = '*'; PANTALLA[0][63] = '*'; PANTALLA[0][64] = '*'; PANTALLA[0][65] = '*'; PANTALLA[0][66] = '*'; PANTALLA[0][67] = '*'; PANTALLA[0][68] = '*'; PANTALLA[0][69] = '*'; PANTALLA[0][70] = '*'; PANTALLA[0][71] = '*'; PANTALLA[0][72] = '*'; PANTALLA[0][73] = '*'; PANTALLA[0][74] = '*'; PANTALLA[1][0] = '*'; PANTALLA[1][1] = '_'; PANTALLA[1][2] = '_'; PANTALLA[1][3] = '_'; PANTALLA[1][4] = '*'; PANTALLA[1][5] = '*'; PANTALLA[1][6] = '*'; PANTALLA[1][7] = '*'; PANTALLA[1][8] = '*'; PANTALLA[1][9] = '*'; PANTALLA[1][10] = '*'; PANTALLA[1][11] = '*'; PANTALLA[1][12] = '*'; PANTALLA[1][13] = '*'; PANTALLA[1][14] = '*'; PANTALLA[1][15] = '*'; PANTALLA[1][16] = '*'; PANTALLA[1][17] = '*'; PANTALLA[1][18] = '*'; PANTALLA[1][19] = '*'; PANTALLA[1][20] = '*'; PANTALLA[1][21] = '*'; PANTALLA[1][22] = '*'; PANTALLA[1][23] = '*'; PANTALLA[1][24] = '_'; PANTALLA[1][25] = '_'; PANTALLA[1][26] = '_'; PANTALLA[1][27] = '_'; PANTALLA[1][28] = '*'; PANTALLA[1][29] = '*'; PANTALLA[1][30] = '*'; PANTALLA[1][31] = '*'; PANTALLA[1][32] = '*'; PANTALLA[1][33] = '*'; PANTALLA[1][34] = '*'; PANTALLA[1][35] = '*'; PANTALLA[1][36] = '*'; PANTALLA[1][37] = '*'; PANTALLA[1][38] = '*'; PANTALLA[1][39] = '*'; PANTALLA[1][40] = '*'; PANTALLA[1][41] = '*'; PANTALLA[1][42] = '*'; PANTALLA[1][43] = '*'; PANTALLA[1][44] = '*'; PANTALLA[1][45] = '_'; PANTALLA[1][46] = '*'; PANTALLA[1][47] = '*'; PANTALLA[1][48] = '*'; PANTALLA[1][49] = '*'; PANTALLA[1][50] = '*'; PANTALLA[1][51] = '*'; PANTALLA[1][52] = '*'; PANTALLA[1][53] = '*'; PANTALLA[1][54] = '*'; PANTALLA[1][55] = '*'; PANTALLA[1][56] = '*'; PANTALLA[1][57] = '*'; PANTALLA[1][58] = '*'; PANTALLA[1][59] = '*'; PANTALLA[1][60] = '*'; PANTALLA[1][61] = '*'; PANTALLA[1][62] = '*'; PANTALLA[1][63] = '*'; PANTALLA[1][64] = '*'; PANTALLA[1][65] = '*'; PANTALLA[1][66] = '*'; PANTALLA[1][67] = '*'; PANTALLA[1][68] = '*'; PANTALLA[1][69] = '*'; PANTALLA[1][70] = '*'; PANTALLA[1][71] = '*'; PANTALLA[1][72] = '*'; PANTALLA[1][73] = '*'; PANTALLA[1][74] = '*'; PANTALLA[2][0] = '*'; PANTALLA[2][1] = '_'; PANTALLA[2][2] = '_'; PANTALLA[2][3] = '_'; PANTALLA[2][4] = '*'; PANTALLA[2][5] = '*'; PANTALLA[2][6] = '*'; PANTALLA[2][7] = '*'; PANTALLA[2][8] = '*'; PANTALLA[2][9] = '*'; PANTALLA[2][10] = '*'; PANTALLA[2][11] = '*'; PANTALLA[2][12] = '*'; PANTALLA[2][13] = '*'; PANTALLA[2][14] = '*'; PANTALLA[2][15] = '*'; PANTALLA[2][16] = '*'; PANTALLA[2][17] = '*'; PANTALLA[2][18] = '*'; PANTALLA[2][19] = '*'; PANTALLA[2][20] = '*'; PANTALLA[2][21] = '*'; PANTALLA[2][22] = '*'; PANTALLA[2][23] = '*'; PANTALLA[2][24] = '_'; PANTALLA[2][25] = '*'; PANTALLA[2][26] = '*'; PANTALLA[2][27] = '_'; PANTALLA[2][28] = '*'; PANTALLA[2][29] = '*'; PANTALLA[2][30] = '*'; PANTALLA[2][31] = '*'; PANTALLA[2][32] = '*'; PANTALLA[2][33] = '*'; PANTALLA[2][34] = '*'; PANTALLA[2][35] = '*'; PANTALLA[2][36] = '_'; PANTALLA[2][37] = '_'; PANTALLA[2][38] = '_'; PANTALLA[2][39] = '_'; PANTALLA[2][40] = '_'; PANTALLA[2][41] = '_'; PANTALLA[2][42] = '_'; PANTALLA[2][43] = '_'; PANTALLA[2][44] = '*'; PANTALLA[2][45] = '_'; PANTALLA[2][46] = '*'; PANTALLA[2][47] = '*'; PANTALLA[2][48] = '*'; PANTALLA[2][49] = '*'; PANTALLA[2][50] = '*'; PANTALLA[2][51] = '*'; PANTALLA[2][52] = '*'; PANTALLA[2][53] = '*'; PANTALLA[2][54] = '_'; PANTALLA[2][55] = '_'; PANTALLA[2][56] = '_'; PANTALLA[2][57] = '_'; PANTALLA[2][58] = '_'; PANTALLA[2][59] = '_'; PANTALLA[2][60] = '_'; PANTALLA[2][61] = '_'; PANTALLA[2][62] = '_'; PANTALLA[2][63] = '_'; PANTALLA[2][64] = '_'; PANTALLA[2][65] = '_'; PANTALLA[2][66] = '*'; PANTALLA[2][67] = '*'; PANTALLA[2][68] = '*'; PANTALLA[2][69] = '*'; PANTALLA[2][70] = '*'; PANTALLA[2][71] = '*'; PANTALLA[2][72] = '*'; PANTALLA[2][73] = '*'; PANTALLA[2][74] = '*'; PANTALLA[3][0] = '*'; PANTALLA[3][1] = '_'; PANTALLA[3][2] = '_'; PANTALLA[3][3] = '_'; PANTALLA[3][4] = '_'; PANTALLA[3][5] = '_'; PANTALLA[3][6] = '_'; PANTALLA[3][7] = '_'; PANTALLA[3][8] = '_'; PANTALLA[3][9] = '_'; PANTALLA[3][10] = '_'; PANTALLA[3][11] = '_'; PANTALLA[3][12] = '_'; PANTALLA[3][13] = '_'; PANTALLA[3][14] = '_'; PANTALLA[3][15] = '_'; PANTALLA[3][16] = '_'; PANTALLA[3][17] = '_'; PANTALLA[3][18] = '_'; PANTALLA[3][19] = '_'; PANTALLA[3][20] = '_'; PANTALLA[3][21] = '_'; PANTALLA[3][22] = '_'; PANTALLA[3][23] = '*'; PANTALLA[3][24] = '_'; PANTALLA[3][25] = '*'; PANTALLA[3][26] = '*'; PANTALLA[3][27] = '_'; PANTALLA[3][28] = '*'; PANTALLA[3][29] = '_'; PANTALLA[3][30] = '_'; PANTALLA[3][31] = '_'; PANTALLA[3][32] = '_'; PANTALLA[3][33] = '_'; PANTALLA[3][34] = '_'; PANTALLA[3][35] = '_'; PANTALLA[3][36] = '_'; PANTALLA[3][37] = '*'; PANTALLA[3][38] = '*'; PANTALLA[3][39] = '*'; PANTALLA[3][40] = '*'; PANTALLA[3][41] = '*'; PANTALLA[3][42] = '*'; PANTALLA[3][43] = '*'; PANTALLA[3][44] = '*'; PANTALLA[3][45] = '_'; PANTALLA[3][46] = '*'; PANTALLA[3][47] = '*'; PANTALLA[3][48] = '*'; PANTALLA[3][49] = '*'; PANTALLA[3][50] = '*'; PANTALLA[3][51] = '*'; PANTALLA[3][52] = '*'; PANTALLA[3][53] = '*'; PANTALLA[3][54] = '_'; PANTALLA[3][55] = '*'; PANTALLA[3][56] = '*'; PANTALLA[3][57] = '*'; PANTALLA[3][58] = '*'; PANTALLA[3][59] = '*'; PANTALLA[3][60] = '*'; PANTALLA[3][61] = '*'; PANTALLA[3][62] = '*'; PANTALLA[3][63] = '*'; PANTALLA[3][64] = '*'; PANTALLA[3][65] = '_'; PANTALLA[3][66] = '*'; PANTALLA[3][67] = '*'; PANTALLA[3][68] = '*'; PANTALLA[3][69] = '*'; PANTALLA[3][70] = '*'; PANTALLA[3][71] = '*'; PANTALLA[3][72] = '*'; PANTALLA[3][73] = '*'; PANTALLA[3][74] = '*'; PANTALLA[4][0] = '*'; PANTALLA[4][1] = '*'; PANTALLA[4][2] = '*'; PANTALLA[4][3] = '_'; PANTALLA[4][4] = '*'; PANTALLA[4][5] = '*'; PANTALLA[4][6] = '*'; PANTALLA[4][7] = '*'; PANTALLA[4][8] = '_'; PANTALLA[4][9] = '*'; PANTALLA[4][10] = '*'; PANTALLA[4][11] = '*'; PANTALLA[4][12] = '_'; PANTALLA[4][13] = '*'; PANTALLA[4][14] = '*'; PANTALLA[4][15] = '*'; PANTALLA[4][16] = '*'; PANTALLA[4][17] = '*'; PANTALLA[4][18] = '*'; PANTALLA[4][19] = '_'; PANTALLA[4][20] = '*'; PANTALLA[4][21] = '*'; PANTALLA[4][22] = '*'; PANTALLA[4][23] = '*'; PANTALLA[4][24] = '_'; PANTALLA[4][25] = '*'; PANTALLA[4][26] = '*'; PANTALLA[4][27] = '_'; PANTALLA[4][28] = '*'; PANTALLA[4][29] = '*'; PANTALLA[4][30] = '*'; PANTALLA[4][31] = '*'; PANTALLA[4][32] = '*'; PANTALLA[4][33] = '*'; PANTALLA[4][34] = '*'; PANTALLA[4][35] = '*'; PANTALLA[4][36] = '_'; PANTALLA[4][37] = '*'; PANTALLA[4][38] = '*'; PANTALLA[4][39] = '*'; PANTALLA[4][40] = '*'; PANTALLA[4][41] = '*'; PANTALLA[4][42] = '*'; PANTALLA[4][43] = '*'; PANTALLA[4][44] = '*'; PANTALLA[4][45] = '_'; PANTALLA[4][46] = '_'; PANTALLA[4][47] = '_'; PANTALLA[4][48] = '_'; PANTALLA[4][49] = '_'; PANTALLA[4][50] = '_'; PANTALLA[4][51] = '_'; PANTALLA[4][52] = '_'; PANTALLA[4][53] = '*'; PANTALLA[4][54] = '*'; PANTALLA[4][55] = '*'; PANTALLA[4][56] = '*'; PANTALLA[4][57] = '*'; PANTALLA[4][58] = '*'; PANTALLA[4][59] = '*'; PANTALLA[4][60] = '*'; PANTALLA[4][61] = '*'; PANTALLA[4][62] = '*'; PANTALLA[4][63] = '*'; PANTALLA[4][64] = '*'; PANTALLA[4][65] = '_'; PANTALLA[4][66] = '*'; PANTALLA[4][67] = '*'; PANTALLA[4][68] = '*'; PANTALLA[4][69] = '*'; PANTALLA[4][70] = '*'; PANTALLA[4][71] = '*'; PANTALLA[4][72] = '*'; PANTALLA[4][73] = '*'; PANTALLA[4][74] = '*'; PANTALLA[5][0] = '*'; PANTALLA[5][1] = '*'; PANTALLA[5][2] = '*'; PANTALLA[5][3] = '_'; PANTALLA[5][4] = '*'; PANTALLA[5][5] = '*'; PANTALLA[5][6] = '*'; PANTALLA[5][7] = '*'; PANTALLA[5][8] = '_'; PANTALLA[5][9] = '*'; PANTALLA[5][10] = '*'; PANTALLA[5][11] = '*'; PANTALLA[5][12] = '_'; PANTALLA[5][13] = '*'; PANTALLA[5][14] = '*'; PANTALLA[5][15] = '*'; PANTALLA[5][16] = '*'; PANTALLA[5][17] = '*'; PANTALLA[5][18] = '*'; PANTALLA[5][19] = '_'; PANTALLA[5][20] = '*'; PANTALLA[5][21] = '*'; PANTALLA[5][22] = '*'; PANTALLA[5][23] = '*'; PANTALLA[5][24] = '_'; PANTALLA[5][25] = '*'; PANTALLA[5][26] = '*'; PANTALLA[5][27] = '_'; PANTALLA[5][28] = '*'; PANTALLA[5][29] = '_'; PANTALLA[5][30] = '_'; PANTALLA[5][31] = '_'; PANTALLA[5][32] = '_'; PANTALLA[5][33] = '_'; PANTALLA[5][34] = '_'; PANTALLA[5][35] = '_'; PANTALLA[5][36] = '_'; PANTALLA[5][37] = '*'; PANTALLA[5][38] = '*'; PANTALLA[5][39] = '*'; PANTALLA[5][40] = '*'; PANTALLA[5][41] = '*'; PANTALLA[5][42] = '*'; PANTALLA[5][43] = '*'; PANTALLA[5][44] = '*'; PANTALLA[5][45] = '*'; PANTALLA[5][46] = '*'; PANTALLA[5][47] = '*'; PANTALLA[5][48] = '*'; PANTALLA[5][49] = '*'; PANTALLA[5][50] = '*'; PANTALLA[5][51] = '*'; PANTALLA[5][52] = '_'; PANTALLA[5][53] = '_'; PANTALLA[5][54] = '_'; PANTALLA[5][55] = '_'; PANTALLA[5][56] = '_'; PANTALLA[5][57] = '_'; PANTALLA[5][58] = '_'; PANTALLA[5][59] = '_'; PANTALLA[5][60] = '_'; PANTALLA[5][61] = '_'; PANTALLA[5][62] = '_'; PANTALLA[5][63] = '_'; PANTALLA[5][64] = '_'; PANTALLA[5][65] = '_'; PANTALLA[5][66] = '_'; PANTALLA[5][67] = '_'; PANTALLA[5][68] = '_'; PANTALLA[5][69] = '_'; PANTALLA[5][70] = '_'; PANTALLA[5][71] = '_'; PANTALLA[5][72] = '_'; PANTALLA[5][73] = '*'; PANTALLA[5][74] = '*'; PANTALLA[6][0] = '*'; PANTALLA[6][1] = '*'; PANTALLA[6][2] = '*'; PANTALLA[6][3] = '_'; PANTALLA[6][4] = '*'; PANTALLA[6][5] = '*'; PANTALLA[6][6] = '*'; PANTALLA[6][7] = '*'; PANTALLA[6][8] = '_'; PANTALLA[6][9] = '*'; PANTALLA[6][10] = '*'; PANTALLA[6][11] = '*'; PANTALLA[6][12] = '_'; PANTALLA[6][13] = '*'; PANTALLA[6][14] = '*'; PANTALLA[6][15] = '_'; PANTALLA[6][16] = '_'; PANTALLA[6][17] = '_'; PANTALLA[6][18] = '_'; PANTALLA[6][19] = '_'; PANTALLA[6][20] = '_'; PANTALLA[6][21] = '_'; PANTALLA[6][22] = '_'; PANTALLA[6][23] = '*'; PANTALLA[6][24] = '_'; PANTALLA[6][25] = '*'; PANTALLA[6][26] = '*'; PANTALLA[6][27] = '_'; PANTALLA[6][28] = '*'; PANTALLA[6][29] = '*'; PANTALLA[6][30] = '*'; PANTALLA[6][31] = '*'; PANTALLA[6][32] = '*'; PANTALLA[6][33] = '*'; PANTALLA[6][34] = '*'; PANTALLA[6][35] = '*'; PANTALLA[6][36] = '_'; PANTALLA[6][37] = '*'; PANTALLA[6][38] = '*'; PANTALLA[6][39] = '*'; PANTALLA[6][40] = '*'; PANTALLA[6][41] = '_'; PANTALLA[6][42] = '_'; PANTALLA[6][43] = '_'; PANTALLA[6][44] = '_'; PANTALLA[6][45] = '_'; PANTALLA[6][46] = '_'; PANTALLA[6][47] = '_'; PANTALLA[6][48] = '_'; PANTALLA[6][49] = '_'; PANTALLA[6][50] = '_'; PANTALLA[6][51] = '*'; PANTALLA[6][52] = '*'; PANTALLA[6][53] = '*'; PANTALLA[6][54] = '*'; PANTALLA[6][55] = '*'; PANTALLA[6][56] = '*'; PANTALLA[6][57] = '*'; PANTALLA[6][58] = '*'; PANTALLA[6][59] = '*'; PANTALLA[6][60] = '*'; PANTALLA[6][61] = '*'; PANTALLA[6][62] = '*'; PANTALLA[6][63] = '*'; PANTALLA[6][64] = '*'; PANTALLA[6][65] = '*'; PANTALLA[6][66] = '*'; PANTALLA[6][67] = '*'; PANTALLA[6][68] = '*'; PANTALLA[6][69] = '*'; PANTALLA[6][70] = '*'; PANTALLA[6][71] = '*'; PANTALLA[6][72] = '_'; PANTALLA[6][73] = '*'; PANTALLA[6][74] = '*'; PANTALLA[7][0] = '*'; PANTALLA[7][1] = '*'; PANTALLA[7][2] = '*'; PANTALLA[7][3] = '_'; PANTALLA[7][4] = '*'; PANTALLA[7][5] = '*'; PANTALLA[7][6] = '*'; PANTALLA[7][7] = '*'; PANTALLA[7][8] = '_'; PANTALLA[7][9] = '*'; PANTALLA[7][10] = '*'; PANTALLA[7][11] = '*'; PANTALLA[7][12] = '_'; PANTALLA[7][13] = '*'; PANTALLA[7][14] = '*'; PANTALLA[7][15] = '_'; PANTALLA[7][16] = '*'; PANTALLA[7][17] = '*'; PANTALLA[7][18] = '*'; PANTALLA[7][19] = '*'; PANTALLA[7][20] = '*'; PANTALLA[7][21] = '*'; PANTALLA[7][22] = '*'; PANTALLA[7][23] = '*'; PANTALLA[7][24] = '_'; PANTALLA[7][25] = '*'; PANTALLA[7][26] = '*'; PANTALLA[7][27] = '_'; PANTALLA[7][28] = '_'; PANTALLA[7][29] = '_'; PANTALLA[7][30] = '_'; PANTALLA[7][31] = '_'; PANTALLA[7][32] = '*'; PANTALLA[7][33] = '*'; PANTALLA[7][34] = '*'; PANTALLA[7][35] = '*'; PANTALLA[7][36] = '_'; PANTALLA[7][37] = '*'; PANTALLA[7][38] = '*'; PANTALLA[7][39] = '*'; PANTALLA[7][40] = '*'; PANTALLA[7][41] = '*'; PANTALLA[7][42] = '*'; PANTALLA[7][43] = '*'; PANTALLA[7][44] = '*'; PANTALLA[7][45] = '*'; PANTALLA[7][46] = '*'; PANTALLA[7][47] = '_'; PANTALLA[7][48] = '*'; PANTALLA[7][49] = '*'; PANTALLA[7][50] = '_'; PANTALLA[7][51] = '*'; PANTALLA[7][52] = '*'; PANTALLA[7][53] = '_'; PANTALLA[7][54] = '*'; PANTALLA[7][55] = '*'; PANTALLA[7][56] = '*'; PANTALLA[7][57] = '*'; PANTALLA[7][58] = '*'; PANTALLA[7][59] = '*'; PANTALLA[7][60] = '*'; PANTALLA[7][61] = '*'; PANTALLA[7][62] = '*'; PANTALLA[7][63] = '*'; PANTALLA[7][64] = '*'; PANTALLA[7][65] = '_'; PANTALLA[7][66] = '*'; PANTALLA[7][67] = '_'; PANTALLA[7][68] = '*'; PANTALLA[7][69] = '*'; PANTALLA[7][70] = '*'; PANTALLA[7][71] = '*'; PANTALLA[7][72] = '_'; PANTALLA[7][73] = '*'; PANTALLA[7][74] = '*'; PANTALLA[8][0] = '*'; PANTALLA[8][1] = '*'; PANTALLA[8][2] = '*'; PANTALLA[8][3] = '_'; PANTALLA[8][4] = '*'; PANTALLA[8][5] = '*'; PANTALLA[8][6] = '*'; PANTALLA[8][7] = '*'; PANTALLA[8][8] = '_'; PANTALLA[8][9] = '_'; PANTALLA[8][10] = '_'; PANTALLA[8][11] = '_'; PANTALLA[8][12] = '_'; PANTALLA[8][13] = '*'; PANTALLA[8][14] = '*'; PANTALLA[8][15] = '_'; PANTALLA[8][16] = '*'; PANTALLA[8][17] = '*'; PANTALLA[8][18] = '*'; PANTALLA[8][19] = '*'; PANTALLA[8][20] = '*'; PANTALLA[8][21] = '*'; PANTALLA[8][22] = '*'; PANTALLA[8][23] = '*'; PANTALLA[8][24] = '_'; PANTALLA[8][25] = '*'; PANTALLA[8][26] = '*'; PANTALLA[8][27] = '*'; PANTALLA[8][28] = '*'; PANTALLA[8][29] = '*'; PANTALLA[8][30] = '*'; PANTALLA[8][31] = '_'; PANTALLA[8][32] = '*'; PANTALLA[8][33] = '*'; PANTALLA[8][34] = '*'; PANTALLA[8][35] = '*'; PANTALLA[8][36] = '_'; PANTALLA[8][37] = '*'; PANTALLA[8][38] = '*'; PANTALLA[8][39] = '_'; PANTALLA[8][40] = '_'; PANTALLA[8][41] = '_'; PANTALLA[8][42] = '_'; PANTALLA[8][43] = '_'; PANTALLA[8][44] = '_'; PANTALLA[8][45] = '_'; PANTALLA[8][46] = '*'; PANTALLA[8][47] = '_'; PANTALLA[8][48] = '*'; PANTALLA[8][49] = '*'; PANTALLA[8][50] = '_'; PANTALLA[8][51] = '*'; PANTALLA[8][52] = '*'; PANTALLA[8][53] = '_'; PANTALLA[8][54] = '*'; PANTALLA[8][55] = '*'; PANTALLA[8][56] = '_'; PANTALLA[8][57] = '_'; PANTALLA[8][58] = '_'; PANTALLA[8][59] = '_'; PANTALLA[8][60] = '*'; PANTALLA[8][61] = '*'; PANTALLA[8][62] = '*'; PANTALLA[8][63] = '*'; PANTALLA[8][64] = '*'; PANTALLA[8][65] = '_'; PANTALLA[8][66] = '*'; PANTALLA[8][67] = '_'; PANTALLA[8][68] = '*'; PANTALLA[8][69] = '*'; PANTALLA[8][70] = '_'; PANTALLA[8][71] = '_'; PANTALLA[8][72] = '_'; PANTALLA[8][73] = '*'; PANTALLA[8][74] = '*'; PANTALLA[9][0] = '*'; PANTALLA[9][1] = '*'; PANTALLA[9][2] = '*'; PANTALLA[9][3] = '_'; PANTALLA[9][4] = '*'; PANTALLA[9][5] = '*'; PANTALLA[9][6] = '*'; PANTALLA[9][7] = '*'; PANTALLA[9][8] = '*'; PANTALLA[9][9] = '*'; PANTALLA[9][10] = '*'; PANTALLA[9][11] = '*'; PANTALLA[9][12] = '_'; PANTALLA[9][13] = '*'; PANTALLA[9][14] = '*'; PANTALLA[9][15] = '_'; PANTALLA[9][16] = '*'; PANTALLA[9][17] = '*'; PANTALLA[9][18] = '*'; PANTALLA[9][19] = '_'; PANTALLA[9][20] = '_'; PANTALLA[9][21] = '_'; PANTALLA[9][22] = '_'; PANTALLA[9][23] = '_'; PANTALLA[9][24] = '_'; PANTALLA[9][25] = '*'; PANTALLA[9][26] = '_'; PANTALLA[9][27] = '*'; PANTALLA[9][28] = '*'; PANTALLA[9][29] = '*'; PANTALLA[9][30] = '*'; PANTALLA[9][31] = '_'; PANTALLA[9][32] = '*'; PANTALLA[9][33] = '*'; PANTALLA[9][34] = '*'; PANTALLA[9][35] = '*'; PANTALLA[9][36] = '_'; PANTALLA[9][37] = '_'; PANTALLA[9][38] = '*'; PANTALLA[9][39] = '_'; PANTALLA[9][40] = '*'; PANTALLA[9][41] = '*'; PANTALLA[9][42] = '*'; PANTALLA[9][43] = '*'; PANTALLA[9][44] = '*'; PANTALLA[9][45] = '_'; PANTALLA[9][46] = '*'; PANTALLA[9][47] = '_'; PANTALLA[9][48] = '*'; PANTALLA[9][49] = '*'; PANTALLA[9][50] = '_'; PANTALLA[9][51] = '*'; PANTALLA[9][52] = '*'; PANTALLA[9][53] = '_'; PANTALLA[9][54] = '*'; PANTALLA[9][55] = '*'; PANTALLA[9][56] = '_'; PANTALLA[9][57] = '*'; PANTALLA[9][58] = '*'; PANTALLA[9][59] = '_'; PANTALLA[9][60] = '_'; PANTALLA[9][61] = '_'; PANTALLA[9][62] = '_'; PANTALLA[9][63] = '_'; PANTALLA[9][64] = '_'; PANTALLA[9][65] = '_'; PANTALLA[9][66] = '*'; PANTALLA[9][67] = '_'; PANTALLA[9][68] = '*'; PANTALLA[9][69] = '*'; PANTALLA[9][70] = '_'; PANTALLA[9][71] = '*'; PANTALLA[9][72] = '*'; PANTALLA[9][73] = '*'; PANTALLA[9][74] = '*'; PANTALLA[10][0] = '*'; PANTALLA[10][1] = '*'; PANTALLA[10][2] = '_'; PANTALLA[10][3] = '_'; PANTALLA[10][4] = '_'; PANTALLA[10][5] = '_'; PANTALLA[10][6] = '_'; PANTALLA[10][7] = '_'; PANTALLA[10][8] = '_'; PANTALLA[10][9] = '_'; PANTALLA[10][10] = '*'; PANTALLA[10][11] = '*'; PANTALLA[10][12] = '_'; PANTALLA[10][13] = '*'; PANTALLA[10][14] = '*'; PANTALLA[10][15] = '_'; PANTALLA[10][16] = '*'; PANTALLA[10][17] = '*'; PANTALLA[10][18] = '*'; PANTALLA[10][19] = '_'; PANTALLA[10][20] = '*'; PANTALLA[10][21] = '*'; PANTALLA[10][22] = '*'; PANTALLA[10][23] = '*'; PANTALLA[10][24] = '*'; PANTALLA[10][25] = '*'; PANTALLA[10][26] = '_'; PANTALLA[10][27] = '*'; PANTALLA[10][28] = '*'; PANTALLA[10][29] = '*'; PANTALLA[10][30] = '*'; PANTALLA[10][31] = '_'; PANTALLA[10][32] = '*'; PANTALLA[10][33] = '*'; PANTALLA[10][34] = '*'; PANTALLA[10][35] = '*'; PANTALLA[10][36] = '_'; PANTALLA[10][37] = '*'; PANTALLA[10][38] = '*'; PANTALLA[10][39] = '_'; PANTALLA[10][40] = '*'; PANTALLA[10][41] = '*'; PANTALLA[10][42] = '*'; PANTALLA[10][43] = '_'; PANTALLA[10][44] = '*'; PANTALLA[10][45] = '_'; PANTALLA[10][46] = '*'; PANTALLA[10][47] = '_'; PANTALLA[10][48] = '*'; PANTALLA[10][49] = '*'; PANTALLA[10][50] = '_'; PANTALLA[10][51] = '*'; PANTALLA[10][52] = '*'; PANTALLA[10][53] = '_'; PANTALLA[10][54] = '*'; PANTALLA[10][55] = '*'; PANTALLA[10][56] = '_'; PANTALLA[10][57] = '*'; PANTALLA[10][58] = '*'; PANTALLA[10][59] = '_'; PANTALLA[10][60] = '*'; PANTALLA[10][61] = '*'; PANTALLA[10][62] = '*'; PANTALLA[10][63] = '*'; PANTALLA[10][64] = '*'; PANTALLA[10][65] = '*'; PANTALLA[10][66] = '*'; PANTALLA[10][67] = '_'; PANTALLA[10][68] = '*'; PANTALLA[10][69] = '*'; PANTALLA[10][70] = '_'; PANTALLA[10][71] = '*'; PANTALLA[10][72] = '*'; PANTALLA[10][73] = '*'; PANTALLA[10][74] = '*'; PANTALLA[11][0] = '*'; PANTALLA[11][1] = '*'; PANTALLA[11][2] = '_'; PANTALLA[11][3] = '*'; PANTALLA[11][4] = '*'; PANTALLA[11][5] = '*'; PANTALLA[11][6] = '*'; PANTALLA[11][7] = '*'; PANTALLA[11][8] = '*'; PANTALLA[11][9] = '_'; PANTALLA[11][10] = '*'; PANTALLA[11][11] = '_'; PANTALLA[11][12] = '_'; PANTALLA[11][13] = '_'; PANTALLA[11][14] = '_'; PANTALLA[11][15] = '_'; PANTALLA[11][16] = '_'; PANTALLA[11][17] = '_'; PANTALLA[11][18] = '*'; PANTALLA[11][19] = '_'; PANTALLA[11][20] = '*'; PANTALLA[11][21] = '*'; PANTALLA[11][22] = '_'; PANTALLA[11][23] = '*'; PANTALLA[11][24] = '_'; PANTALLA[11][25] = '_'; PANTALLA[11][26] = '_'; PANTALLA[11][27] = '_'; PANTALLA[11][28] = '_'; PANTALLA[11][29] = '_'; PANTALLA[11][30] = '*'; PANTALLA[11][31] = '_'; PANTALLA[11][32] = '*'; PANTALLA[11][33] = '_'; PANTALLA[11][34] = '_'; PANTALLA[11][35] = '_'; PANTALLA[11][36] = '_'; PANTALLA[11][37] = '*'; PANTALLA[11][38] = '*'; PANTALLA[11][39] = '_'; PANTALLA[11][40] = '*'; PANTALLA[11][41] = '*'; PANTALLA[11][42] = '*'; PANTALLA[11][43] = '_'; PANTALLA[11][44] = '*'; PANTALLA[11][45] = '_'; PANTALLA[11][46] = '*'; PANTALLA[11][47] = '_'; PANTALLA[11][48] = '_'; PANTALLA[11][49] = '_'; PANTALLA[11][50] = '_'; PANTALLA[11][51] = '*'; PANTALLA[11][52] = '*'; PANTALLA[11][53] = '_'; PANTALLA[11][54] = '*'; PANTALLA[11][55] = '*'; PANTALLA[11][56] = '_'; PANTALLA[11][57] = '*'; PANTALLA[11][58] = '*'; PANTALLA[11][59] = '_'; PANTALLA[11][60] = '*'; PANTALLA[11][61] = '*'; PANTALLA[11][62] = '_'; PANTALLA[11][63] = '_'; PANTALLA[11][64] = '_'; PANTALLA[11][65] = '_'; PANTALLA[11][66] = '_'; PANTALLA[11][67] = '_'; PANTALLA[11][68] = '*'; PANTALLA[11][69] = '_'; PANTALLA[11][70] = '_'; PANTALLA[11][71] = '*'; PANTALLA[11][72] = '*'; PANTALLA[11][73] = '*'; PANTALLA[11][74] = '*'; PANTALLA[12][0] = '*'; PANTALLA[12][1] = '*'; PANTALLA[12][2] = '_'; PANTALLA[12][3] = '*'; PANTALLA[12][4] = '*'; PANTALLA[12][5] = '_'; PANTALLA[12][6] = '_'; PANTALLA[12][7] = '_'; PANTALLA[12][8] = '*'; PANTALLA[12][9] = '_'; PANTALLA[12][10] = '*'; PANTALLA[12][11] = '*'; PANTALLA[12][12] = '*'; PANTALLA[12][13] = '*'; PANTALLA[12][14] = '*'; PANTALLA[12][15] = '_'; PANTALLA[12][16] = '*'; PANTALLA[12][17] = '*'; PANTALLA[12][18] = '*'; PANTALLA[12][19] = '_'; PANTALLA[12][20] = '*'; PANTALLA[12][21] = '*'; PANTALLA[12][22] = '_'; PANTALLA[12][23] = '*'; PANTALLA[12][24] = '_'; PANTALLA[12][25] = '*'; PANTALLA[12][26] = '*'; PANTALLA[12][27] = '*'; PANTALLA[12][28] = '*'; PANTALLA[12][29] = '*'; PANTALLA[12][30] = '*'; PANTALLA[12][31] = '_'; PANTALLA[12][32] = '*'; PANTALLA[12][33] = '*'; PANTALLA[12][34] = '_'; PANTALLA[12][35] = '*'; PANTALLA[12][36] = '*'; PANTALLA[12][37] = '*'; PANTALLA[12][38] = '*'; PANTALLA[12][39] = '_'; PANTALLA[12][40] = '*'; PANTALLA[12][41] = '*'; PANTALLA[12][42] = '*'; PANTALLA[12][43] = '_'; PANTALLA[12][44] = '*'; PANTALLA[12][45] = '_'; PANTALLA[12][46] = '*'; PANTALLA[12][47] = '*'; PANTALLA[12][48] = '_'; PANTALLA[12][49] = '*'; PANTALLA[12][50] = '*'; PANTALLA[12][51] = '*'; PANTALLA[12][52] = '_'; PANTALLA[12][53] = '_'; PANTALLA[12][54] = '_'; PANTALLA[12][55] = '_'; PANTALLA[12][56] = '_'; PANTALLA[12][57] = '*'; PANTALLA[12][58] = '*'; PANTALLA[12][59] = '_'; PANTALLA[12][60] = '*'; PANTALLA[12][61] = '*'; PANTALLA[12][62] = '_'; PANTALLA[12][63] = '*'; PANTALLA[12][64] = '*'; PANTALLA[12][65] = '*'; PANTALLA[12][66] = '*'; PANTALLA[12][67] = '_'; PANTALLA[12][68] = '*'; PANTALLA[12][69] = '*'; PANTALLA[12][70] = '_'; PANTALLA[12][71] = '*'; PANTALLA[12][72] = '*'; PANTALLA[12][73] = '*'; PANTALLA[12][74] = '*'; PANTALLA[13][0] = '*'; PANTALLA[13][1] = '*'; PANTALLA[13][2] = '_'; PANTALLA[13][3] = '*'; PANTALLA[13][4] = '*'; PANTALLA[13][5] = '_'; PANTALLA[13][6] = '*'; PANTALLA[13][7] = '_'; PANTALLA[13][8] = '*'; PANTALLA[13][9] = '_'; PANTALLA[13][10] = '*'; PANTALLA[13][11] = '_'; PANTALLA[13][12] = '_'; PANTALLA[13][13] = '_'; PANTALLA[13][14] = '*'; PANTALLA[13][15] = '_'; PANTALLA[13][16] = '*'; PANTALLA[13][17] = '*'; PANTALLA[13][18] = '*'; PANTALLA[13][19] = '_'; PANTALLA[13][20] = '*'; PANTALLA[13][21] = '_'; PANTALLA[13][22] = '_'; PANTALLA[13][23] = '*'; PANTALLA[13][24] = '_'; PANTALLA[13][25] = '*'; PANTALLA[13][26] = '*'; PANTALLA[13][27] = '*'; PANTALLA[13][28] = '*'; PANTALLA[13][29] = '*'; PANTALLA[13][30] = '*'; PANTALLA[13][31] = '_'; PANTALLA[13][32] = '*'; PANTALLA[13][33] = '*'; PANTALLA[13][34] = '_'; PANTALLA[13][35] = '*'; PANTALLA[13][36] = '*'; PANTALLA[13][37] = '*'; PANTALLA[13][38] = '*'; PANTALLA[13][39] = '_'; PANTALLA[13][40] = '*'; PANTALLA[13][41] = '*'; PANTALLA[13][42] = '*'; PANTALLA[13][43] = '_'; PANTALLA[13][44] = '*'; PANTALLA[13][45] = '_'; PANTALLA[13][46] = '_'; PANTALLA[13][47] = '_'; PANTALLA[13][48] = '_'; PANTALLA[13][49] = '_'; PANTALLA[13][50] = '_'; PANTALLA[13][51] = '_'; PANTALLA[13][52] = '_'; PANTALLA[13][53] = '*'; PANTALLA[13][54] = '*'; PANTALLA[13][55] = '_'; PANTALLA[13][56] = '*'; PANTALLA[13][57] = '*'; PANTALLA[13][58] = '*'; PANTALLA[13][59] = '_'; PANTALLA[13][60] = '*'; PANTALLA[13][61] = '*'; PANTALLA[13][62] = '_'; PANTALLA[13][63] = '*'; PANTALLA[13][64] = '*'; PANTALLA[13][65] = '*'; PANTALLA[13][66] = '*'; PANTALLA[13][67] = '_'; PANTALLA[13][68] = '*'; PANTALLA[13][69] = '*'; PANTALLA[13][70] = '_'; PANTALLA[13][71] = '*'; PANTALLA[13][72] = '*'; PANTALLA[13][73] = '*'; PANTALLA[13][74] = '*'; PANTALLA[14][0] = '*'; PANTALLA[14][1] = '*'; PANTALLA[14][2] = '_'; PANTALLA[14][3] = '_'; PANTALLA[14][4] = '_'; PANTALLA[14][5] = '_'; PANTALLA[14][6] = '*'; PANTALLA[14][7] = '_'; PANTALLA[14][8] = '*'; PANTALLA[14][9] = '_'; PANTALLA[14][10] = '*'; PANTALLA[14][11] = '_'; PANTALLA[14][12] = '*'; PANTALLA[14][13] = '_'; PANTALLA[14][14] = '*'; PANTALLA[14][15] = '*'; PANTALLA[14][16] = '*'; PANTALLA[14][17] = '*'; PANTALLA[14][18] = '*'; PANTALLA[14][19] = '_'; PANTALLA[14][20] = '*'; PANTALLA[14][21] = '*'; PANTALLA[14][22] = '_'; PANTALLA[14][23] = '*'; PANTALLA[14][24] = '_'; PANTALLA[14][25] = '*'; PANTALLA[14][26] = '_'; PANTALLA[14][27] = '_'; PANTALLA[14][28] = '_'; PANTALLA[14][29] = '_'; PANTALLA[14][30] = '_'; PANTALLA[14][31] = '_'; PANTALLA[14][32] = '*'; PANTALLA[14][33] = '*'; PANTALLA[14][34] = '_'; PANTALLA[14][35] = '*'; PANTALLA[14][36] = '*'; PANTALLA[14][37] = '*'; PANTALLA[14][38] = '*'; PANTALLA[14][39] = '_'; PANTALLA[14][40] = '_'; PANTALLA[14][41] = '_'; PANTALLA[14][42] = '_'; PANTALLA[14][43] = '_'; PANTALLA[14][44] = '*'; PANTALLA[14][45] = '*'; PANTALLA[14][46] = '*'; PANTALLA[14][47] = '*'; PANTALLA[14][48] = '*'; PANTALLA[14][49] = '*'; PANTALLA[14][50] = '*'; PANTALLA[14][51] = '*'; PANTALLA[14][52] = '*'; PANTALLA[14][53] = '*'; PANTALLA[14][54] = '*'; PANTALLA[14][55] = '_'; PANTALLA[14][56] = '*'; PANTALLA[14][57] = '*'; PANTALLA[14][58] = '*'; PANTALLA[14][59] = '_'; PANTALLA[14][60] = '*'; PANTALLA[14][61] = '*'; PANTALLA[14][62] = '_'; PANTALLA[14][63] = '*'; PANTALLA[14][64] = '*'; PANTALLA[14][65] = '_'; PANTALLA[14][66] = '*'; PANTALLA[14][67] = '_'; PANTALLA[14][68] = '*'; PANTALLA[14][69] = '*'; PANTALLA[14][70] = '_'; PANTALLA[14][71] = '*'; PANTALLA[14][72] = '*'; PANTALLA[14][73] = '*'; PANTALLA[14][74] = '*'; PANTALLA[15][0] = '*'; PANTALLA[15][1] = '*'; PANTALLA[15][2] = '*'; PANTALLA[15][3] = '*'; PANTALLA[15][4] = '*'; PANTALLA[15][5] = '*'; PANTALLA[15][6] = '*'; PANTALLA[15][7] = '_'; PANTALLA[15][8] = '*'; PANTALLA[15][9] = '_'; PANTALLA[15][10] = '_'; PANTALLA[15][11] = '_'; PANTALLA[15][12] = '*'; PANTALLA[15][13] = '_'; PANTALLA[15][14] = '_'; PANTALLA[15][15] = '_'; PANTALLA[15][16] = '_'; PANTALLA[15][17] = '_'; PANTALLA[15][18] = '_'; PANTALLA[15][19] = '_'; PANTALLA[15][20] = '*'; PANTALLA[15][21] = '*'; PANTALLA[15][22] = '_'; PANTALLA[15][23] = '_'; PANTALLA[15][24] = '_'; PANTALLA[15][25] = '*'; PANTALLA[15][26] = '_'; PANTALLA[15][27] = '*'; PANTALLA[15][28] = '*'; PANTALLA[15][29] = '*'; PANTALLA[15][30] = '*'; PANTALLA[15][31] = '*'; PANTALLA[15][32] = '*'; PANTALLA[15][33] = '*'; PANTALLA[15][34] = '_'; PANTALLA[15][35] = '*'; PANTALLA[15][36] = '*'; PANTALLA[15][37] = '*'; PANTALLA[15][38] = '*'; PANTALLA[15][39] = '_'; PANTALLA[15][40] = '*'; PANTALLA[15][41] = '*'; PANTALLA[15][42] = '_'; PANTALLA[15][43] = '*'; PANTALLA[15][44] = '*'; PANTALLA[15][45] = '*'; PANTALLA[15][46] = '*'; PANTALLA[15][47] = '*'; PANTALLA[15][48] = '_'; PANTALLA[15][49] = '*'; PANTALLA[15][50] = '*'; PANTALLA[15][51] = '*'; PANTALLA[15][52] = '*'; PANTALLA[15][53] = '*'; PANTALLA[15][54] = '*'; PANTALLA[15][55] = '_'; PANTALLA[15][56] = '*'; PANTALLA[15][57] = '*'; PANTALLA[15][58] = '*'; PANTALLA[15][59] = '_'; PANTALLA[15][60] = '*'; PANTALLA[15][61] = '*'; PANTALLA[15][62] = '_'; PANTALLA[15][63] = '*'; PANTALLA[15][64] = '*'; PANTALLA[15][65] = '_'; PANTALLA[15][66] = '*'; PANTALLA[15][67] = '_'; PANTALLA[15][68] = '_'; PANTALLA[15][69] = '_'; PANTALLA[15][70] = '_'; PANTALLA[15][71] = '*'; PANTALLA[15][72] = '*'; PANTALLA[15][73] = '*'; PANTALLA[15][74] = '*'; PANTALLA[16][0] = '*'; PANTALLA[16][1] = '*'; PANTALLA[16][2] = '*'; PANTALLA[16][3] = '*'; PANTALLA[16][4] = '*'; PANTALLA[16][5] = '*'; PANTALLA[16][6] = '*'; PANTALLA[16][7] = '_'; PANTALLA[16][8] = '*'; PANTALLA[16][9] = '*'; PANTALLA[16][10] = '*'; PANTALLA[16][11] = '*'; PANTALLA[16][12] = '*'; PANTALLA[16][13] = '_'; PANTALLA[16][14] = '*'; PANTALLA[16][15] = '*'; PANTALLA[16][16] = '*'; PANTALLA[16][17] = '*'; PANTALLA[16][18] = '*'; PANTALLA[16][19] = '*'; PANTALLA[16][20] = '*'; PANTALLA[16][21] = '*'; PANTALLA[16][22] = '_'; PANTALLA[16][23] = '*'; PANTALLA[16][24] = '*'; PANTALLA[16][25] = '*'; PANTALLA[16][26] = '_'; PANTALLA[16][27] = '*'; PANTALLA[16][28] = '*'; PANTALLA[16][29] = '*'; PANTALLA[16][30] = '*'; PANTALLA[16][31] = '*'; PANTALLA[16][32] = '*'; PANTALLA[16][33] = '_'; PANTALLA[16][34] = '_'; PANTALLA[16][35] = '_'; PANTALLA[16][36] = '_'; PANTALLA[16][37] = '_'; PANTALLA[16][38] = '_'; PANTALLA[16][39] = '_'; PANTALLA[16][40] = '*'; PANTALLA[16][41] = '*'; PANTALLA[16][42] = '_'; PANTALLA[16][43] = '*'; PANTALLA[16][44] = '*'; PANTALLA[16][45] = '*'; PANTALLA[16][46] = '*'; PANTALLA[16][47] = '*'; PANTALLA[16][48] = '_'; PANTALLA[16][49] = '*'; PANTALLA[16][50] = '*'; PANTALLA[16][51] = '*'; PANTALLA[16][52] = '*'; PANTALLA[16][53] = '*'; PANTALLA[16][54] = '*'; PANTALLA[16][55] = '_'; PANTALLA[16][56] = '_'; PANTALLA[16][57] = '_'; PANTALLA[16][58] = '*'; PANTALLA[16][59] = '_'; PANTALLA[16][60] = '_'; PANTALLA[16][61] = '_'; PANTALLA[16][62] = '_'; PANTALLA[16][63] = '_'; PANTALLA[16][64] = '_'; PANTALLA[16][65] = '_'; PANTALLA[16][66] = '*'; PANTALLA[16][67] = '*'; PANTALLA[16][68] = '*'; PANTALLA[16][69] = '*'; PANTALLA[16][70] = '*'; PANTALLA[16][71] = '*'; PANTALLA[16][72] = '*'; PANTALLA[16][73] = '*'; PANTALLA[16][74] = '*'; PANTALLA[17][0] = '*'; PANTALLA[17][1] = '*'; PANTALLA[17][2] = '*'; PANTALLA[17][3] = '*'; PANTALLA[17][4] = '*'; PANTALLA[17][5] = '*'; PANTALLA[17][6] = '*'; PANTALLA[17][7] = '_'; PANTALLA[17][8] = '_'; PANTALLA[17][9] = '_'; PANTALLA[17][10] = '_'; PANTALLA[17][11] = '_'; PANTALLA[17][12] = '*'; PANTALLA[17][13] = '_'; PANTALLA[17][14] = '_'; PANTALLA[17][15] = '_'; PANTALLA[17][16] = '_'; PANTALLA[17][17] = '_'; PANTALLA[17][18] = '_'; PANTALLA[17][19] = '_'; PANTALLA[17][20] = '_'; PANTALLA[17][21] = '_'; PANTALLA[17][22] = '_'; PANTALLA[17][23] = '*'; PANTALLA[17][24] = '*'; PANTALLA[17][25] = '*'; PANTALLA[17][26] = '_'; PANTALLA[17][27] = '*'; PANTALLA[17][28] = '*'; PANTALLA[17][29] = '*'; PANTALLA[17][30] = '*'; PANTALLA[17][31] = '*'; PANTALLA[17][32] = '*'; PANTALLA[17][33] = '_'; PANTALLA[17][34] = '*'; PANTALLA[17][35] = '*'; PANTALLA[17][36] = '*'; PANTALLA[17][37] = '*'; PANTALLA[17][38] = '*'; PANTALLA[17][39] = '*'; PANTALLA[17][40] = '*'; PANTALLA[17][41] = '*'; PANTALLA[17][42] = '_'; PANTALLA[17][43] = '_'; PANTALLA[17][44] = '_'; PANTALLA[17][45] = '_'; PANTALLA[17][46] = '_'; PANTALLA[17][47] = '_'; PANTALLA[17][48] = '_'; PANTALLA[17][49] = '*'; PANTALLA[17][50] = '*'; PANTALLA[17][51] = '*'; PANTALLA[17][52] = '*'; PANTALLA[17][53] = '*'; PANTALLA[17][54] = '*'; PANTALLA[17][55] = '*'; PANTALLA[17][56] = '*'; PANTALLA[17][57] = '*'; PANTALLA[17][58] = '*'; PANTALLA[17][59] = '*'; PANTALLA[17][60] = '*'; PANTALLA[17][61] = '*'; PANTALLA[17][62] = '*'; PANTALLA[17][63] = '*'; PANTALLA[17][64] = '*'; PANTALLA[17][65] = '*'; PANTALLA[17][66] = '*'; PANTALLA[17][67] = '*'; PANTALLA[17][68] = '*'; PANTALLA[17][69] = '*'; PANTALLA[17][70] = '*'; PANTALLA[17][71] = '*'; PANTALLA[17][72] = '*'; PANTALLA[17][73] = '*'; PANTALLA[17][74] = '*'; PANTALLA[18][0] = '*'; PANTALLA[18][1] = '*'; PANTALLA[18][2] = '*'; PANTALLA[18][3] = '*'; PANTALLA[18][4] = '*'; PANTALLA[18][5] = '*'; PANTALLA[18][6] = '*'; PANTALLA[18][7] = '*'; PANTALLA[18][8] = '*'; PANTALLA[18][9] = '*'; PANTALLA[18][10] = '*'; PANTALLA[18][11] = '*'; PANTALLA[18][12] = '*'; PANTALLA[18][13] = '*'; PANTALLA[18][14] = '*'; PANTALLA[18][15] = '*'; PANTALLA[18][16] = '*'; PANTALLA[18][17] = '*'; PANTALLA[18][18] = '*'; PANTALLA[18][19] = '*'; PANTALLA[18][20] = '*'; PANTALLA[18][21] = '*'; PANTALLA[18][22] = '*'; PANTALLA[18][23] = '*'; PANTALLA[18][24] = '*'; PANTALLA[18][25] = '*'; PANTALLA[18][26] = '_'; PANTALLA[18][27] = '_'; PANTALLA[18][28] = '_'; PANTALLA[18][29] = '_'; PANTALLA[18][30] = '_'; PANTALLA[18][31] = '_'; PANTALLA[18][32] = '_'; PANTALLA[18][33] = '_'; PANTALLA[18][34] = '*'; PANTALLA[18][35] = '*'; PANTALLA[18][36] = '*'; PANTALLA[18][37] = '*'; PANTALLA[18][38] = '*'; PANTALLA[18][39] = '*'; PANTALLA[18][40] = '*'; PANTALLA[18][41] = '*'; PANTALLA[18][42] = '*'; PANTALLA[18][43] = '*'; PANTALLA[18][44] = '*'; PANTALLA[18][45] = '*'; PANTALLA[18][46] = '*'; PANTALLA[18][47] = '*'; PANTALLA[18][48] = '*'; PANTALLA[18][49] = '*'; PANTALLA[18][50] = '*'; PANTALLA[18][51] = '*'; PANTALLA[18][52] = '*'; PANTALLA[18][53] = '*'; PANTALLA[18][54] = '*'; PANTALLA[18][55] = '*'; PANTALLA[18][56] = '*'; PANTALLA[18][57] = '*'; PANTALLA[18][58] = '*'; PANTALLA[18][59] = '*'; PANTALLA[18][60] = '*'; PANTALLA[18][61] = '*'; PANTALLA[18][62] = '*'; PANTALLA[18][63] = '*'; PANTALLA[18][64] = '*'; PANTALLA[18][65] = '*'; PANTALLA[18][66] = '*'; PANTALLA[18][67] = '*'; PANTALLA[18][68] = '*'; PANTALLA[18][69] = '*'; PANTALLA[18][70] = '*'; PANTALLA[18][71] = '*'; PANTALLA[18][72] = '*'; PANTALLA[18][73] = '*'; PANTALLA[18][74] = '*'; PANTALLA[19][0] = '*'; PANTALLA[19][1] = '*'; PANTALLA[19][2] = '*'; PANTALLA[19][3] = '*'; PANTALLA[19][4] = '*'; PANTALLA[19][5] = '*'; PANTALLA[19][6] = '*'; PANTALLA[19][7] = '*'; PANTALLA[19][8] = '*'; PANTALLA[19][9] = '*'; PANTALLA[19][10] = '*'; PANTALLA[19][11] = '*'; PANTALLA[19][12] = '*'; PANTALLA[19][13] = '*'; PANTALLA[19][14] = '*'; PANTALLA[19][15] = '*'; PANTALLA[19][16] = '*'; PANTALLA[19][17] = '*'; PANTALLA[19][18] = '*'; PANTALLA[19][19] = '*'; PANTALLA[19][20] = '*'; PANTALLA[19][21] = '*'; PANTALLA[19][22] = '*'; PANTALLA[19][23] = '*'; PANTALLA[19][24] = '*'; PANTALLA[19][25] = '*'; PANTALLA[19][26] = '*'; PANTALLA[19][27] = '*'; PANTALLA[19][28] = '*'; PANTALLA[19][29] = '*'; PANTALLA[19][30] = '*'; PANTALLA[19][31] = '*'; PANTALLA[19][32] = '*'; PANTALLA[19][33] = '*'; PANTALLA[19][34] = '*'; PANTALLA[19][35] = '*'; PANTALLA[19][36] = '*'; PANTALLA[19][37] = '*'; PANTALLA[19][38] = '*'; PANTALLA[19][39] = '*'; PANTALLA[19][40] = '*'; PANTALLA[19][41] = '*'; PANTALLA[19][42] = '*'; PANTALLA[19][43] = '*'; PANTALLA[19][44] = '*'; PANTALLA[19][45] = '*'; PANTALLA[19][46] = '*'; PANTALLA[19][47] = '*'; PANTALLA[19][48] = '*'; PANTALLA[19][49] = '*'; PANTALLA[19][50] = '*'; PANTALLA[19][51] = '*'; PANTALLA[19][52] = '*'; PANTALLA[19][53] = '*'; PANTALLA[19][54] = '*'; PANTALLA[19][55] = '*'; PANTALLA[19][56] = '*'; PANTALLA[19][57] = '*'; PANTALLA[19][58] = '*'; PANTALLA[19][59] = '*'; PANTALLA[19][60] = '*'; PANTALLA[19][61] = '*'; PANTALLA[19][62] = '*'; PANTALLA[19][63] = '*'; PANTALLA[19][64] = '*'; PANTALLA[19][65] = '*'; PANTALLA[19][66] = '*'; PANTALLA[19][67] = '*'; PANTALLA[19][68] = '*'; PANTALLA[19][69] = '*'; PANTALLA[19][70] = '*'; PANTALLA[19][71] = '*'; PANTALLA[19][72] = '*'; PANTALLA[19][73] = '*'; PANTALLA[19][74] = '*';
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