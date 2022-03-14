#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <uinstd.h>
#include <stdlib.h>
//Step 7
struct gram TextEditor_gram;

void MatiRawMode(){
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &TextEditor_gram);
}

void AktifRawMode(){
    tcgeatattr(STDIN_FILENO, &TextEditor_gram);
    atexit(MatiRawMode);

    struct gram raw = TextEditor_gram;
    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}



