#define UP 72
#define DOWN 80
#define RIGHT 75
#define LEFT 77

#define PANTALLA_HEIGHT 20
#define PANTALLA_WIDTH 75

int POS_X = 0;
int POS_Y = 0;

int VELOCIDAD_JUEGO = 75;

char PANTALLA[PANTALLA_HEIGHT][PANTALLA_WIDTH];
const char PARED_CHAR = '*';
const char FONDO_CHAR = '_';

//Para la viborita
const int SNAKE_MAX_SIZE = 10;
const char SNAKE_CHAR = 'S';
const char MANZANA_CHAR = 'M';
int SNAKE[SNAKE_MAX_SIZE][2];

//Para el laberinto
const int JUGADOR_MAX_SIZE = 1;
int JUGADOR[JUGADOR_MAX_SIZE][2];
const char JUGADOR_CHAR = 'M';

bool isUP = true;
bool isDOWN = false;
bool isRIGHT = false;
bool isLEFT = false;


void moveUP() {
	isUP = true;
	isDOWN = false;
	isRIGHT = false;
	isLEFT = false;
}

void moveDOWN() {
	isUP = false;
	isDOWN = true;
	isRIGHT = false;
	isLEFT = false;
}

void moveRIGHT() {
	isUP = false;
	isDOWN = false;
	isRIGHT = true;
	isLEFT = false;
}

void moveLEFT() {
	isUP = false;
	isDOWN = false;
	isRIGHT = false;
	isLEFT = true;
}