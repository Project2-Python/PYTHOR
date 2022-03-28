#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "kelolafile.h"
#include "tampilan.h"
#include "IOText.h"



void menu(){
   initEditor();
   char choice;
   
        system("cls");
        gotoxy(22,1);	printf("\t\t+==================================================+");
        gotoxy(22,2);	printf("\t\t|                                                  |");
        gotoxy(22,3);	printf("\t\t|                      PYTHOR                      |");
        gotoxy(22,4);	printf("\t\t|                Python Text Editor                |");
        gotoxy(22,5);	printf("\t\t|        A simple text editor written in C         |");
        gotoxy(22,6);	printf("\t\t|                                                  |");
        gotoxy(22,7);	printf("\t\t+==================================================+");
        gotoxy(22,8);	printf("\t\t|                                                  |");
        gotoxy(22,9);	printf("\t\t|     MENU:                                        |");
        gotoxy(22,10);	printf("\t\t|  1. Create New File                              |");
        gotoxy(22,11);	printf("\t\t|  2. Open/Edit File                               |");
        gotoxy(22,12);	printf("\t\t|  3. Rename File                                  |");
        gotoxy(22,13);	printf("\t\t|  4. Delete File                                  |");
        gotoxy(22,14);	printf("\t\t|  5. Documentation                                |");
        gotoxy(22,15);	printf("\t\t|  6. Exit                                         |");
        gotoxy(22,16);	printf("\t\t|                                                  |");
        gotoxy(22,17);	printf("\t\t|                                                  |");
        gotoxy(22,18);	printf("\t\t+==================================================+");
        gotoxy(22,19);	printf("\t\t|                                                  |");
        gotoxy(22,20);	printf("\t\t|                Made by Python Team               |");
        gotoxy(22,21);	printf("\t\t|                                                  |");
        gotoxy(22,22);	printf("\t\t+==================================================+");
        gotoxy(22,23);	printf("\t\tPilihan Menu: ");
        
        choice = getch();
        choice = toupper(choice);
        putchar(choice);

        switch(choice) {
            case '1':
                createFile();
                break;
            case '2':
            	openFile();
                break;
            case '3':
                renameFile();
                break;
            case '4':
                removeFile();
                break;
            case '5':
                documentation();
                break;
            case '6':
            	exitScreen();
                exit(1);
                break;
            default:
            gotoxy(22,25);printf("\t\tMasukkan Tidak Sesuai!");
                Sleep(1000);
                menu();
        }
    
	
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void documentation(){
	
	system("cls");
	gotoxy(22,1);	printf("+============================================================================+\n");
	gotoxy(22,2);	printf("|                                                                            |\n");
	gotoxy(22,3); 	printf("|                                   PYTHOR                                   |\n");							
	gotoxy(22,4);	printf("|                            (Python Text Editor)                            |\n");	
	gotoxy(22,5);	printf("|                                                                            |\n");     				    
	gotoxy(22,6);	printf("+============================================================================+\n");
	gotoxy(22,7);	printf("|                                                                            |\n");
	gotoxy(22,8);	printf("| PYTHOR adalah suatu program komputer yang digunakan untuk membuat,         |\n");
    gotoxy(22,9); 	printf("| mengubah, mengedit, ataupun menyimpan suatu text ke dalam file.            |\n");
	gotoxy(22,10);	printf("| Dibuat oleh Python Team beranggotakan:                                     |\n");
  	gotoxy(22,11);	printf("| 1. Aprillia Rahmawati                                                      |\n");
   	gotoxy(22,12);	printf("| 2. Hilman Permana                                                          |\n");
   	gotoxy(22,13);	printf("| 3. Irfan Khaerul Mupid                                                     |\n");
   	gotoxy(22,14);	printf("| 4. Muhammad Andhika Prasetya                                               |\n");
  	gotoxy(22,15);	printf("| 5. Wildan Setya Nugraha                                                    |\n");
	gotoxy(22,16);	printf("|                                                                            |\n");
	gotoxy(22,17);	printf("+============================================================================+\n");
	gotoxy(22,18);	printf("|                                                                            |\n");
	gotoxy(22,19);	printf("| Fitur PYTHOR:                                                              |\n");
    gotoxy(22,20);	printf("| 1. Create File    -> untuk membuat dan mengedit file baru                  |\n");
	gotoxy(22,21);	printf("| 2. Open/Edit File -> untuk membuka dan mengedit file                       |\n");
	gotoxy(22,22);	printf("| 3. Rename File    -> untuk mengganti nama file                             |\n");
	gotoxy(22,23);	printf("| 4. Delete File    -> untuk menghapus file                                  |\n");
	gotoxy(22,24);	printf("|                                                                            |\n");
 	gotoxy(22,25);	printf("+============================================================================+\n");
 	gotoxy(22,26);  system(" pause");
 	menu();
}

void loadingScreen(){
	
	system("cls");
	
		gotoxy(35,9); printf("              =======================");
		gotoxy(35,10);printf("               MOHON TUNGGU SEBENTAR");
		gotoxy(35,12);printf("              =======================");
		
		Sleep(700);
		gotoxy(35,11);printf("                     . ");
		Sleep(700);
		printf(". ");
		Sleep(700);
		printf(". ");
		Sleep(700);
		printf(". ");
		Sleep(700);
		printf(". ");
	
}

void exitScreen(){
	
	system("cls");
	gotoxy(35,9); 	printf("              =======================");
	gotoxy(35,11);	printf("              =======================");
	Sleep(300); 
	gotoxy(35,10); 	printf("                BYE ");
	Sleep(300);
				   	printf("BYE ");
	Sleep(300);
				   	printf("PYTHOR ");
	Sleep(300);
				   	printf("USER ");
	printf("\n\n\n\n\n\n\n\n\n");
				   
	
}

void commandLine(){
	int y2 	= MAXBARIS ;
	gotoxy(0,y2+1); 	printf("=======================================================================================================================\n");
	gotoxy(0,y2+2); 	printf("Ctrl+S = Save \t ESC = Save & Exit \t ENTER = New Line");
}

