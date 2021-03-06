#ifndef IOTEXT_H
#define IOTEXT_H
#define MAXBARIS 40
#define MAXKOLOM 80
#include <windows.h>

struct data{
 char data[MAXBARIS][MAXKOLOM];
};

struct editor{
 int baris;
 int kolom;
 HANDLE hstdout;
 COORD destcord;
};

static struct editor E;
static struct data D;

enum KeyInput{
	
	ENTER = 13,
	CTRL_S = 19,
	CTRL_N = 14,
	CTRL_Q = 17,
	CTRL_C = 3,
	CTRL_I = 9
	
};

void print(char arr[MAXBARIS][MAXKOLOM]);
void insertion(int key);
void deleteChar();
void moveCursor();
void setCursor();
void initEditor();
void openFile();
void keyProsess(char filename[20]);
void getData(char data[MAXBARIS][MAXKOLOM]);
int getLastX(int baris);
int getLastY();

#endif
