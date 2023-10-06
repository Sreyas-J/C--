// #include<stdbool.h>
#include<string.h>
#include "../include/condition.h"

bool evaluate_condition(int x,char *op,int y){ 
    if(strcmp(op,">")==0){
        if(x>y) return true;
        return false;
    }
    else if(strcmp(op,"<")==0){
        if(x<y) return true;
        return false;
    }
    else if(strcmp(op,"==")==0){
        if(x==y) return true;
        return false;
    }
    else if(strcmp(op,">=")==0){
        if(x>=y) return true;
        return false;
    }
    else if(strcmp(op,"<=")==0){
        if(x<=y) return true;
        return false;
    }
}