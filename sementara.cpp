#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "fungsi.h"
#define MAXKOLOM 8
#define MAXBARIS 4


//Modul ctrl S
//void save(){
//
//
//		
//		FILE *File;
//		File = fopen(FileName, "w"); 
//		if(File==NULL){
//			printf("ERROR FILE TIDAK ADA");
//		} else {
//			while(strlen(data)>0){
//			    	fputs(data, File);
//				fputs("\n", File);
//			    	gets(data);
//			}
//		}
//		fclose(File);
//}
	


void inputketext(){
	
	int pilihan;
	
	//Input Ke TextEditor
	char TextEditor[MAXKOLOM][MAXBARIS];
	int i,j;
	
	//Input kalimat di text editor
	for(i = 1; i <= MAXBARIS; i++){
			for(j = 1; j <= MAXKOLOM; j++){
				TextEditor[i][j] = getche();
				if(j == 8){
					printf("\n");
				} 
			}
		
	}
	
	switch(pilihan){
		case CTRL_C : 
			printf("Ini ctrl C");
			break;
		case CTRL_S :
			printf("Ini ctrl S");
			break;
		case CTRL_Q :
			printf("Ini buat keluar");
			break;
		case ENTER :
			printf("Buat new line");
	}
	
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu(){

    int input;
        
        system("cls");
        
        gotoxy(30,2); printf("                     MENU UTAMA\n");
        gotoxy(30,3); printf("           ===============================\n");
        gotoxy(30,4); printf("               TEKAN <0> UNTUK BATAL\n\n");
        gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
        gotoxy(1,6); printf("**********************************************************************************************************************\n");
    
        gotoxy(30,8);  printf("    1. OPEN FILE                 4. ABOUT\n	");
        gotoxy(30,10); printf("    2. DELETE FILE    			5. HELP\n	");
        gotoxy(30,12); printf("                  			");
        
        printf("\n\n\nPILIHAN : "); 
        scanf("%d", &input);
        
        switch(input){
            case 1:   
               
                break;
            case 2:
                 
                break;
            case 3:	
                
                break;
            case 4:
                 
                break;
            case 5:
                break;
    }
}

//void openFile (char FileName[20]){
//	
//	FILE *File;
//	char data[100]; 
//	File = fopen(FileName, "r+");
//	if(File == NULL){
//		return;
//	} 
//
//	while(!feof(File)){
//		fprintf(File, "%s\n", data); 
//		printf("%s\n", data); 
//	}
//
//	fclose(File); 
//}



