/* Function to allow user to enter input, checks if number is repeated and if number is between 1-10 */

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