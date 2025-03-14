//Description: To check whether the 3 integer inputs obtained are the sides of a triangle or not and also to check if the triangle is equilateral, isoscles or scalene.


#include <stdio.h>
int main ()
{
     int side_1, side_2, side_3;
     
     //Using printf and scanf thrice to obtain the integer values of sides of triangle from the user.
     
     printf("Type an integer value for side 'a' of triangle: ");
     scanf("%d", &side_1);
     printf("Type an integer value for side 'b' of triangle: ");
     scanf("%d", &side_2);
     printf("Type an integer value for side 'c' of triangle: ");
     scanf("%d", &side_3);
     
     //Using first if statement to check whether user input positive integers, if not print length to side cannot be negative statement.
     
     if ( side_1 > 0 && side_2 > 0 && side_3 > 0) {
          
          //Using second if statement to check if the 3 integers satisfy condition for being sides of triangle.
          
          if ( side_1 + side_2 > side_3 && side_2 + side_3 > side_1 && side_1 + side_3 > side_2) {
               printf("The 3 integer values given by user are the sides of a triangle.\n");
               
               //Using if, else if and else statements to check whether triangle is equilateral, isoscles or scalene respectively.
               
               if ( side_1 == side_2 && side_2 == side_3 && side_1 == side_3) {
                    printf("The triangle is an equilateral traingle.\n");
                    }
                    
               else if ( side_1 == side_2 || side_2 == side_3 || side_1 == side_3) {
                    printf("The triangle is an isosceles triangle.\n");
                    }
                    
               else printf("The triangle is a scalene triangle.\n");
               
               }
               
         else printf("The 3 integer values given by user are NOT the sides of a triangle.\n");
}
     else printf("One or more of the values given as input is negative. Length of side cannot be negative. Not a triangle.\n");
     
     return 0;
     
}
