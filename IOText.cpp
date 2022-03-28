#include <stdio.h>
#include <conio.h>
#include <string.h>
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

void getData(char data[MAXBARIS][MAXKOLOM]){
	
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

void deleteChar(){
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
   break;
  case 80: // DOWN
   if(E.destcord.Y < getLastY()){
    E.destcord.Y++;
    if(E.destcord.X > getLastX(E.destcord.Y)){
    	E.destcord.X = getLastX(E.destcord.Y);
	}	
   }
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
 //struct editor E;
 //struct data D;
 E.destcord.X = 0;
 E.destcord.Y = 0;
 E.baris = 0;
 E.kolom = 0;
}

void openFile(){
	
	FILE *fedit;
	int i, j;
	char c, filename[20];;
	gotoxy(22,25); printf("\t\tNama file : ");
	scanf("%s", filename);
	
	fedit = fopen(filename,"r");
	if(fedit == NULL)
	{
		
		gotoxy(22,26); printf("\t\tFile tidak ada");
		gotoxy(22,27); system("\t\tpause");
		menu();
		
	} 
	
	
	system("cls");
	E.baris = 0;
	E.kolom = 0;
	while(!feof(fedit)){
		c = fgetc(fedit);
		if(c == -1){
			break;
		}
		D.data[E.baris][E.kolom] = c;
		printf("%c", D.data[E.baris][E.kolom]);
		if(c == '\n'){
			E.kolom = 0;
			E.baris++;
		} else {
			E.kolom++;
		}
		if(E.kolom > MAXKOLOM){
			printf("\n");
			E.kolom = 0;
			E.baris++;
		}
		if(E.baris > MAXBARIS){
			break;
		}
	}
	fclose(fedit);
 	E.destcord.X = E.kolom;
 	E.destcord.Y = E.baris;
	keyProsess(filename);
}

void keyProsess(char filename[20]){
 char temp;
 E.hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
 gotoxy(0,40); 	printf("=======================================================================================================================\n");
 gotoxy(0,41); 	printf("Ctrl+S = Save \t ESC = Save & Exit \t ENTER = New Line");

 while(1){
  SetConsoleCursorPosition(E.hstdout, E.destcord);
  temp = getch();
  if(temp == -32){                       // Arrow
   moveCursor();

  } else if(temp == '\b'){              // Backspace
   deleteChar();

  }else if(temp == '\x1b') {            // Ecscape
  	saveFile(filename);
	memset(D.data, 0, sizeof(D.data));
	menu();

  } else if(temp == CTRL_S){		//save
  	saveFile(filename);
  	
  }else {
   insertion(temp);                  // Input Data
   setCursor();
  }
 }
 
  
}
