#include <stdio.h>
#include <string.h>

void save_file(char FileName[30], char data[200]){
	FILE *File;

	File = fopen(FileName, "w");
    if(File==NULL)
        printf("ERROR FILE TIDAK ADA");
    else
    {
        while(strlen(data)>0)
        {
            fputs(data, File);
			fputs("\n", File);
            gets(data);
        }
    }
    fclose(File);
}