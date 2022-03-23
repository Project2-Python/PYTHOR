#ifndef IOTEXT_H
#define IOTEXT_H
#define MAXBARIS 8
#define MAXKOLOM 4

#include <stdio.h>
#include <conio.h>
#include <windows.h>

//Variabel Global
enum KeyInput{
	
	ENTER = 13,
	CTRL_S = 19,
	CTRL_N = 14,
	CTRL_Q = 17,
	CTRL_C = 3,
	BACKSPACE = 8
	
};

char data[MAXBARIS][MAXKOLOM];
int baris, kolom;

HANDLE hstdout;
COORD destcord;

//Procedure dan Fungsi
void gotoxy(int x, int y);
void insertion(int key);
void Print_Text();
void moveCursor();
void setCursor();


#endif



