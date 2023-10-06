#include "../include/variable.h"
#include "../include/arithmetic.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/interpreter.h"
#include "../include/print.h"
#include "../include/condition.h"

#define maxVariables 100
#define stringLen 20

int count=0;
struct var variables[maxVariables];
void execute_c_minus_minus(char *code) {
    char *line;
    char *saveptr1; // State variable for the outer strtok_r
    char *saveptr2; // State variable for the inner strtok_r
    char *saveptr3;
    char *saveptr4;

    line = strtok_r(code, "\n", &saveptr1);

    while (line != NULL) {
        char *tok; 
        tok = strtok_r(line, " ", &saveptr2);

        while (tok != NULL) {
             //conditions
            if(strcmp(tok,"if")==0){
                tok=strtok_r(NULL," (",&saveptr2);
                char *newv=tok;
                tok= strtok_r(NULL," ",&saveptr2);
                char *op=tok;
                tok=strtok_r(NULL," ",&saveptr2);

                if(evaluate_condition(get_variable_value(newv),op,atoi(tok))==true){
                    line=strtok_r(NULL,";",&saveptr1);

                    while(strcmp(tok,"}")!=0 && line!=NULL){
                        execute_c_minus_minus(line);
                        if(line==NULL){
                            break;
                        }
                        line=strtok_r(NULL,";",&saveptr1);
                    }

                }
                else{
                    while (line!=NULL && strcmp(line,"}")!=0)
                    {
                        line=strtok_r(NULL,";",&saveptr1);
                    }                 
                }
            }
            else if (strcmp(tok, "int") == 0) {
                tok = strtok_r(NULL, " ", &saveptr2);
                create_variable(tok);
                tok = strtok_r(NULL, "= ", &saveptr2);
                char *v;
                v=strtok_r(tok, ";", &saveptr3);
                tok=strtok_r(NULL," ",&saveptr2);
                char *op=tok;
                //printf("op: %s\n",op);

                if (tok != NULL) {
                    tok=strtok_r(NULL,tok,&saveptr2);
                    //printf("tok: %s\n",tok);
                    char *y=strtok_r(tok,";",&saveptr3);
                    char result_str[stringLen];  
                    sprintf(result_str, "%d", perform_arithematic(get_variable_value(v),op,get_variable_value(y)));
                    assign_variable(result_str);
                } else {
                    assign_variable(v);
                }
            }

            // printing variable
            else if(strcmp(tok,"print")==0){

                tok=strtok_r(NULL," ",&saveptr2);
                char *p=strtok_r(tok,";",&saveptr4);
                char final[stringLen];
                sprintf(final,"%d",get_variable_value(tok));
                print_variable(final);
            }

            if(tok!=NULL){
                tok = strtok_r(NULL, " ", &saveptr2);
            }
            else break;
        }

        if(line!=NULL){
            line = strtok_r(NULL, "\n", &saveptr1);
        }
        else break;
    }
}

