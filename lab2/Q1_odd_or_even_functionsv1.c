/* Program that checks if a number is even or odd, using a function.
    Main function will prompt the user to input a number, the function should distinguish between even or odd
    Author: NS
    Date: 13/02/2020
*/

#include <stdio.h>

//Function Signature
int evenodd(int, int);

int main()
{
    int inputnumber;
    int answer;

    printf("Enter a number to find if it is even or odd:\n");
    scanf("%d", &inputnumber);

    printf("%d is your number.\n\n", inputnumber);

    //Function checking if number is even or odd
    evenodd(inputnumber, answer);

    answer = evenodd(inputnumber, answer);

    if(answer == 1)
    {
        printf("Even.\n");
    }
    else
    {
        printf("Odd.\n");
    }


    return 0;

}//end main()

//Function to distinguish between an even or odd number
int evenodd(int thenumber, int ans)
{

    if(thenumber%2 == 0)
    {
        //Set ans to 1 if the number is even
        ans = 1;
    }
    else
    {
        //Set ans to 0 if the number is odd
        ans = 0;
    }

    return ans;
}//end function evenodd()
