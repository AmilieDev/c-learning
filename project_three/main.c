#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void){

    char user_answer[50];
    char best_subject[50] = "Computer Science";
    bool answer_status = false;

    while(answer_status == false){
        printf("What is your favourite subject? \n");
        fgets(user_answer, sizeof(user_answer), stdin);
        user_answer[strcspn(user_answer, "\n")] = '\0';


        if (strcmp(user_answer, best_subject) == 0){
            printf("Of course it is!\n");
            answer_status = true;
        }else{
            printf("Try again!\n");
            answer_status = 0;
        }
    }
    
    return 0;
}