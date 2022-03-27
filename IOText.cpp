#include "IOText.h"
#include "kelolafile.h"
#include "tampilan.h"
#include <conio.h>


void print(char Arr[MAXBARIS][MAXKOLOM]){
 int i, j;
 for(i=0; i<MAXBARIS; i++){
  for(j=0; j<MAXKOLOM; j++){
   printf("%c", Arr[i][j]);
  }
  printf("\n");
 }
}

void GetFileData(char fileData[MAXBARIS][MAXKOLOM]){
	int i, j;
	for(i=0; i<MAXBARIS; i++){
		for(j=0; j<MAXKOLOM; j++){
			D.data[i][j] = fileData[i][j];
		}
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
   E.destcord.X = MAXKOLOM+1;
   E.destcord.Y--;
  }
 }
 E.kolom -= 1;
 D.data[E.baris][E.kolom]= NULL;
 printf(" ", '\b');
}




void moveCursor(){
 char temp = getch();
 switch(temp){
  case 72: // UP
   if(E.destcord.Y == 0){
    E.destcord.Y = MAXBARIS;
   } else {
    E.destcord.Y--;
   }
//   E.baris = E.destcord.Y;
   break;
  case 75: // LEFT
   if(E.destcord.X == 0){
    E.destcord.X == MAXKOLOM;
   } else {
    E.destcord.X--;
   }
//   E.kolom = E.destcord.X;
   break;
  case 77:// RIGHT
   if(E.destcord.X == MAXKOLOM){
    E.destcord.X = 0;
   } else {
    E.destcord.X++;
   }
//   E.kolom = E.destcord.X;
   break;
  case 80: // DOWN
   if(E.destcord.Y == MAXBARIS){
    E.destcord.Y = 0;
   } else {
    E.destcord.Y++;   	
   }
//   E.baris = E.destcord.Y;
   break;
 }
// E.baris = E.destcord.Y;
// E.kolom = E.destcord.X;
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
 
 E.hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
 while(1){
	tahan:
  SetConsoleCursorPosition(E.hstdout, E.destcord);
  D.data[E.baris][E.kolom] = getch();
  if(D.data[E.baris][E.kolom] == -32){                       // Arrow
   moveCursor();
   
  } else if(D.data[E.baris][E.kolom] == '\b'){              // Backspace
   Delete();
   
  }else if(D.data[E.baris][E.kolom] == '\x1b') {            // Ecscape
  	  SaveFile();
	  menu();
   
  } else if(D.data[E.baris][E.kolom] == CTRL_S){		//save
  	SaveFile();
  	
  }else if(D.data[E.baris][E.kolom] == CTRL_I){
  	CommandLine();
  	
  }else if(D.data[E.baris][E.kolom] == CTRL_N){
  	system("cls");
  	goto tahan;
  }else {
   insertion(D.data[E.baris][E.kolom]);                  // Input Data
   setCursor();
  }
 }
 
  
}
