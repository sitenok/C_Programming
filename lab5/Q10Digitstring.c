/*A string arraay of digits
    date: 05/03/2020
    author: ns
*/
#include <stdio.h>

#define SIZE 5

int main()
{
    char *digits[SIZE] = {"","","","","\0"};
    int i;
    
    printf("Please input 4 numbers.\n");
    
    for(i=0; i<(SIZE-1); i++)
    {
        scanf("%s", digits[i]);
    }
    
    
    
    
    
    getchar();
    return 0;
}