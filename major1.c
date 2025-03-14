//Description: To write a c program with a menu to perform 4 different tasks, to locate zeros, decomposition of a number, to enter new number and to exit.


#include <stdio.h>

int CountDigit (int num) {  //defining a function to count number of digits to be used in decompose function
	int count = 0;
	while (num != 0) {
		num = num/10;
		count++;
		}
	return count;
}


int LocateZero (int num)  //locates positions of zeros in the number
{
	int position = 0;
	while (num != 0) {
		if (num % 10 == 0) {
			return position;
			}

		num = num/10;
		position = position +1;
		}
}


void DECOMPOSE (int num) {  //void function which decomposes the number eg: 123 is decomposed as 1 12 123
	int i = 1, j = 1, x = num, z = 1;
	while (i < CountDigit(num)) {  //using count digit to define i which will divide number to obtain the first digit and so on
		z = z*10;
		i++;
		}
		
	while (j <= CountDigit(num)) { //dividing i by 10 incrementally to obtain the values from left
		x = num;
		x = x / z;
		z = z/10;
		printf("%d ", x);
		j++;
		}
		return;
		
	}
	
int NewNumber (int num) //function for asking user to input new number
{
	num = num * 10;
	return num;
}
	


int main ()
{
	int n, option, x, y, i = 0;
	
	printf("Please enter a number n with greater than 3 digits and less than 7: ");
	scanf("%d", &n);
	
	n = n*10;
	x = n;
	printf("Number stored: %d\n", n);

	//using while, if, continue and break statements to succesfully print a menu from which user can choose which function is needed.
	
	while (1) {
		printf("\nChoose option: \n1: Locate\n2: Decompose\n3: New NUmber:\n4: Quit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		x = n;
		
		if(option == 1) {
			printf("Position of zero(s) in %d is: ", n);
			while (x != 0) {
				if (x % 10 == 0) {
				printf("%d ", i);
				}
				x = x/10;
				i++;
				}
			continue;
			}
			i = 0;
			
		if(option == 2) {
			DECOMPOSE(n);
			continue;
		}
			
		if(option == 3) {
			printf("\nPlease type new number, n: ");
			scanf("%d", &y);
			n = NewNumber (y);
			printf("\nStored value of n is %d", n);
			}
			
		//using break in 4th if statement to break of the program.
		
		if(option == 4) {
			printf("\nGoodbye! See you again.\n");
			break;
			}
		}
		
 return 0;
}



