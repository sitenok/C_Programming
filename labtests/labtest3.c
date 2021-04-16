/* Programming lab test #3
    Change user's input to euro or dollar using arrays
    Displays the average of the 3 values inputted.
    Author: Nicole Sitenok c19391873
    Date: 20/02/2020
*/
#include <stdio.h>
#define SIZE 3

//Function Signature
float change_to_Euro(float[]);
float change_to_Dollar(float[]);

int main()
{   
    int exit=1; //variable to loop the menu
    int choice; //variable that stores the menu selection
    float amounts[SIZE]; //array that stores the user's input
    int i;
    //float newAmounts[SIZE]; //array that stores the converted values
    
    //While loop to make sure the menu loops around everytime and program ends gracefully.
    while(exit == 1)
    {
        //MENU
        printf("\n\nMENU\n\n");
        printf("1. Change Dollar to EURO\n");
        printf("2. Change Euro to DOLLAR\n");
        printf("3. EXIT \n\n");
        printf("Please choose one option, 1-3.\n");
        scanf("%d", &choice);
        
        //Selection for menu
        switch(choice)
        {
            case 1:
            {
                printf("Please enter 3 values to convert DOLLAR to EURO.\n");
                
                for(i=0; i<SIZE; i++)
                {
                    scanf("%f", & amounts[i]);
                }//end for
                
                for(i=0; i<SIZE; i++)
                {
                    printf("The values are:%f\n", amounts[i]);
                }
                
                //Function to convert the values to EURO
                change_to_Euro(amounts);
            }//end case1
            
            
            case 2:
            {
                printf("Please enter 3 values to convert EURO to DOLLAR.\n");
                
                for(i=0; i<SIZE; i++)
                {
                    scanf("%f", & amounts[i]);
                }//end for
                
                for(i=0; i<SIZE; i++)
                {
                    printf("The values are:%f\n", amounts[i]);
                }
                
                //Function to convert the values to DOLLAR
                amounts[SIZE]=change_to_Dollar(amounts);
                
                for(i=0; i<SIZE; i++)
                {
                    printf("The values are:%f\n", amounts[i]);
                }
                
            }//end case2
            
            case 3:
            {
                printf("\nExiting program...\n");
                exit = 0;
            }//end case3
            
        }//end switch
        
    }//end while
    flushall();
    getchar();
    return 0;

}//end main

//Function to convert values to EURO
float change_to_Euro(float amounts[SIZE])
{
    int i;
    float conversion = 1.19; //The euro to dollar rate
    float newAmounts[SIZE]; //stores the new, converted values
    float originalValues; //stores original values of array before conversion
    
    printf("Convert Euro to Dollar...\n");

    //Convert euro to dollar (Divide dollar by euro rate).
    for(i=0; i<SIZE; i++)
    {
        newAmounts[i] = amounts[i]/conversion;
    }
    
    return newAmounts[SIZE];
}//end change_to_Euro()


//Function to convert values to DOLLAR
float change_to_Dollar(float amounts[])
{
    int i;
    int sum,ave;
    
    float conversion = 0.84; //The euro to dollar rate
    float newAmounts[SIZE]; //stores the new, converted values
    
    printf("Convert Dollar to Euro...\n");

    
    //Convert Euro to Dollar (Multiply Euro by Dollar rate).
    for(i=0; i<SIZE; i++)
    {
        newAmounts[i] = amounts[i]*conversion;
    }
    for(i=0; i<SIZE; i++)
    {
    printf(" New amounts are %d \n",newAmounts[i]);
    }
    for(i=0; i<SIZE; i++)
    {
        sum=sum+newAmounts[i];
    }
    
    ave=sum/3;
    
    return ave;
}//end change_to_Dollar()


