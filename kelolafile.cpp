#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "kelolafile.h"
#include "IOText.h"
#include "tampilan.h"

char filename[20];

void createFile(){
	
	FILE *fp1;
	int i,j;
	
	gotoxy(22,25); printf("\t\tMasukkan nama file : ");
	scanf("%s",filename);
	fp1 = fopen(filename,"w");
	fclose(fp1);
	system("cls");
//	initEditor();
	keyProsess();
}

void saveFile(){
	
	int i,j;
	char arr[MAXBARIS][MAXKOLOM];
	FILE *fp;
	fp = fopen(filename,"w");
	if(fp == NULL){
		printf("File tidak ada");
	}
	else
	{
		getData(arr);
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

void removeFile(){
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


void renameFile()
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
