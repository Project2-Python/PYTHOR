#include "IOText.h"


char data[MAXBARIS][MAXKOLOM];
int baris, kolom;

HANDLE hstdout;
COORD destcord;


void insertion(int key){
 
 if(key == '\r'){
  data[baris][kolom] = '\n';
 } else {
  data[baris][kolom] = key;
  printf("%c", data[baris][kolom]);
 }
}

void Delete(){
 --destcord.X;
 SetConsoleCursorPosition(hstdout, destcord);
 if(destcord.X < 0){
  destcord.X = 0; 
  if(destcord.Y > 0){
   destcord.X = MAXKOLOM+1;
   destcord.Y--;
  }
 }
 kolom -= 1;
 data[baris][kolom]= '\0';
 printf(" ", '\b');
}




void moveCursor(){
 char temp = getch();
 switch(temp){
  case 72: // UP
   if(destcord.Y == 0){
    destcord.Y = MAXBARIS;
//    baris = MAXBARIS;
   } else {
    destcord.Y--;
//    baris--;
   }
   break;
  case 75: // LEFT
   if(destcord.X == 0){
    destcord.X == MAXKOLOM;
//    kolom = MAXKOLOM;
   } else {
    destcord.X--;
//    kolom--;
   }
   break;
  case 77:// RIGHT
   if(destcord.X == MAXKOLOM){
    destcord.X = 0;
//    kolom = 0;
   } else {
    destcord.X++;
//    kolom++;
   }
   break;
  case 80: // DOWN
   if(destcord.Y == MAXBARIS){
    destcord.Y = 0;
//    baris = 0;
   } else {
    destcord.Y++;
//    baris++;
   }
 }
}

void setCursor(){
  destcord.X;
  destcord.Y;
  
  if(destcord.X == MAXKOLOM-1){
   if(destcord.Y == MAXBARIS-1){
    system("pause");
    } else {
     destcord.X = 0;
    kolom = 0;
    destcord.Y++;
    baris++;
       }
  } else if(data[baris][kolom] == '\n'){
   if(destcord.Y == MAXBARIS-1){
    system("pause");
   } else {
    destcord.X = 0;
    kolom = 0;
    destcord.Y++;
    baris++;
   }
   
  } else {
   destcord.X++;
   kolom++;
  }
}

void initEditor(){
 destcord.X = 0;
 destcord.Y = 0;
 baris = 0;
 kolom = 0;
}

void keyProsess()
{
	
	 hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	 system("cls");
	 while(1)
	 	{
	 
		 SetConsoleCursorPosition(hstdout, destcord);
		 data[baris][kolom] = getch();
		 if(data[baris][kolom] == -32){                       // Arrow
		  moveCursor();
		   
		 } else if(data[baris][kolom] == '\b'){              // Backspace
		  Delete();
		   
		 }else if(data[baris][kolom] == '\x1b') {            // Ecscape
		  return;
		   
		 } else {
		  insertion(data[baris][kolom]);                  // Input Data
		  setCursor();
		 }
	
		}
	  
}


