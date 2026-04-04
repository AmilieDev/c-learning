#include <stdio.h>
#include <math.h>

int main(void){
    float user_input;

    printf("Please input a number > ");
    scanf("%f", &user_input);
    printf("Round to 2 decimals this is > %.2f", user_input);

    return 1;
}