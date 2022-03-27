#include <stdio.h>

void renameFile()
{
    // Path to old and new files
    char oldName[100], newName[100];

    // Input old and new file name
    printf("masukan nama file yang ingin diubah: ");
    scanf("%s", oldName);

    printf("masukkan nama baru untuk file ini: ");
    scanf("%s", newName);


    // rename old file with new name
    if (rename(oldName, newName) == 0)
    {
        printf("Nama file berhasil diubah.\n");
    }
    else
    {
        printf("Error! Tidak dapat mengganti nama file ini.\n");
    }

}