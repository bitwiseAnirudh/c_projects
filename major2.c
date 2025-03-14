//Description: To create a right triangle composed of natural numbers (tailor made for less than 100 natural numbers). depends on number of rows input by user.


#include <stdio.h>

int main ()
{
	int n, count = 1, i = 1;
	int x, y = 1;
	
	//taking number of rows as input from user and asign it to n.
	
	printf("Enter the number of rows: ");
	scanf("%d", &n);
	printf("Floyd's triangle with %d rows: \n", n);
	
	//here x is the value that acts as the limit to count inside the first while loop.
	
	x = ((n+1) * (n+2))/2; //to calculate the total number of terms upto the end of the entered last row.
	
	//here another variable y is also there to increment count with increasing numbers in every loop i.e in the first loop count increments by 1, in the second loop it increments by 2 and so on.
	//\n is present in the first while loop to move on to the next row.
	
	while (count <= x) {
		while (i < count) {
			printf("%d ", i); // we can instead of leaving a space, also use %2d or %3d if we want the last digits of the numbers aligned.
			if (i < 10) { printf(" "); } // printing a space after all the single digit numbers only to match the sample output exactly.
			i++;
			}
		printf("\n");
		count = count + y;
		y++;
	}
	
	return 0;
	
}
