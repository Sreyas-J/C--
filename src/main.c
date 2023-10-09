#include <stdio.h>
#include "../include/interpreter.h"

int main() {
    //the code that will be executed
    char code[] =
        "int x = 10;\n"
        "int y = 5;\n"
        "int z = x + y;\n"
        "print z;\n"
        "if (z > 10) {\n"
        "    int w = 20;\n"
        "    print w;\n"
        "}\n";

    execute_c_minus_minus(code);    //calls the interpreter function 

    return 0;
}
