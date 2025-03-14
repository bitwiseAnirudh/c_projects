//Description: To write a C program which takes two integers a and b as input from the user and print the sum of the squares of all the odd numbers between a and b (including a and b).


#include <stdio.h>
int main ()
{
	int a, b, n, term=0, sum=0;
	printf("Enter the integers: \n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	
	
	if (b < a) {
		a = a + b;
		b = a - b;
		a = a - b;
		}
	
	n = a;
	
	while (n <= b) {
		term = n * n;
		
		if ( n % 2 == 1 ) {
			sum = sum + term; }
			
		n = n + 1;
		}
		
		
	printf("The sum is: %d\n", sum);
	
	return 0;
	
}
			
		
		
	
