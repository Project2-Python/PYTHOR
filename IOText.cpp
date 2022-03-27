#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "IOText.h"
#include "kelolafile.h"
#include "tampilan.h"

int getLastX(int baris){
	int kolom, result;
	result = 0;
	for(kolom=0; kolom<MAXKOLOM; kolom++){
		if(D.data[baris][kolom] == '\000' || D.data[baris][kolom] == -32){
			break;
		}
		result++;
	}
	return result;
}

int getLastY(){
	int baris, result;
	result = 0;
	for(baris=1; baris<MAXBARIS; baris++){
		if(D.data[baris][0] == '\000'){
			break;
		}
		result++;
	}
	return result;
}

void print(char Arr[MAXBARIS][MAXKOLOM]){
 int i, j;
 for(i=0; i<MAXBARIS; i++){
  for(j=0; j<MAXKOLOM; j++){
   printf("%c", Arr[i][j]);
  }
  printf("\n");
 }
}


void GetData(char data[MAXBARIS][MAXKOLOM]){
	
	int i,j;
	for(i=0; i<MAXBARIS;i++){
		for(j=0;j<MAXKOLOM;j++){
			data[i][j] = D.data[i][j];
		}
	}
	
}

void insertion(int key){
 
 if(key == '\r'){
  D.data[E.baris][E.kolom] = NULL;
  printf("\n");
 } else {
  D.data[E.baris][E.kolom] = key;
  printf("%c", D.data[E.baris][E.kolom]);
 }
}

void Delete(){
 --E.destcord.X;
 SetConsoleCursorPosition(E.hstdout, E.destcord);
 if(E.destcord.X < 0){
  E.destcord.X = 0; 
  if(E.destcord.Y > 0){
   E.destcord.Y--;
   E.destcord.X = getLastX(E.destcord.Y);
  }
 }
 E.kolom = E.destcord.X;
 E.baris = E.destcord.Y;
 D.data[E.baris][E.kolom]= NULL;
 printf(" ", '\b');
}




void moveCursor(){
 char temp = getch();
 switch(temp){
  case 72: // UP
   if(E.destcord.Y > 0){
    E.destcord.Y--;
    if(E.destcord.X > getLastX(E.destcord.Y)){
    	E.destcord.X = getLastX(E.destcord.Y);
	}
   }
   //E.baris = E.destcord.Y;
   break;
  case 75: // LEFT
   if(E.destcord.X == 0){
   	if(E.destcord.Y > 0){
   		E.destcord.Y--;
   		E.destcord.X = getLastX(E.destcord.Y);
	   }
   } else {
    E.destcord.X--;
   }
   //E.kolom = E.destcord.X;
   break;
  case 77:// RIGHT
   if(E.destcord.X == getLastX(E.destcord.Y)){
   	if(E.destcord.Y < getLastY()){
    	E.destcord.X = 0;
    	E.destcord.Y++;
	   }
   } else {
    E.destcord.X++;
   }
   //E.kolom = E.destcord.X;
   break;
  case 80: // DOWN
   if(E.destcord.Y < getLastY()){
    E.destcord.Y++;
    if(E.destcord.X > getLastX(E.destcord.Y)){
    	E.destcord.X = getLastX(E.destcord.Y);
	}	
   }
   //E.baris = E.destcord.Y;
   break;
 }
 E.kolom = E.destcord.X;
 E.baris = E.destcord.Y;
}

void setCursor(){
  
  if(E.destcord.X == MAXKOLOM-1){
   if(E.destcord.Y == MAXBARIS-1){
    
    } else {
     E.destcord.X = 0;
    E.kolom = 0;
    E.destcord.Y++;
    E.baris++;
       }
  } else if(D.data[E.baris][E.kolom] == NULL){
   if(E.destcord.Y == MAXBARIS-1){
    
   } else {
    E.destcord.X = 0;
    E.kolom = 0;
    E.destcord.Y++;
    E.baris++;
   }
   
  } else {
   E.destcord.X++;
   E.kolom++;
  }
}

void initEditor(){
 E.destcord.X = 0;
 E.destcord.Y = 0;
 E.baris = 0;
 E.kolom = 0;
}

void keyProsess(){
 printf("\n%d %d", E.baris, E.kolom);
 E.destcord.X = E.kolom;
 E.destcord.Y = E.baris;
 E.hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
 while(1){
  SetConsoleCursorPosition(E.hstdout, E.destcord);
  D.data[E.baris][E.kolom] = getch();
  if(D.data[E.baris][E.kolom] == -32){                       // Arrow
   moveCursor();
   
  }else if(D.data[E.baris][E.kolom] == '\b'){              // Backspace
   Delete();
   
  }else if(D.data[E.baris][E.kolom] == '\x1b') {            // Ecscape
  	SaveFile();
	menu();
   
  }else if(D.data[E.baris][E.kolom] == CTRL_S){
  	SaveFile();
  }
  else {
   insertion(D.data[E.baris][E.kolom]);                  // Input Data
   setCursor();
  }
 }
 
  
}
