#include "../include/arithmetic.h"
#include<string.h>
//returns int value of the arithematic operation
int perform_arithematic(int x,char *op,int y){
    if(strcmp(op,"+")==0){
        return x+y;
    }
    else if(strcmp(op,"-")==0){
        return x-y;
    }
    else if(strcmp(op,"/")==0){
        return x/y;
    }
    else if(strcmp(op,"*")==0){
        return x*y;
    }
}