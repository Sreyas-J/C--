#ifndef INTERPRETER_H
#define INTERPRETER_H
//variable structure 
struct var{
    char name[20];
    int value;
};
void execute_c_minus_minus(char *code);
extern int count;   //number of variables initialized(defined in "interpreter.c")

extern struct var variables[];  //array of variables defined in "interpreter.c"

#endif /* INTERPRETER_H */
