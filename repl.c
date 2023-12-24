#include "chirp_mathexp.h"

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    LexData lexemes[20];
    while (true) {
        printf("? ");
        int nlex = lexer(lexemes, 20);
        printf("> ");
        print_lexdata(lexemes, nlex);
    }
    return 0;
}
