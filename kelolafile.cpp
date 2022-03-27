#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "kelolafile.h"
#include "IOText.h"
#include "tampilan.h"

char filename[10];

void Create(){
	
	FILE *fp1;
	int i,j;
	
	gotoxy(22,25); printf("\t\tMasukkan nama file : ");
	scanf("%s",filename);
	fp1 = fopen(filename,"w");
	fclose(fp1);
	
}

void SaveFile(){
	
	int i,j;
	char arr[MAXBARIS][MAXKOLOM];
	FILE *fp;
	fp = fopen(filename,"w");
	if(fp == NULL){
		printf("File tidak ada");
	}
	else
	{
		GetData(arr);
		for(i=0;i<MAXBARIS;i++){
			for(j=0;j<MAXKOLOM;j++){
				if(arr[i][j]=='\033' || arr[i][j]=='\000' || arr[i][j]=='\023' || arr[i][j]==-32 || arr[i][j]=='\b'){
					if(arr[i][j+1] == '\000'){
						break;
					}
				} else {
					fprintf(fp,"%c",arr[i][j]);
				}
			}
			if(arr[i+1][0] == '\000'){
				break;
			}
			fprintf(fp,"\n");
		}
	}
	fclose(fp);
}

void OpenFile(){
	
	FILE *fedit;
	int i, j;
	char c;
	gotoxy(22,25); printf("\t\tNama file : ");
	scanf("%s",filename);
	
	fedit = fopen(filename,"r");
	if(fedit == NULL)
	{
		
		gotoxy(22,26); printf("\t\tFile tidak ada");
		gotoxy(22,27); system("\t\tpause");
		menu();
		
	} 
	
	
	system("cls");
	while(!feof(fedit)){
		c = fgetc(fedit);
		D.data[E.baris][E.kolom] = c;
		printf("%c", D.data[E.baris][E.kolom]);
		if(c == '\n'){
			E.kolom = 0;
			E.baris++;
		} else {
			E.kolom++;
		}
		if(E.kolom > MAXKOLOM){
			E.kolom = 0;
			E.baris++;
		}
		if(E.baris > MAXBARIS){
			break;
		}
	}
	fclose(fedit);
	
}

void RemoveFile(){
	FILE *fp;
	int status;
	
	gotoxy(25,25); printf("\t\tMasukan Nama File :");
	scanf("%s",filename);
	status=remove(filename);
	if(status!= 0){
	gotoxy(25,27);	printf("\t\tFile Tidak Terhapus");
	}else{
	gotoxy(25,27);	printf("\t\tFile Terhapus");
	}
	
}


void RenameFile()
{
    
    char oldName[100], newName[100];

    
    gotoxy(25,25); printf("\t\tMasukan nama file yang ingin diubah: ");
    scanf("%s", oldName);

    gotoxy(25,26); printf("\t\tMasukkan nama baru untuk file ini: ");
    scanf("%s", newName);

    if (rename(oldName, strcat(newName,".txt")) == 0)
    {
    gotoxy(25,27); printf("\t\tNama file berhasil diubah.\n");
    }
    else
    {
    gotoxy(25,27); printf("\t\tError! Tidak dapat mengganti nama file ini.\n");
    }

}
