#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include "constantes.h"

using namespace std;

void ClearScreen_1()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void ClearScreen_2(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
									 cursor */
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize;                 /* number of character cells in
									 the current buffer */

	/* get the number of character cells in the current buffer */

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	//PERR(bSuccess, "GetConsoleScreenBufferInfo");
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */

	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);
	//PERR(bSuccess, "FillConsoleOutputCharacter");

	/* get the current text attribute */

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	//PERR(bSuccess, "ConsoleScreenBufferInfo");

	/* now set the buffer's attributes accordingly */

	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);
	//PERR(bSuccess, "FillConsoleOutputAttribute");

	/* put the cursor at (0, 0) */

	bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
	//PERR(bSuccess, "SetConsoleCursorPosition");	
	return;
}

void limpiarPantalla()
{
	//ClearScreen_1();
	//ClearScreen_2();
	system("cls");
}

bool iskeypressed(unsigned timeout_ms = 0)
{
	return WaitForSingleObject(
		GetStdHandle(STD_INPUT_HANDLE),
		timeout_ms
		) == WAIT_OBJECT_0;
}

int leerTeclado(){
	/*
	while (!iskeypressed(500))
	{
		cout << "." << flush;
	}
	return 0;
	*/

	if (GetAsyncKeyState(VK_UP)) return UP;
	if (GetAsyncKeyState(VK_DOWN)) return DOWN;
	if (GetAsyncKeyState(VK_RIGHT)) return LEFT;
	if (GetAsyncKeyState(VK_LEFT)) return RIGHT;
	if (GetAsyncKeyState(VK_RETURN)) return 13;
	if (GetAsyncKeyState(VK_ESCAPE)) return 27;
	return 0;
}

void imprimirAPantalla(int val){
	cout << val;
}

void imprimirAPantalla(char c){
	cout << c;
}

void imprimirAPantalla(string str){
	cout << str;
}

void imprimirSaltoLinea(){
	imprimirAPantalla('\n');
}