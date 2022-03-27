#include "kelolafile.h"
#include "tampilan.h"
#include "IOText.h"



void menu(){

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
        gotoxy(22,20);	printf("\t\t|              Made by Python Team (2)             |");
        gotoxy(22,21);	printf("\t\t|                                                  |");
        gotoxy(22,22);	printf("\t\t+==================================================+");
        gotoxy(22,23);	printf("\t\tPilihan Menu: ");
        
        choice = getch();
        choice = toupper(choice);
        putchar(choice);

        switch(choice) {
            case '1':
                Create();
                system("cls");
                keyProsess();
                break;
            case '2':
            	EditFile();
                break;
            case '3':
                RenameFile();
                break;
            case '4':
                RemoveFile();
                break;
            case '5':
                documentation();
                break;
            case '6':
            	ExitScreen();
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
	gotoxy(24,1);	printf("=============================================================================\n");
	gotoxy(24,2); 	printf("|                                   PYTHOR                                   |\n");							
	gotoxy(24,3);	printf("|                            (Python Text Editor)                            |\n");	     				    
	gotoxy(24,4);	printf("=============================================================================\n");
	gotoxy(24,5);	printf("| Pythor adalah suatu program komputer yang digunakan untuk membuat,         |\n");
    gotoxy(24,6); 	printf("| mengubah, mengedit, ataupun menyimpan suatu text.                          |\n");
	gotoxy(24,7);	printf("| Pembuatan pythor ini, disusun oleh :                                       |\n");
  	gotoxy(24,8);	printf("| 1. Aprillia Rahmawati                                                      |\n");
   	gotoxy(24,9);	printf("| 2. Hilman Permana                                                          |\n");
   	gotoxy(24,10);	printf("| 3. Irfan Khaerul Mupid                                                     |\n");
   	gotoxy(24,11);	printf("| 4. Muhammad Andhika Prasetya                                               |\n");
  	gotoxy(24,12);	printf("| 5. Wildan Setya Nugraha                                                    |\n");
	gotoxy(24,13);	printf("*****************************************************************************|\n");
	gotoxy(24,14);	printf("|Adapun penjelasan fitur-fitur yang ada di dalam text editor ini, diantanya  |\n");
    gotoxy(24,15);	printf("|a. Create File    -> berfungsi untuk membuat file baru                      |\n");
	gotoxy(24,16);	printf("|b. Open/Edit File -> berfungsi untuk membuka file atau mengedit file        |\n");
	gotoxy(24,17);	printf("|c. Copy/Paste Text-> berfungsi untuk menyalin maupun menempelkan teks       |\n");
	gotoxy(24,18);	printf("|                     yang sebelumnya sudah disalin                          |\n");
	gotoxy(24,19);	printf("|d. Rename File    -> berfungsi untuk mengganti nama file                    |\n");
	gotoxy(24,20);	printf("|e. Delete File	   -> berfungsi untuk menghapus file                         |\n");
	gotoxy(24,21);	printf("|f. Documentation  -> berfungsi unt menjelaskan tentang identitas program    |\n");
	gotoxy(24,22);	printf("|g. Exit           -> berfungsi untuk keluar dari program yang sedang        |\n");
	gotoxy(24,23);	printf("|                     di jalankan                                            |\n");
 	gotoxy(24,24);	printf("=============================================================================|\n");
 	gotoxy(24,25);  system("pause");
}

void LoadingScreen(){
	
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

void ExitScreen(){
	
	system("cls");
	gotoxy(35,9); 	printf("              =======================");
	gotoxy(35,11);	printf("              =======================");
	Sleep(500); 
	gotoxy(35,10); 	printf("                BYE ");
	Sleep(500);
				   	printf("BYE ");
	Sleep(500);
				   	printf("PYTHOR ");
	Sleep(500);
				   	printf("USER ");
	printf("\n\n\n\n\n\n\n\n\n");
				   
	
}

void CommandLine(){
	
	system("cls");
	gotoxy(0,40); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
	
}

