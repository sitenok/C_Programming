/* Program using dynamic memory allocation for arrays
    Author: ns
    Date: 06/02/2020
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int sum;
    int no_of_nums;
    int i;
    //int no_of_bytes;        (this variable is only needed when using the malloc() function.)
    
    //How many numbers will be inserted?
    printf("Specify how many numbers will be needed:\n");
    scanf("%d", &no_of_nums);
    
    //Allocate the memory block
    ptr = (int*)calloc(no_of_nums, sizeof(int));
    
    
    //check if memory block allocation is successful 
    if(ptr == NULL)
    {
        printf("Memory allocation unsuccessful\n");
        return 0;
    }
    else
    {
        printf("Memory allocation successful\n\n");
    }
    
    //Enter the numbers into the array
    for(i=0; i < no_of_nums; i++);
    {
        printf("Please enter the numbers:\n");
        scanf("%d", *(ptr+i));
        


    
    flushall();
    getchar();
    return 0;
}