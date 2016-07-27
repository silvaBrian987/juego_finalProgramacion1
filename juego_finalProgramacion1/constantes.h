#define UP 72
#define DOWN 80
#define RIGHT 75
#define LEFT 77

#define PANTALLA_HEIGHT 20
#define PANTALLA_WIDTH 75

const int SNAKE_MAX_SIZE = 10;
const char SNAKE_CHAR = 'S';
const char PARED_CHAR = '*';
const char MANZANA_CHAR = 'M';

char PANTALLA[PANTALLA_HEIGHT][PANTALLA_WIDTH];

int SNAKE[SNAKE_MAX_SIZE][2];

int POS_X = 0;
int POS_Y = 0;

bool isUP = true;
bool isDOWN = false;
bool isRIGHT = false;
bool isLEFT = false;