#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void){
    printf("Welcome to CampusCal!\n");
    printf("Please enter (in Litres) how much water you have had. No need to add an L! \n");

    float litres;
    float finalTotal = 0;

    /* Get user input in float using a pointer for litres. */
    scanf("\n%f", &litres);
    finalTotal = finalTotal + litres;

    /* Print out the final float with %f indicating float. */
    printf("%f", finalTotal);
    
    return 0;
}