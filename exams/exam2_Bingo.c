/* 
    A menu driven program which plays a Bingo game. An array of randomly selected numbers is compared
    to the user's array of selected numbers. If all numbers match, player wins Bingo!
    Author: Nicole Sitenok C19391873
    Compiler: Atom/Borland
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 6

//Function Signatures
int * player_guess(); //Function which enables the player to input their 6 numbers
int * generate_rand_nums(); //Fucntion which generates 6 random numbers
void show_nums(int*, int*); //Fucntion which shows both sets of numbers
void compare(int*, int*); //Function which compares the two lists
void number_frequency(); //Function which displays the frequency of the 6 randomly generated numbers

//Index Variables
int i;
int j;
int temp;

int main()
{
    int *player_nums; // Pointer which stores location of 6 digits the player inputted
    int *winning_nums; // Pointer for 6 randomly generated digits
    int option; //Stores selection from menu
    int chosen=0; //Ensures option 1 was chosen and random numbers are generated
    int validguesses=0; //Ensures numbers entered by player are valid
    
    //While loop used for graceful finish & to display menu after every option choice
    while(true)
    {
        //Display menu
        printf("\n\n          MENU\n\n");
        printf("1. Enter player's 6 numbers\n");
        printf("2. Generate game's 6 random numbers\n"); 
        printf("3. Display player and game number sets (in increasing order)\n"); 
        printf("4. Compare the player and game numbers\n"); 
        printf("5. Display frequency of the game's generated numbers\n"); 
        printf("6. End Program\n");
        
        printf("\nPlease select an option from the menu above.\n");
        scanf("%d", &option);
        
        //Menu Selection
        
        switch(option)
        {
            case 1:
            {
                //Call function to prompt player to enter 6 numbers
                player_nums = player_guess();
                
                //Variables to ensure this option has been chosen and guesses are valid
                chosen=1;
                validguesses = 1;
                
                break;
            }//end case 1
            
            case 2:
            {
                //Function to generate 6 random numbers for bingo
                winning_nums = generate_rand_nums();
                
                //Ensures that both option 1 and 2 have been selected, makes chosen == 2
                chosen=2;
                
                break;
            }//end case 2
            
            case 3:
            {
                if(validguesses == 1)
                {
                    
                    //Ensure player guesses are valid and random numbers are chosen
                    if(chosen == 2)
                    {
                        //Function to display both number sets
                        show_nums(&*player_nums, &*winning_nums);
                    }
                    else
                    {
                        printf("\nPlease choose option 2 to generate random numbers.\n");
                    }
                    
                }
                else
                {
                    printf("\nPlease choose option 1 and enter 6 digits first.\n");
                }//end if else
                
                break;
                
            }//end case 3
            
            case 4:
            {
                if(validguesses == 1)
                {
                    
                    //Ensure player guesses are valid and random numbers are chosen
                    if(chosen == 2)
                    {
                        //Function to compare winning numbers and user input
                        compare(&*player_nums, &*winning_nums);
                    }
                    else
                    {
                        printf("\nPlease choose option 2 to generate random numbers.\n");
                    }
                    
                }
                else
                {
                    printf("\nPlease choose option 1 and enter 6 digits first.\n");
                }//end if else
                
                break;
                
            }//end case 4
            
            case 5:
            {
                if(chosen == 2)
                {
                    //Display how many times specific numbers were randomly chosen
                    number_frequency();
                }
                else
                {
                    printf("\nPlease choose option 2 at least once.\n");
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
    
    
}//end main


/* Function which allows player to enter 6 digits into an array and checks validity
*/
int * player_guess()
{
    static int input[SIZE] = {0,}; //static array so mem address is not lost when passed to main()

    printf("Please enter 6 numbers.\n");
    
    //Prompt player to input 6 digits
    i=0;
    while ( i < SIZE ) 
    {
        int repeat = 0;
        scanf("%d", &(*(input+i)));
        
        //Check if value entered is a digit between 1-10
        while((isdigit(*(input+i)) != 0) || (((*(input+i)) > 10) || ((*(input+i)) < 1)) )
        {
            printf("Please enter a valid number between 1-10.\n");
            scanf("%d", &*(input+i));
        }//end while
        
        //If number entered is the repeated, prompt player to enter until number is unique
        for (j=0; j<i; j++ ) 
        {
            if ( (*(input+i)) == (*(input+j)) ) 
            {
                printf( "Number has already been entered. Please enter a new number:\n" );
                repeat = 1;
                break;
            }
        }//end for
        
        //If number entered is unique, increase the counter for array position
        if ( repeat == 0 )
        {
            i++;
        }
        
    }//end while
    
    //Sort array in increasing order
    for(i=0; i<SIZE; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            if(input[i] > input[j])
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }//end for

    return input;
}//end player_guess()

