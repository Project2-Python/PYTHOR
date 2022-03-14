
#include "fungsi.h"
#include <unistd.h>

int main(){

    AktifRawMode();
    
    char kata;
    while (read(STDIN_FILENO,&kata,1) == 1 && kata != 'q');{
        if(iscntrl(c)){
            printf("%d\n", c);
        } else {
            printf("%d('%c'\n",kata,kata);
        }
    }

    return 0;
}
