/* Function which generates 6 random numbers
*/
int * generate_rand_nums()
{
    static int game_nums[SIZE]={0,}; //static array so mem address is not lost when passed to main()
    
    for(i=0; i<SIZE; i++)
    {
        //Finds remainder of a random number when divided by 10 and stores into array
        ( *(game_nums+i) ) = ( (rand() % 10) + 1 );
        printf(" random nums: %d \n", *(game_nums+i));
    }
    
    return game_nums;
}//end generate_rand_nums()