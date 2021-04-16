/* Strings // DMA
    count number of vowels in string
    find the number of charcters
    concatenate strings
    Date: 12/03/2020
    Author: ns
    */

#include <stdio.h>
#include <string.h>

//Structures

//Symbolic names
#define SIZE 21

//Function Signature
void vowels(char[]);
void howmany(char[]);


int main()
{
    char my_string[SIZE] = {"0"};
    
    printf("Please enter a sentence:\n");
    gets(my_string);
    
    //Function to count number of vowels and cons
    vowels(my_string);
    
    //Function to find the number of characters in the string
    
    
    
    
    
    
}

//Function to count the vowels in entered string
void vowels(char my_string[])
{
    int vowel = 0;
    int i;
    int con = 0;
    
    for(i=0; i<strlen(my_string); i++)
    {
        if( (my_string[i] == 'a') || (my_string[i] == 'e') || (my_string[i] == 'i') || (my_string[i] == 'o') || (my_string[i] == 'u') )
        {
            vowel++;
        }
        else
        {
            con++;
        }//end if else
        
    }//end for
    
    //display number of vowels and consanants
    for(i=0; i<strlen(my_string); i++)
    {
        printf("There are %d vowels.\n", vowel);
        printf("There are %d consanants.\n", con);
    }
    
}//end vowels()

//Function to find the number of characters in the string
void howmany(char my_string[])
{
    int how_many;
    int i;
    
    how_many = strlen(my_string);
    
    printf("There are %d characters.\n", how_many);
    
    //Print the string in reverse
    
    

}