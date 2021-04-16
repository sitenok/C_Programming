/*Program to display an array of pointer strings
    Date: 05/03/2020
    Author: ns
*/

#include <stdio.h>

#define SIZE 3 

int main()
{
    //and array of pointers which point at the start of each mem address of each string
    char *names[SIZE] = {"molly", "polly", "dolly"};
    int i;
    
    for(i=0; i<SIZE; i++)
    {
        //subscript
        printf("%s\n", names[i]);
        
        //pointer notation
        printf("%s\n", *(names + i));
        
        
    }
    
    
    
    
    getchar();
    return 0;
}