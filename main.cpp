#include "fungsi.h"
#include <unistd.h>

int main(){

    AktifRawMode();
    
    char kata;
    while (read(STDIN_FILENO,&kata,1) == 1 && kata != 'q');
    


    return 0;
}