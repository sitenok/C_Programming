/*Program to compare the elements of a string array to input
    Date: 05/03/2020
    Author: ns
*/

#include <stdio.h>
#include <string.h> //needed for gets() function

#define SIZE 3

int main()
{
    char *names[SIZE] = {"molly", "dolly", "polly"};
    char input[21];
    int i;
    int check=0;
    
    printf("Please enter your name\n");
    gets(input);
    
    for(i=0; i < SIZE; i++)
    {
        if((input[i]) == *(names[i]))
        {
            check++;
            //printf("check = %d", check);
        }
        
    }//end for
    
    if(check == 1)
    {
        printf("Welcome, %s.\n", input);
    }
    else
    {
        printf("Name not found.\n");
    }
    
    
    getchar();
    return 0;
}