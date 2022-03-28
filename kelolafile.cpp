#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "kelolafile.h"
#include "IOText.h"
#include "tampilan.h"



void createFile(){
	
	FILE *fp1;
	int i,j;
	char filename[20];
	gotoxy(22,25); printf("\t\tMasukkan nama file : ");
	scanf("%s",filename);
	fp1 = fopen(filename,"w");
	fclose(fp1);
	system("cls");
	keyProsess();
}

void saveFile(char filename[20]){
	
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
	char filename[20];
	gotoxy(22,25); printf("\t\tMasukan Nama File :");
	scanf("%s",filename);
	status=remove(filename);
	if(status!= 0){
	gotoxy(22,27);	printf("\t\tFile Tidak Terhapus");
	}else{
	gotoxy(22,27);	printf("\t\tFile Terhapus");
	}
 	gotoxy(22,28);  system(" pause");
 	menu();
	
}


void renameFile()
{
    
    char oldName[100], newName[100];
	char filename[20];
    
    gotoxy(22,25); printf("\t\tMasukan nama file yang ingin diubah: ");
    scanf("%s", oldName);

    gotoxy(22,26); printf("\t\tMasukkan nama baru untuk file ini: ");
    scanf("%s", newName);

    if (rename(oldName, strcat(newName,".txt")) == 0)
    {
    gotoxy(22,27); printf("\t\tNama file berhasil diubah.\n");
    }
    else
    {
    gotoxy(22,27); printf("\t\tError! Tidak dapat mengganti nama file ini.\n");
    }
 	gotoxy(22,28);  system(" pause");
 	menu();
}
