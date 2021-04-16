/*A program that uses dynamic memory allocation to allocate memory for 5 floating-point numbers
    and finds the average.
    Author: ns
    Date: 06/02/2020
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *ptr;
    float *averageptr;
    float sum;
    int no_of_nums;
    int i = 0;

    printf("Enter the amount of numbers needed:\n");
    scanf("%d", &no_of_nums);


    //Allocate the memory block needed
    ptr = (float*)calloc(no_of_nums, sizeof(float));

    //Check if allocation successful
    if (ptr == NULL)
    {
        printf("Failed to allocate memory.\n\n");
    }
    else
    {
        printf("Memory allocation successful.\n\n");
    }

    printf("There will be a set of %d numbers.\n", no_of_nums);


    //Enter the numbers into memory block
    for(i = 0; i < no_of_nums; i++)
    {
        printf("Please enter the numbers:\n");
        scanf("%f", & *(ptr+i));
    }//end for

    //Display the numbers
    printf("The numbers entered:\n\n");

    for(i=0; i < no_of_nums; i++)
    {
        printf("%f\n", *(ptr+i));
    }

    //Calculate the sum of the numbers
    for(i = 0; i < no_of_nums; i++)
    {
        sum = sum + *(ptr+i);
    }

    printf("The sum of the numbers is: %f\n\n", sum);

    //Allocate space for Average memory block
    averageptr = (float*)calloc(no_of_nums, sizeof(float));

    //Calculate avrg
    *averageptr = sum/no_of_nums;

    //Display the average
    printf("The average of these numbers is:\n");

    for(i=0; i < 1 ; i++)
    {
        printf("%f\n", *(averageptr+i));
    }


    return 0;
}
