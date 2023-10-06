#ifndef INTERPRETER_H
#define INTERPRETER_H

struct var{
    char name[20];
    int value;
};
void execute_c_minus_minus(char *code);
extern int count;

extern struct var variables[];

#endif /* INTERPRETER_H */
