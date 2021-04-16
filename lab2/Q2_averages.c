/* Program that uses a function to calculate the average of three numbers
    Author: NS
    Date: 13/02/2020
*/

#include <stdio.h>
#define NO_OF_NUMS 3
//Function signature
float averagesF(int, int, int);

int main()
{
    int number1, number2, number3;
    float average;

    printf("Please enter three numbers to get the average of them.\n");
    scanf("%d", &number1);

    printf("Please enter another:\n");
    scanf("%d", &number2);

    printf("Please enter another:\n");
    scanf("%d", &number3);


    average = averagesF(number1, number2, number3);

    printf("The average of %d, %d, %d is:\n", number1, number2, number3);
    printf("%f", average);

    return 0;
}//end main


//Function which calculates the averages of three inputted numbers
float averagesF(int num1, int num2, int num3)
{
    int total;
    float avrg;

    total = num1 + num2 + num3;
    avrg = (float)total/NO_OF_NUMS;        //CASTING<<<<<< temporarily changes the total and NO_OF_NUMS to a float.

    return avrg;
}//end function averages()
