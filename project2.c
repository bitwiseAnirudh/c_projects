//Description: To obtain discounted final amount after user inputs initial amount of money for which books were purchased while having different ranges of discounts for different inputs of initial amount.

#include <stdio.h>
int main ()

{

     int amt;
     float final_amt;
     printf("Type the purchase amount: ");
     scanf("%d", &amt);
     
     //While loop used to repeatedly ask user to type positive values if they continue to type negative values.
     
     while (1) 
     {
         
         //Using if statement to check if amount is negative. if yes, asking user to type again.
         
         if (amt < 0) {
         	printf("Error. Amount typed is negative. Please type amount again: ");
                scanf("%d", &amt);
		}
    
         //Using 3 if statements to check of the 3 given ranges of amount and apply discount individually.
         
         if ( amt >= 0 && amt < 100) {
	        final_amt = (float) amt * 0.9;
                printf("The purchase amount after discount is: %f\n", final_amt);
                                                                                               
         //Using break statement to ensure while loop doesn't run infinitely and program exits after 1 cycle if amount typed is positive but executes loop multiple times if amount typed is negative
			
	break;
        }
    
        if ( amt >= 100 && amt <= 999) {
            final_amt = (float) amt * 0.8;
            printf("The purchase amount after discount is: %f\n", final_amt);
            break;
        }
    
        if ( amt >= 1000) {
        	final_amt = (float) amt * 0.6;
    		printf("The purchase amount after discount is: %f\n", final_amt);
    		break;
        }
    
   
	}

	return 0;

}