/* Function which generates 6 random numbers
*/
int * generate_rand_nums()
{
    static int game_nums[SIZE]={0,}; //static array so mem address is not lost when passed to main()
    
    for(i=0; i<SIZE; i++)
    {
        //Finds remainder of a random number when divided by 10 and stores into array
        ( *(game_nums+i) ) = ( (rand() % 10) + 1 );
    }
    
    //Sort array in increasing order
    for(i=0; i<SIZE; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            if(game_nums[i] > game_nums[j])
            {
                temp = game_nums[i];
                game_nums[i] = game_nums[j];
                game_nums[j] = temp;
            }
        }
    }//end for
    
    //Check if each element in array is unique and change if not
    for(i=0; i<SIZE; i++)
    {
        //If the current element equals the element before or after it, add 1.
        if( (*(game_nums+i)) == (*(game_nums+i-1)) && (*(game_nums+i+1)) )
        {
            (*(game_nums+i))++;
            
            //If any number if larger than 10, make it 1.
            if((*(game_nums+i)) > 10)
            {
                (*(game_nums+i))=1;
                
                //If an element is the same as any other element, add 1 until it is not.
                while( (*(game_nums+i)) == (*(game_nums+0)) && (*(game_nums+1)) && (*(game_nums+2)) && (*(game_nums+3)) && (*(game_nums+4)) && (*(game_nums+5)) )
                {
                    (*(game_nums+i))++;
                }
                
            }//end if
            
        }//end if
        
    }//end for
    
    //Sort array in increasing order
    for(i=0; i<SIZE; i++)
    {
        for(j=i+1; j<SIZE; j++)
        {
            if(game_nums[i] > game_nums[j])
            {
                temp = game_nums[i];
                game_nums[i] = game_nums[j];
                game_nums[j] = temp;
            }
        }
    }//end for
    
    printf("\n6 Random numbers have been generated, good luck!\n");
    return game_nums;
}//end generate_rand_nums()

/* Function to show both the player's guesses and the correct bingo answers by taking values 
    from the pointers in main() which point at arrays in generate_rand_nums() and player_guess() */
void show_nums(int *player_nums, int *winning_nums)
{
    //Print the player's input
    printf("\n\nYour numbers are:\n");
    for(i=0; i<SIZE;i++)
    {
        printf("%d ", *(player_nums+i));
    }
    
    //Print the winning numbers
    printf("\n\nThe winning numbers are:\n");
    for(i=0; i<SIZE;i++)
    {
        printf("%d ", *(winning_nums+i));
    }
}//end show_nums()

/* Function which compares both sets of numbers, displays how many matched and if all numbers match,
    displays Bingo!  **Could not get loop to work** */
