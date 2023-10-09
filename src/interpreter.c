#include "../include/variable.h"
#include "../include/arithmetic.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/interpreter.h"
#include "../include/print.h"
#include "../include/condition.h"

#define maxVariables 100    //max number of variables that can be initialized
#define stringLen 20    //used in some parts as the limit of length of variable name

int count=0;    //keeps track of the number of variables initialized
struct var variables[maxVariables]; //array of variables
void execute_c_minus_minus(char *code) {
    char *line; //contains a line of code
    char *saveptr1; // State variable for the outer strtok_r
    char *saveptr2; // State variable for the inner strtok_r
    char *saveptr3; // State variable for buffer values
    char *saveptr4; // State variable for buffer values

    line = strtok_r(code, "\n", &saveptr1);
    //loop that goes line-by-line to each line of the code
    while (line != NULL) {
        char *tok;
        tok = strtok_r(line, " ", &saveptr2);   //accesses each term in the code
    //loops through each word of the line
        while (tok != NULL) {
             //handles "if" statement logic
            if(strcmp(tok,"if")==0){
                tok=strtok_r(NULL," (",&saveptr2);
                char *newv=tok;
                tok= strtok_r(NULL," ",&saveptr2);
                char *op=tok;
                tok=strtok_r(NULL," ",&saveptr2);

                if(evaluate_condition(get_variable_value(newv),op,atoi(tok))==true){    //evaluates if the condition is true or false
                    line=strtok_r(NULL,";",&saveptr1);
                    //executes the code in if condition
                    while(strcmp(tok,"}")!=0 && line!=NULL){
                        execute_c_minus_minus(line);
                        if(line==NULL){
                            break;
                        }
                        line=strtok_r(NULL,";",&saveptr1);
                    }

                }
                //skips the code in if condition
                else{
                    while (line!=NULL && strcmp(line,"}")!=0)
                    {
                        line=strtok_r(NULL,";",&saveptr1);
                    }                 
                }
            }
            //creates variable
            else if (strcmp(tok, "int") == 0) {
                tok = strtok_r(NULL, " ", &saveptr2);
                create_variable(tok);   //creates a variable in "variables" array
                tok = strtok_r(NULL, "= ", &saveptr2);
                char *v;
                v=strtok_r(tok, ";", &saveptr3);
                tok=strtok_r(NULL," ",&saveptr2);
                char *op=tok;
                //this part is used when value is assigned by arithematic operations
                if (tok != NULL) {
                    tok=strtok_r(NULL,tok,&saveptr2);
                    char *y=strtok_r(tok,";",&saveptr3);
                    char result_str[stringLen];  
                    sprintf(result_str, "%d", perform_arithematic(get_variable_value(v),op,get_variable_value(y))); //converting the appropriate value into a string
                    assign_variable(result_str);    //assigning value to the variable
                } else {
                    assign_variable(v); //assigning the value when given directly
                }
            }

            // printing variable
            else if(strcmp(tok,"print")==0){

                tok=strtok_r(NULL," ",&saveptr2);
                char *p=strtok_r(tok,";",&saveptr4);
                char final[stringLen];
                sprintf(final,"%d",get_variable_value(tok));    //converting the value of variable to be printed into string
                print_variable(final);  //printing the value of variable
            }
            //going to next term if there's another term in the line
            if(tok!=NULL){
                tok = strtok_r(NULL, " ", &saveptr2);
            }
            else break; //going to next line if the line is completed
        }
        //going to next line if line exists
        if(line!=NULL){
            line = strtok_r(NULL, "\n", &saveptr1);
        }
        else break; //breaking out of loop if code is completed
    }
}

