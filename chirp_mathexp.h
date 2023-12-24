#ifndef CHIRP_MATHEXP_H
#define CHIRP_MATHEXP_H

typedef enum Lexeme {
    NUL, ADD, SUB, MUL, DIV, NUM, ERR
} Lexeme;

typedef struct LexData {
    Lexeme lexeme;
    int status;
} LexData;

int lexer(LexData *data, int length);
void print_lexdata(const LexData *data, int length);

#endif