void compare(int * player_nums, int * winning_nums)
{
    int matched=0; //Records how many numbers match
    
    if( (*(player_nums+0)) == (*(winning_nums+0)) )
    {
        matched++;
    }
    if( (*(player_nums+0)) == (*(winning_nums+1)) )
    {
        matched++;
    }
    if( (*(player_nums+0)) == (*(winning_nums+2)) )
    {
        matched++;
    }
    if( (*(player_nums+0)) == (*(winning_nums+3)) )
    {
        matched++;
    }
    if( (*(player_nums+0)) == (*(winning_nums+4)) )
    {
        matched++;
    }
    if( (*(player_nums+0)) == (*(winning_nums+5)) )
    {
        matched++;
    }    
    
    if( (*(player_nums+1)) == (*(winning_nums+0)) )
    {
        matched++;
    }
    if( (*(player_nums+1)) == (*(winning_nums+1)) )
    {
        matched++;
    }
    if( (*(player_nums+1)) == (*(winning_nums+2)) )
    {
        matched++;
    }
    if( (*(player_nums+1)) == (*(winning_nums+3)) )
    {
        matched++;
    }
    if( (*(player_nums+1)) == (*(winning_nums+4)) )
    {
        matched++;
    }
    if( (*(player_nums+1)) == (*(winning_nums+5)) )
    {
        matched++;
    }
    
    if( (*(player_nums+2)) == (*(winning_nums+0)) )
    {
        matched++;
    }
    if( (*(player_nums+2)) == (*(winning_nums+1)) )
    {
        matched++;
    }
    if( (*(player_nums+2)) == (*(winning_nums+2)) )
    {
        matched++;
    }
    if( (*(player_nums+2)) == (*(winning_nums+3)) )
    {
        matched++;
    }
    if( (*(player_nums+2)) == (*(winning_nums+4)) )
    {
        matched++;
    }
    if( (*(player_nums+2)) == (*(winning_nums+5)) )
    {
        matched++;
    }
    
    if( (*(player_nums+3)) == (*(winning_nums+0)) )
    {
        matched++;
    }
    if( (*(player_nums+3)) == (*(winning_nums+1)) )
    {
        matched++;
    }
    if( (*(player_nums+3)) == (*(winning_nums+2)) )
    {
        matched++;
    }
    if( (*(player_nums+3)) == (*(winning_nums+3)) )
    {
        matched++;
    }
    if( (*(player_nums+3)) == (*(winning_nums+4)) )
    {
        matched++;
    }
    if( (*(player_nums+3)) == (*(winning_nums+5)) )
    {
        matched++;
    }
    
    
    if( (*(player_nums+4)) == (*(winning_nums+0)) )
    {
        matched++;
    }
    if( (*(player_nums+4)) == (*(winning_nums+1)) )
    {
        matched++;
    }
    if( (*(player_nums+4)) == (*(winning_nums+2)) )
    {
        matched++;
    }
    if( (*(player_nums+4)) == (*(winning_nums+3)) )
    {
        matched++;
    }
    if( (*(player_nums+4)) == (*(winning_nums+4)) )
    {
        matched++;
    }
    if( (*(player_nums+4)) == (*(winning_nums+5)) )
    {
        matched++;
    }
    
    if( (*(player_nums+5)) == (*(winning_nums+0)) )
    {
        matched++;
    }
    if( (*(player_nums+5)) == (*(winning_nums+1)) )
    {
        matched++;
    }
    if( (*(player_nums+5)) == (*(winning_nums+2)) )
    {
        matched++;
    }
    if( (*(player_nums+5)) == (*(winning_nums+3)) )
    {
        matched++;
    }
    if( (*(player_nums+5)) == (*(winning_nums+4)) )
    {
        matched++;
    }
    if( (*(player_nums+5)) == (*(winning_nums+5)) )
    {
        matched++;
    }
    
    //Display how many numbers match and if all match, print Bingo!
    if(matched < 2)
    {
        printf("%d number matches!\n", matched);
    }
    else
    {
        printf("%d numbers match!\n", matched);
    }
    
    if(matched == 6)
    {
        printf("BINGO!");
    }
}//end compare()

/* Function which displays the amount of times a randomly generated number was used
*/
void number_frequency()
{
    
    
}//end number_frequency()
