#include "../include/variable.h"
#include "../include/interpreter.h"
#include<string.h>
#include<stdlib.h>

void create_variable(char *token){
    strcpy(variables[count].name,token);
}

void assign_variable(char *token){
    variables[count].value=atoi(token);
    count++;
}

int get_variable_value(char *var_name){
    int i=0;
    while(1){
        if(strcmp(variables[i].name,var_name)==0){
            return variables[i].value;
        }
        i++;
    }
}