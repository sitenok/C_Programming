/* Lab Test 2
    Author: Nicole Sitenok
    Date: 02/12/2019
    Using Borland compiler
    Program using two different arrays to copy, change and print the contents
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main()
{
    char barack[] = {'Y','E','S',' ','W','E',' ','C','A','N'};
    char michelle[sizeof(barack)] = {'0'};
    int i;
    
    
    
    //Copy contents of barack[] to michelle[]
    for(i=0; i<sizeof(barack); i++)
    {
        *(michelle+i) = *(barack+i);
    }
    
    
    //Replacing blank spaces with underlines
    michelle[3] = '_';
    michelle[6] = '_';
    
    
    //Display contents of michelle[]
    printf("The contents of array michelle[] are:\n");

    for(i=0; i<sizeof(barack); i++)
    {
        printf("%c\n", *(michelle+i));
    }
    
    getchar();
    return 0;
    
    
}//end main