#include "../include/variable.h"
#include "../include/interpreter.h"
#include<string.h>
#include<stdlib.h>
//adds variable to "variables" array at "count" position
void create_variable(char *token){
    strcpy(variables[count].name,token);
}
//writes the value of the variable
void assign_variable(char *token){
    variables[count].value=atoi(token);
    count++;
}

int get_variable_value(char *var_name){
    int i=0;
    while(1){
        if(strcmp(variables[i].name,var_name)==0){
            return variables[i].value;  //returns the value of a given variable
        }
        i++;
    }
}