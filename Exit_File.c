#include "save_file.h"
#define Waktu_Exit_ 3

void exit_file(char FileName[30], char data[200]){
	int InputKeyboard;
    	int Waktu_Exit = Waktu_Exit_;
	while (IsPerubahan && Waktu_Exit > 0){
		printf("PERHATIAN!! FILE BELUM DI SAVE.\n");
		printf("TEKAN CTRL-Q SEBANYAK %d UNTUK KELUAR\n", Waktu_Exit);
		scanf("%d", &InputKeyboard);
		if(InputKeyboard == 2){
			save_file(FileName, data);
			printf("AKHIRNYA FILE SUDAH DI SAVE\n");
		}
		Waktu_Exit--; 
	}
	printf("TERIMAKASIH ");
}
