#include "chirp_mathexp.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ISNUM(ch)       (ch >= '0' && ch <= '9')
#define CHARTOINT(ch)   (ch - '0')

int lexer(LexData *datarr, int length) 
{
    int cursor = 0, ch = getchar();
    while (cursor < length) {
        switch (ch) {
            case '+':
                datarr[cursor].lexeme = ADD;
                datarr[cursor].status = 0;
                ch = getchar();
                ++cursor;
                break;
            case '-':
                datarr[cursor].lexeme = SUB;
                datarr[cursor].status = 0;
                ch = getchar();
                ++cursor;
                break;
            case '*':
                datarr[cursor].lexeme = MUL;
                datarr[cursor].status = 0;
                ch = getchar();
                ++cursor;
                break;
            case '/':
                datarr[cursor].lexeme = DIV;
                datarr[cursor].status = 0;
                ch = getchar();
                ++cursor;
                break;
            case 'q':
                exit(0);
                break;
            default:
                if (ISNUM(ch)) {
                    datarr[cursor].lexeme = NUM;
                    datarr[cursor].status = 0;
                    while (ISNUM(ch)) {
                        datarr[cursor].status = 10 * datarr[cursor].status + CHARTOINT(ch);
                        ch = getchar();
                    }
                    ++cursor;
                    break;
                }
                else if (ch == '\n') return cursor;
                else if (isspace(ch)) {
                    ch = getchar();
                    break;
                }
                datarr[cursor].lexeme = ERR;
                datarr[cursor].status = 0;
                ch = getchar();
                break;
        }
    }
    return cursor;
}

void print_lexdata(const LexData *datarr, int length)
{
    for (int i = 0; i < length; ++i) {
        switch (datarr[i].lexeme) {
            case NUL:
                printf("--- ");
                break;
            case ADD:
                printf("ADD ");
                break;
            case SUB:
                printf("SUB ");
                break;
            case MUL:
                printf("MUL ");
                break;
            case DIV:
                printf("DIV ");
                break;
            case NUM:
                printf("NUM(%d) ", datarr[i].status);
                break;
            case ERR:
                printf("ERR ");
                break;
            default:
                printf("??? ");
                break;
        }
    }
    putchar('\n');
}
