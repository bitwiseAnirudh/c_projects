/*
Call a positive integer N “perfect” if N is equal to the sum of all its proper divisors (i.e., divisors including
1 but not N). E.g., 6 is such a number as its divisors 1, 2 and 3 sums to 6.
(a) Write a C program that takes a positive integer N as input and reports all the perfect numbers less than
or equal to N. Your program must use a function to detect perfect numbers. In particular, the main
function should call a function IsPerfect(int num) with a suitably chosen (non-void) return type; the
function IsPerfect(·) is invoked for each number num from 1 to N. The main function should report if
the number is perfect based on the output of the function call.
(b) Define a positive integer N as “abundant” if the sum of its proper divisors is greater than N. E.g., 12 is
an abundant number because the sum of all its proper divisors (i.e., 1, 2, 3, 4, 6) is 16. Write a C program
that takes N as input and prints all the odd abundant numbers less than or equal to N. You may use the
function IsPerfect(int num) defined above to modify it to a different function IsAbundantOdd(int num)
and write this program.
*/

#include <stdio.h>

int IsPerfect (int num)
{
	int count = 1, sum = 0;
	
	while (count < num) {
		
		if (num % count == 0) {
			sum = sum + count; }
			
		count++;
		
	}
	if (sum == num) {
	return sum; }
	
	else return 0;
			
}

int IsAbundantOdd (int num)
{
	int count = 1, sum = 0;
	
	while (count < num) {
		
		if (num % count == 0) {
			sum = sum + count; }
			
		count++;
		
	}
	if (sum > num && num % 2 == 1) {
	return sum; }
	
	else return 0;
			
}





	
int main ()
{
	int n1, n2, i = 2, j = 2;
	
	printf("Please type number, N (For checking perfect number): ");
	scanf("%d", &n1);
	
	printf("Please type number, N (For checking abundant number): ");
	scanf("%d", &n2);
	
	printf("Perfect numbers less than or equal %d are: ", n1);
	
	while (i <= n1) {
	
		if ( i == IsPerfect(i)) {
		printf("%d, ", IsPerfect(i)); }
		
		i++;
		
		}
		
	printf("\nAbundant numbers less than or equal %d are: ", n2);
		
	while (j <= n2) {
	
		if (IsAbundantOdd(j) > j) {
		printf("%d, ", j); }
		
		j++;
		
		}
	
	printf("\n");
	
	return 0;
	
}
