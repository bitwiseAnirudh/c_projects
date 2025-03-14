/*
Write a C program that takes an integer n as input from the user and populate an integer array A[ ] with n
non-negative random integers less than 1000. Print the array. Ask the user to enter an integer k. print the kth
largest element of the array. Your program must not sort the whole array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	srand(time(NULL));
	int n, i, j, k, largest, largest_index;
	
	
	printf("Please type the number of elements of array, n: ");
	scanf("%d", &n);
	int A[n];
	
	printf("PLease type k for finding kth largest number.");
	scanf("%d", &k);

	
	
	for(i = 0; i < n; i++) {
		A[i] = rand() % 1000;
		
		}
		
	printf("The random array generated is: ");
	
	for(j = 0; j < n; j++) {
		printf("%d, ", A[j]);
		}
		
	 largest = 0;
	
	//defininf largest as a variable and assigning 3rd largest value
	
	for(i = 0; i < k; i++) {
	largest = -1;
		for(j = 0; j < n; j++) {
			if(A[j] > largest) {
				largest = A[j];
				largest_index = j;
				}
				}
				A[largest_index] = -2;
		}	
		
		printf("\nThe %dth largest element in the array is: %d\n", k, largest);
		

		
	return 0;
}
