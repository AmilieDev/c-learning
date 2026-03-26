/* https://www.ibm.com/docs/en/i/7.5.0?topic=extensions-standard-c-library-functions-table-by-name */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Source - https://stackoverflow.com/a/10966395
// Posted by Terrence M, modified by community. See post 'Timeline' for change history
// Retrieved 2026-03-26, License - CC BY-SA 3.0

#define FOREACH_TYPE(TYPE) \
        TYPE(rock)   \
        TYPE(paper)  \
        TYPE(scissors)   \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum TYPE_ENUM {
    FOREACH_TYPE(GENERATE_ENUM)
};

static const char *TYPE_STRING[] = {
    FOREACH_TYPE(GENERATE_STRING)
};

// ^ Code provided in a source / stackoverflow source.
// Modified to fit this RockPaperScissors program.

/* All programs, need an entry point */
int main(void){
    srand(time(NULL)); /* Seeding with the current time to make it change constantly. */

    /* Randomly select a number with an appropriate upper and lower bound*/
    int lower_bound = 1;
    int upper_bound = 3;

    int computer_selected = rand() % (upper_bound - lower_bound + 1);

    /* Prepare for computer answer, allocate 50 bytes to be safe.*/
    char computer_answer[50];

    /* 
    This should check if computerSelected is equal to whatever, and then once done
    spit out Rock, Paper or Scissors to "computerAnswer"
    See https://www.geeksforgeeks.org/c/strcpy-in-c/ for STRCPY
    */
    if (computer_selected == 0) {
        /* These chars need to be 1 more than the actual word as C adds '\0' at the end of the program. */
        char computer_answer_tmp[5] = "rock";
        strcpy(computer_answer, computer_answer_tmp);
    } else if (computer_selected == 1) {
        char computer_answer_tmp[6] = "paper";
        strcpy(computer_answer, computer_answer_tmp);
    } else if (computer_selected == 2) {
        char computer_answer_tmp[9] = "scissors";
        strcpy(computer_answer, computer_answer_tmp);
    } else {
        printf("Fatal Error; Attempted to generate an invalid number.\n");
        printf("Attempted Generated Number; %i", computer_selected);
        return -1;
    }

    /* printf("Debug Output; Computer has selected: %s\n", computer_answer); */

    /* Pull in users answer: */
    char user_answer[50];
   
    printf("Please type 'rock', 'paper', or 'scissors': ");
    scanf("%s", &user_answer);
    /* printf("Debug Output; User has selected: %s\n", user_answer); */

    //  Source - https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c
    /* Automatically lowercase the users answer.*/
    for(int i = 0; user_answer[i]; i++){
        user_answer[i] = tolower(user_answer[i]);
    }

    /* 
    Check user chose a valid input / output. If not, kick them out.
    See https://www.geeksforgeeks.org/c/strcmp-in-c/ for string comparison.
    */
    if (strcmp(user_answer, TYPE_STRING[rock]) == 0) {
        printf("Debug Output; User Selected: Rock\n");
    } else if (strcmp(user_answer, TYPE_STRING[paper]) == 0) {
        printf("Debug Output; User Selected: Paper\n");
    } else if (strcmp(user_answer, TYPE_STRING[scissors]) == 0) {
        printf("Debug Output; User Selected: Scissors\n");
    } else {
        printf("Fatal Error; Incorrect input by user.\n");
        printf("User inputted %s, it must be written exactly as instructed.\n", user_answer);
        return -1;
    }

    /* Overall totals / results, then exiting the program. */
    if (strcmp(computer_answer, user_answer) == 0){
        printf("Draw! You both selected %s!\n", user_answer);
    } else if ((user_answer == TYPE_STRING[paper] && computer_answer == TYPE_STRING[rock]) ||
                (user_answer == TYPE_STRING[rock] && computer_answer == TYPE_STRING[scissors]) ||
                user_answer == TYPE_STRING[scissors] && computer_answer == TYPE_STRING[paper]) {
            printf("Player Victory! The computer selected %s - you selected %s.\n", computer_answer, user_answer);
        }  else {
        printf("Computer won! You selected %s and the computer selected %s.\n", user_answer, computer_answer);
    }
    return 0;
}