/* Assignment 2, Lottery Game. Program displays a menu with 6 options. 1- Enter 6 numbers. 2- Display numbers. 3- Sort the numbers.
    4- Compare guesses to winning numbers. 5- Display the frequency of chosen numbers. 6- Exit program(graceful finish).
        Author: Nicole Sitenok C19391873
        Borland & Atom compiler.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 6
#define MAX 42
#define MIN 1

//Function Signatures
void opt1(int guesses[]); //function to enter numbers into array
void opt2(int guesses[]); //function to display the numbers of the entered array
void opt3(int guesses[], int num); //function which usues BUBBLE SORT to sort the contents of the array in ascending order
void swap(int *a, int *b); // function to assist the bubble sort function above. Switches places of two elements
void opt4(int guesses[], int winningnums[]); //compare strings for winnning numbers
void opt5(int freq[]); //Display frequency of numbers entered


int main()
{
    int option; //stores selection from menu
    int guesses[SIZE]; //stores the 6 numbers inputted
    int chosen=0; //Makes sure that options 2-5 are not chosen before array initialized
    int num = SIZE; //parameter for bubble sort function, opt3()
    int winningNums[SIZE] = {1, 3, 5, 7, 9, 11}; //array containing winning numbers

    
    //While loop used for graceful finish & to display menu after every option choice
    while(true)
    {
        //Display menu to user
        printf("\n\n MENU \n\n");
        printf("1. Enter your numbers\n");
        printf("2. Display your numbers\n");
        printf("3. Sort your numbers\n");
        printf("4. Compare to winning numbers\n");
        printf("5. Frequency of numbers\n");
        printf("6. Exit program");
        
        printf("\n\nPlease select an option from the menu above.\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
            {
                //Initialize array guesses[], input the 6 guesses.
                opt1(guesses);
                chosen = 1;
                
                break;
            }//end case 1
            
            case 2:
            {
                //makes sure option 1 has been chosen
                if(chosen == 1)
                {
                    //Function to display the guesses
                    opt2(guesses);
                    
                }
                else
                {
                    printf("\nPlease choose option 1 and enter 6 number before chosing any other option.\n");
                }//end if else
                
                break;
            }//end case 2
            
            case 3:
            {
                if(chosen == 1)
                {
                    //Function to sort the array in ascending order using bubble sort algorithm & print them
                    opt3(guesses, num);
                    
                }
                else
                {
                    printf("\nPlease choose option 1 and enter 6 number before chosing any other option.\n");
                }//end if else
                
                break;
                
            }//end case 3
            
            case 4:
            {
                if(chosen == 1)
                {
                    //Function to compare the numbers
                    opt4(guesses, winningNums);
                    
                }
                else
                {
                    printf("\nPlease choose option 1 and enter 6 number before chosing any other option.\n");
                }//end if else
                
                break;
                
            }//end case 4
            
            case 5:
            {
                if(chosen == 1)
                {
                    //Function which shows the frequency of numbers entered
                    opt5(guesses);
                    
                    
                }
                else
                {
                    printf("\nPlease choose option 1 and enter 6 number before chosing any other option.\n");
                }//end if else
                
                break;
                
            }//end case 5
            
            case 6:
            {
                printf("\n\nExiting program...\n\n");
                
                return 0;
            }//end case 6
            
        }//end switch
        
    }//end while
    
}//end main()


//Function which allows user to enter 6 numbers
void opt1(int guesses[])
{
    int i;
    int j;
    int input; //stores the number inputted, for error checking

    printf("Please enter 6 numbers.\n");
    for(i=0; i<SIZE; i++)
    {
        scanf("%d", & input);
        
        //Checks for valid entry
        if( (isdigit(input) == 1) || (input < MIN) || (input > MAX) )
        {
            printf("\nInvalid input, please enter 6 numbers between 1-42.\n");
            i=i-1; //to make sure the element space isnt filled by invalid number
        }
        
        else
        {
            *(guesses + i) = input;
        }
        
        //Ensures unique entry
        if(i > 0)
        {
            j = i-1;
            
            if( (*(guesses) + j) == input)
            {
                printf("Please enter a number you have not already entered.\n");
                i = i-1; //return to previous element space
            }
            
        }//end if
        
    }//end for
    
    printf("\nNumbers memorized.\n");
    
}//end opt1() INPUT NUMBERS


//Function which prints the contents of 1D array
void opt2(int guesses[])
{
    int i; 
    
    printf("\nYour numbers are:");
    for(i=0; i<SIZE; i++)
    {
        printf("%d \0", *(guesses+i));
    }
    
}//end opt2() DISPLAY NUMBERS

    
void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
    
}//end swap()

void opt3(int guesses[], int num)
{
    int i, j;
    
    for(i=0; i<num-1; i++)
    {
        for(j=0; j< num-i-1; j++)
        {
            if( guesses[j] > guesses[j+1] )
            {
                //swap the numbers if b is larger
                swap(&guesses[j], &guesses[j+1]);
            }
            
        }//end inner for
        
    }//end outer for
    
    //print the sorted numbers
    printf("\nYour numbers are:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d \0", *(guesses+i));
    }

}//end opt3() SORT


//Function to compare guesses and actual winning numbers
void opt4(int guesses[], int winningnums[])
{
    int matches=0;
    int i;
    
    for(i=0; i<SIZE; i++)
    {
        //compare element [i] to each winning number
        if( *(guesses+i) == *(winningnums+0) )
        {
            matches++;
        }
        
        if( *(guesses+i) == *(winningnums+1) )
        {
            matches++;
        }
        
        if( *(guesses+i) == *(winningnums+2) )
        {
            matches++;
        }
        
        if( *(guesses+i) == *(winningnums+3) )
        {
            matches++;
        }
        
        if( *(guesses+i) == *(winningnums+4) )
        {
            matches++;
        }
        
        if( *(guesses+i) == *(winningnums+5) )
        {
            matches++;
        }
        
        
    }//end for
    
    //Print the guesses and actual winning numbers and the amount of matches
    printf("\nYour numbers are:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d, \0", *(guesses+i));
    }
    
    printf("\nThe winning numbers are:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d, \0", *(winningnums+i));
    }
    
    printf("\nThe number of matches is: %d.\n", matches);
    
    //Show prizes depending on the number of guessed matched
    if(matches == 3)
    {
        printf("\n\nCongratualtions you have won a CINEMA PASS!\n\n");
    }
    
    if(matches == 4)
    {
        printf("\n\nCongratualtions you have won a WEEKEND AWAY!\n\n");
    }
    
    if(matches == 5)
    {
        printf("\n\nCongratualtions you have won a NEW CAR!\n\n");
    }
    
    if(matches == 6)
    {
        printf("\n\nCongratualtions you have won the JACKPOT!!\n\n");
    }
    
    if(matches < 3)
    {
        printf("Sorry, maybe next time.\n");
    }
    
    
}//end opt4() COMPARE & PRIZES

//Function to display frequency of numbers entered 
void opt5(int guesses[])
{
    int range[42];
    int i;
    int frequ[42] = {0};
    static int count1= 0, count2=0, count3=0, count4=0, count5=0, count6=0;
    
    
    //fill array with numbers 1-42
    for(i=0; i < MAX; i++)
    {
        *(range+i) = i;
    }
    
    //fill second array with the amount of times that number is encountered
    for(i=0;i<MAX;i++)
    {
        if( *(guesses+0) == *(range+i) )
        {
            count1++;
            *(frequ+i) = count1;
        }
        
        if( *(guesses+1) == *(range+i) )
        {
            count2++;
            *(frequ+i) = count2;
        }
        
        if( *(guesses+2) == *(range+i) )
        {
            count3++;
            *(frequ+i) = count3;
        }
        
        if( *(guesses+3) == *(range+i) )
        {
            count4++;
            *(frequ+i) = count4;
        }
        
        if( *(guesses+4) == *(range+i) )
        {
            count5++;
            *(frequ+i) = count5;
        }
        
        if( *(guesses+5) == *(range+i) )
        {
            count6++;
            *(frequ+i) = count6;
        }
        
    }//end for
    
    //Display the number of time the guess is encountered
    for(i=0; i<MAX; i++)
    {
        printf("\nThe number %d has been selected %d amount of times.\n", *(range+i), *(frequ+i) );
    }
    
}//end opt4() FREQUENCY
