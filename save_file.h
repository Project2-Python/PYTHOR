
#include <stdio.h>
#include <string.h>

//Variabel Global
int IsPerubahan;  // Sebagai penanda apakah ada perubahan data, jika ada akan bernilai 1 
                 // Namun jika tidak ada akan bernilai 0 
                 // fungsinya agar ketika ingin Exit File tapi belum di Save maka variabel ini akan bernilai 1
                  

void save_file(char FileName[30], char data[200]);

