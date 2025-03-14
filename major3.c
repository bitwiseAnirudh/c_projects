/* This program calculates a modified Fibonacci-based sequence G(n) using the formula:
*     G(n) = a * F(n) + b
* where F(n) is the Fibonacci sequence defined as:
*     F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n ≥ 2.
*
* The program takes an integer n as input and ensures it is non-negative.
* It then accepts three different pairs of values (a, b) and computes G(n) for each pair.
* The recursive function G(n, a, b) is used to compute the values.
*/

#include <stdio.h>

int G (int n, int a, int b) //function G with input n, a, b
{
	if (n == 0) return b;        //base case for n = 0
	if (n == 1) return a + b;    //base case for n = 1
	else return G (n-1, a, b) + G (n-2, a, b) - b;              //recursive statement to calculate G(n) = a*F(n) + b, when F is fibonacci series
}

int main ()
{
	int n, i, j, a, b;
	
	printf("Enter the values of n: ");
	scanf("%d", &n);
	while(n < 0)                //handling negative values of n
	{
		printf("Value of n entered is less than zero, enter proper value of n: ");
		scanf("%d", &n);
	}
		
	
	for(i = 0; i < 3; i++)  //3 choices of a, b
	{
		printf("\nEnter %dst value of (a,b): ", i+1);
		scanf("%d %d", &a, &b);
		for(j = 0; j <= n; j++)
		{
			printf("%d, ", G(j, a, b)); //calling function G everytime to obtain value of G(j)
		}
	}
	
	printf("\n");
	
	return 0;
}
