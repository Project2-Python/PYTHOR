#include <stdio.h>
#include <iostream>
#include <fstream>
#define MAX 4
#define MIN 4

using namespace std;
char filename[15];

void createFile(){
	FILE *fp;
	
	printf("Masukan Nama FIle \n");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	
	if(fp!=NULL){
		printf("File berhasil dibuat");
		
	}else{
		printf("file gagal");
		
	}
}

void RemoveFile(){
	FILE *fp;
	printf("Masukan Nama File :");
	scanf("%s",filename);
	remove(filename);
	if(fp!=NULL){
		printf("File Terhapus");
	}else{
		printf("File Tidak Terhapus");
	}
	
}
int main(){
	
	int pil;
	aksen:
	printf("Masukan Pilihan :");
	scanf("%d",&pil);
	switch(pil){
		case 1:
			
			createFile();
			goto aksen;
			break;
		
		case 2:
			RemoveFile();
			break;
		case 0:
			return 0;
		
	}
		

	return 0;
}
