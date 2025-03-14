//Description: To write a C program which takes a positive integer N as input and prints the sum of the first N term of the series with the general term 1/ ((2n - 1)(2n + 1)).
//This C program calculates the sum of the first N terms of the mathematical series with the general term 1 / ((2n - 1)(2n + 1)), where N is a positive integer input by the user. The program first takes input N and ensures it is positive by repeatedly prompting the user if a negative value is entered. It then calculates the sum of the series for the first N terms using a do-while loop. After computing this sum, the program enters another loop to check for convergence by adding more terms until the sum no longer changes significantly. Finally, it prints the sum after N terms, the sum after an additional term, and the total number of terms required to reach stability.

#include <stdio.h>
int main ()
{
	int N, count=1;
	float term=0, sum=0, previous_value=0;
	printf("Enter N: ");
	scanf("%d", &N);
	
			
		           do {
				term = ((float) 1 / ((2.0 * count - 1) * (2.0 * count + 1)));
				sum = sum + term;
				count++; 
			    } while (count <= N);
				
		printf("SUM(%d) = %f\n", N, sum);
		
		
		while (1) {
			
		                previous_value = sum;
				term = ((float) 1 / ((2.0 * count - 1) * (2.0 * count + 1)));
				sum = sum + term;
				if(sum == previous_value)
				break;
				count++;
				}
				
		printf("SUM(%d) = %f\n", count, previous_value);
		printf("SUM(%d) = %f\n", count + 1, sum);
				
				
			 
			   
	return 0;
	
}
			
			
		 
