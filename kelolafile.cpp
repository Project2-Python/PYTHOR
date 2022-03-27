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
	int i, j;
	char c;
	
	gotoxy(22,25); printf("\t\tNama file : ");
	scanf("%s",filename);
	
	fedit = fopen(strcat(filename,".txt"),"r");
	if(fedit == NULL)
	{
		
		gotoxy(22,26); printf("\t\tFile tidak ada");
		gotoxy(22,27); system("\t\tpause");
		menu();
		
	} 
	
	
	system("cls");
	while(!feof(fedit)){
		fscanf(fedit, "%c", &D.data[E.baris][E.kolom]);
		printf("%c", D.data[E.baris][E.kolom]);
		if(j==MAXKOLOM-1){
			i++;
		}
		j++;
	}
	keyProsess();
	fclose(fedit);
	
}

void RemoveFile(){
	FILE *fp;
	int status;
	
	gotoxy(25,25); printf("\t\tMasukan Nama File :");
	scanf("%s",filename);
	status=remove(strcat(filename,".txt"));
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
