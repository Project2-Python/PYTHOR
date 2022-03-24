#include "kelolafile.h"
#include "IOText.h"

void Create(){
	
	char filename[10];
	FILE *fp1;
	int i,j;
	
	system("cls");
	printf("Masukkan nama file : ");
	scanf("%s",filename);
	fp1 = fopen(strcat(filename,".txt"),"w");
	keyProsess();
	for(i = 0;i <= MAXBARIS; i++){
		for(j = 0; j <= MAXKOLOM; j++){
			putc(data[i][j],fp1);
		}
	}
	fclose(fp1);
	
}
