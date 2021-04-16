/* Programming lab3
    Pass by reference exercise, Area of circle and area of square.
    Author: ns
    Date: 20/02/2020
*/

#include <stdio.h>

//Function signature
void circleSize(int*);
void squareSize(int*);

int main()
{
    float radius;
    float side;
    
    printf("To calculate the area of a circle enter a radius value:\n");
    scanf("%f", & radius);
    
    printf("To calculate the area of a square enter the length of one side:\n");
    scanf("%f", & side);
    
    //Calculate area of circle using pass by reference
    circleSize(&radius);
    squareSize(&side);
    
}

void circleSize(int*rad)
{
    printf("\n\nrad contains %f \n\n", *rad);
    
    
    
    
    
    
    