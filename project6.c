/*
A number N is said to be Even-Major-Factored if the number of even factors of N is greater than the number
of odd factors. A number N is said to be Odd-Major-Factored if the number of odd factors of N is greater
than the number of even factors. A number N is said to be Odd-Even-Factored if the number of odd and even
factors of N are equal. (Consider 1 as a factor but the number N itself is not a factor.) For example, factors
of 6 are 1, 2 and 3, so 6 is Odd-Major-Factored. Factors of 12 are 1, 2, 3, 4, 6; so 12 is Even-Major-Factored
Factors of 4 are 1 and 2, so, 4 is Odd-Even-Factored.
Write a C program which reads a number N and prints whether N is of type Even-Major-Factored or
Odd-Major-Factored or Odd-Even-Factored. Your program must use a function to detect numbers of any
type (as specified above). In particular, the main function should call a function CheckType(int num) (with a
suitably chosen return type) that takes an integer num as input and reports the type of num (i.e., whether is it
Even-Major-Factored or Odd-Major-Factored or Odd-Even-Factored).
*/

#include <stdio.h>

void checktype (int num)
{
	int i = 1, total_fact = 0, even_fact = 0, odd_fact = 0;
	
 	//using while loop to find total number of factors, even and odd factors.
	
	while (i <= (num/2)) {
		if (num % i == 0) {
			total_fact++; }
			
		if (num % (2 * i) == 0) {
			even_fact++;       }
			
		if (num % (2 * i - 1) == 0) {
			odd_fact++;           }
			
		i++;
		}
		
		//doing even_fact-- because in the above loop for the second if statement the number istelf is divided i.e. last iteration will be num % 2 * num == num % num, so this will give extra unwanted factor.
		
		if (num % 2 == 0) {
		even_fact--; }
		
	//checking if number is odd majored or even majored or even odd using following if statements.
		
	if (even_fact > odd_fact) {
		printf("The number is Even-Major-Factored\n");  }
		
	if (even_fact < odd_fact) {
		printf("The number is Odd-Major-Factored\n");  }
		
	if (even_fact == odd_fact) {
		printf("The number is Odd-Even-Factored\n");  }

		
	return;
		
}

int main ()
{
	int n;
	
	//using printf, scanf to obtain input number from user.
	
	printf("Please type the number: ");
	scanf("%d", &n);
	
	//calling void function checktype in main function.
	
	checktype(n);
		
	return 0;
	
}
		
