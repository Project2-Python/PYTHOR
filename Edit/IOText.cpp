#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "IOText.h"

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void insertion(int key){
	if(key == '\r'){
		data[baris][kolom] = '\n';
	} else {
		data[baris][kolom] = key;
	}
}

void Print_Text(){
	printf("%c", data[baris][kolom]);
}
void moveCursor(){
	char temp = getch();
	switch(temp){
		case 72: // UP
			if(destcord.Y == 0){
				destcord.Y = MAXBARIS;
			} else {
				destcord.Y--;
			}
			break;
		case 75: // LEFT
			if(destcord.X == 0){
				destcord.X == MAXKOLOM;
			} else {
				destcord.X--;
			}
			break;
		case 77:// RIGHT
			if(destcord.X == MAXKOLOM){
				destcord.X = 0;
			} else {
				destcord.X++;
			}
			break;
		case 80: // DOWN
			if(destcord.Y == MAXBARIS){
				destcord.Y = 0;
			} else {
				destcord.Y++;
			}
	}
}

void setCursor(){
 	destcord.X;
 	destcord.Y;
 	
 	if(destcord.X == MAXKOLOM){
 		destcord.X = 0;
 		destcord.Y++;
	 } else if(data[baris][kolom] == '\n'){
	 	destcord.X = 0;
	 	destcord.Y++;
	 } else {
	 	destcord.X++;
	 }
}
	

void mainsementara(){
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destcord.X = 0;
	destcord.Y = 0;
	baris = 0, kolom = 0;
	system("cls");
	
	while(1){
		SetConsoleCursorPosition(hstdout, destcord);
		data[baris][kolom] = getch();
		if(data[baris][kolom] == -32){
			moveCursor();
		} else {
			insertion(data[baris][kolom]);
			Print_Text();
			setCursor();
		}
		
//		setCursor();
	}	
	
}
