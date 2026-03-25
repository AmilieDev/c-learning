/* https://www.ibm.com/docs/en/i/7.5.0?topic=extensions-standard-c-library-functions-table-by-name */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TYPECODES C(ROCK)C(PAPER)C(SCISSORS)
#define C(x) x,
enum TypeCodes {
    Rock, Paper, Scissors
};
#undef C

#define C(x) #x,
const char * const typecode[] = { TYPECODES };

/* All programs, need an entry point */
int main(void){
    srand(time(NULL)); /* Seeding with the current time to make it change constantly. */

    /* Randomly select a number with an appropriate upper and lower bound*/
    int lower_bound = 1;
    int upper_bound = 3;

    int computer_selected = rand() % (upper_bound - lower_bound + 1);
    int user_selected = 0;

    /* Prepare for computer answer, allocate 50 bytes to be safe.*/
    char computer_answer[50];

    /*  
    This should check if computerSelected is equal to whatever, and then once done
    spit out Rock, Paper or Scissors to "computerAnswer"
    See https://www.geeksforgeeks.org/c/strcpy-in-c/ for STRCPY
    */
    if (computer_selected == 0) {
        /* These chars need to be 1 more than the actual word as C adds '\0' at the end of the program. */
        char computer_answer_tmp[5] = "Rock";
        strcpy(computer_answer, computer_answer_tmp);
    } else if (computer_selected == 1) {
        char computer_answer_tmp[6] = "Paper";
        strcpy(computer_answer, computer_answer_tmp);
    } else if (computer_selected == 2) {
        char computer_answer_tmp[9] = "Scissors";
        strcpy(computer_answer, computer_answer_tmp);
    } else {
        printf("Fatal Error; Attempted to generate an invalid number.\n");
        printf("Attempted Generated Number; %i", computer_selected);
        return -1;
    }

    /* printf("Debug Output; Computer has selected: %s\n", computer_answer); */

    /* Pull in users answer: */
    char user_answer[50];
   
    printf("Please type 'Rock', 'Paper', or 'Scissors': ");
    scanf("%s", &user_answer);
    /* printf("Debug Output; User has selected: %s\n", user_answer); */

    /* 
    Check user chose a valid input / output. If not, kick them out.
    See https://www.geeksforgeeks.org/c/strcmp-in-c/ for string comparison.
    */
    if (strcmp(user_answer, "Rock") == 0) {
        printf("Debug Output; User Selected: Rock\n");
    } else if (strcmp(user_answer, "Paper") == 0) {
        printf("Debug Output; User Selected: Paper\n");
    } else if (strcmp(user_answer, "Scissors") == 0) {
        printf("Debug Output; User Selected: Scissors\n");
    } else {
        printf("Fatal Error; Incorrect input by user.\n");
        printf("User inputted %s, it must be written exactly as instructed.\n", user_answer);
        return -1;
    }

    /* Overall totals / results, then exiting the program. */
    if (strcmp(computer_answer, user_answer) == 0){
        printf("Draw! You both selected %s!\n", user_answer);
    } else if ((strcmp(user_answer, "Paper") == 0 && strcmp(computer_answer, "Rock") == 0) ||
                (strcmp(user_answer, "Rock") == 0 && strcmp(computer_answer, "Scissors") == 0) ||
                (strcmp(user_answer, "Scissors") == 0 && strcmp(computer_answer, "Paper") == 0)) {
            printf("Player Victory! The computer selected %s - you selected %s.\n", computer_answer, user_answer);
        }  else {
        printf("Computer won! You selected %s and the computer selected %s.\n", user_answer, computer_answer);
    }
    return 0;

}