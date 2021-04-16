/* 
    A menu driven program which generates a code by allowing a user to enter a 4 digits code.
    Compares the 4 digit number to the access code.
    The codes are encrypted and decrypted by a certain algorithm. 
    The number of access attempted are recorded using a structure.
    Author: Nicole Sitenok C19391873
    Compiler: Atom, Borland.
*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 4

//Structures
struct code_counter
{
    int correct_code;
    int wrong_code;     
};

//Fucntion Signatures
int * generate_code();
void encrypt(int[]);
void compare(int[], int[], struct code_counter);
void decrypt(int[]);
void displayAttempts(struct code_counter);

//Index variables
int i;

int main()
{
    int access_code[SIZE] = {4, 5, 2, 3}; //the key code
    int option; //stores selection from menu
    int chosen=0; //ensures code has been generated in option 1
    int encrypted=0; //ensures code is not encrypted twice
    int *input_ptr; //pointer which points at input[] in generate_code (array containing code which is inputted)
    int user_code[SIZE]={0,}; //stores user's input code
    
    struct code_counter count = {0, 0}; //sets counter to zero.
    
    //While loop used for graceful finish & to display menu after every option choice
    while(true)
    {
        //Display menu
        printf("\n\n\nMENU\n");
        printf("1. Enter a code or generate a random code\n");
        printf("2. Encrypt code\n"); 
        printf("3. Check if the encrypted code matches the default authorised access code\n"); 
        printf("4. Decrypt code\n"); 
        printf("5. Display the number of times the encrypted code is: i. Correct ii. Wrong\n"); 
        printf("6. Exit Program\n");
        
        printf("\n\nPlease select an option from the menu above.\n");
        scanf("%d", &option);
        
        //Menu Selection
        
        switch(option)
        {
            case 1:
            {
                //Call function to generate a code
                input_ptr = generate_code();
                
                //store code into array
                for(i=0;i<SIZE;i++)
                {
                    *(user_code+i) = *(input_ptr+i);
                }
                
                //to ensure this option has been chosen
                chosen++;
                encrypted = 0;
                
                break;
            }//end case 1
            
            case 2:
            {
                //makes sure option 1 has been chosen
                if(chosen == 1)
                {
                    
                    //ensures code is not encrypted twice
                    if(encrypted == 1)
                    {
                        printf("Code has already been encrypted.\n");
                    }
                    else
                    {
                        //Function to encrypt generated code
                        encrypt(user_code);
                        encrypted++;
                    }
                    
                }
                else
                {
                    printf("\nPlease choose option 1 before chosing any other option.\n");
                }//end if else
                
                break;
            }//end case 2
            
            case 3:
            {
                if(chosen == 1)
                {
                    
                    //ensure code is encrypted before comparing
                    if(encrypted == 1)
                    {
                        //Function to compare code
                        compare(user_code, access_code, count);
                    }
                    else
                    {
                        printf("\nPlease encrypt code before comparing.\n");
                    }
                    
                }
                else
                {
                    printf("\nPlease choose option 1.\n");
                }//end if else
                
                break;
                
            }//end case 3
            
            case 4:
            {
                if(chosen == 1)
                {
                    
                    //ensures code has been encrypted to be decrypted
                    if(encrypted == 1)
                    {
                        //Function to decrypt code
                        decrypt(user_code);
                        encrypted=0;
                    }
                    else
                    {
                        printf("\nPlease encrypt code before comparing.\n");
                    }
                    
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
                    //Display structure which shows how many times code is correct or incorrect
                    displayAttempts(count);
                }
                else
                {
                    printf("\nPlease choose option 1.\n");
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
    

/* Function that asks for input and stores them in an array */
int * generate_code()
{
    static int input[SIZE] = {0,}; //static array so mem address is not lost when passed to main()
    
    printf("Please enter your 4 digit code.\n");
    
    for(i=0; i<SIZE; i++)
    {
        scanf("%d", &*(input+i));
        
        //check if value entered is a digit between 0-9
        while((isdigit(*(input+i)) != 0) || (((*(input+i)) > 9) || ((*(input+i)) < 0)) )
        {
            printf("Please enter a valid number between 0-9.\n");
            scanf("%d", &*(input+i));
        }
        
    }
    
    //display the code
    printf("\nYour code is: ");
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", *(input+i));
    }
    
    return input;
}//end generate_code()


/* Function which encrypts the code entered with a certain algorithm 
    Encryption Algorithm:       -Swap the 1st number with the 3rd number. 
                                            - Swap the 2nd number with the 4th number. 
                                            - Add 1 to each number.
                                            - If any number has a value equal to 10, change this value to 0
        */
void encrypt(int original[])
{
    int temp; //temporarily holds variables while swapping
    
    //Swapping 1st and 3rd number
    temp = original[0];
    original[0] = original[2];
    original[2] = temp;
    //Swapping 2nd and 4th number
    temp = original[1];
    original[1] = original[3];
    original[3] = temp;
    //Adding 1 to each number
    for(i=0;i<SIZE;i++)
    {
        (*(original+i))++;
        
        //ensuring no number equals 10
        if(*(original+i) == 10)
        {
            *(original+i) = 0;
        }
        
    }//end for
    
    //Display encrypted code
    printf("\nEncrypted code is: ");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ", *(original+i));
    }

}//end encrypt()


/* Function which compares the user's code to the access code */
void compare(int userCode[], int access[], struct code_counter)
{
    int match=0; //variable that stores how many times the elements of arrays match
    
    for(i=0; i<SIZE; i++)
    {
        if( (*(userCode+i)) == (*(access+i)) )
        {
            match++;
            
            //if all digits match
            if(match == 4)
            {
                printf("\n\nCorrect Code entered.");
                
            }
        }
        else
        {
            printf("\n\nWrong Code entered.");
        }
        
    }//endfor
    
}//end compare()


/* Function that decrypts the encrypted code to its original form. 
    Decryption Algorithm:   - Subtract 1 from each number. 
                                        - If any number has a value equal to 1, change this value to 9. 
                                        - Swap the 1st number with the 3rd number. 
                                        - Swap the 2nd number with the 4th number.
*/
void decrypt(int userCode[])
{
    int temp; //temporarily holds variables while swapping
    
    //Subtracting 1 from each number
    for(i=0;i<SIZE;i++)
    {
        (*(userCode+i))--;
        
        //ensuring no number equals 1
        if(*(userCode+i) == -1)
        {
            *(userCode+i) = 9;
        }
        
    }//end for
    
    //Swapping 1st and 3rd number
    temp = userCode[0];
    userCode[0] = userCode[2];
    userCode[2] = temp;
    //Swapping 2nd and 4th number
    temp = userCode[1];
    userCode[1] = userCode[3];
    userCode[3] = temp;
    
    //Display decrypted code
    printf("\nDecrypted code is: ");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ", *(userCode+i));
    }
    
}//end decrypt()

/* Function which counts how many wrong/correct attempts were made using a structure */
void displayAttempts(struct code_counter)
{
    
    
}
