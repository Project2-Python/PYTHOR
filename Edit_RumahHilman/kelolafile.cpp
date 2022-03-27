#include "kelolafile.h"
#include "IOText.h"
#include "tampilan.h"

char filename[10];

void Create(){
	
	FILE *fp1;
	int i,j;
	
	gotoxy(22,25); printf("\t\tMasukkan nama file : ");
	scanf("%s",filename);
	fp1 = fopen(strcat(filename,".txt"),"w");
	fclose(fp1);
	
}

void SaveFile(){
	
	int i,j;
	char arr[MAXBARIS][MAXKOLOM];
	FILE *fp;
	fp = fopen(filename,"r+");
	if(fp == NULL){
		printf("File tidak ada");
	}
	else
	{
		GetData(arr);
		for(i=0;i<MAXBARIS;i++){
			for(j=0;j<MAXKOLOM;j++){
				fprintf(fp,"%c",arr[i][j]);
			}
			fprintf(fp,"\n");
		}
	}
	fclose(fp);
}

void EditFile(){
	
	FILE *fedit;
	char c;
	
	gotoxy(22,25); printf("\t\tNama file : ");
	scanf("%s",filename);
	
	fedit = fopen(strcat(filename,".txt"),"r+");
	if(fedit == NULL)
	{
		
		gotoxy(22,26); printf("\t\tFile tidak ada");
		gotoxy(22,27); system("\t\tpause");
		menu();
		
	} else {
		
		while(!feof(fedit)){
			D.data[i][j]=getch(fedit);
    		
		}
		
	}
	system("cls");
	keyProsess();
	fclose(fedit);
	
	
}
