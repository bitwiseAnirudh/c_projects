/*
A magic square of size n is a square matrix of size n × n where each of the n rows, each of the n
columns and each of the 2 diagonals respectively sums the same. E.g., below is a magic square of
size 3:
9 2 7
4 6 8
5 10 3
Above, note that each row, each column and each diagonal sums to 18. Write a C program that first
reads a positive integer n as input to create a 2-D array M describing an n × n matrix M filled
up with the integers 1 to n2. Assume that each number can be used only once. Input the matrix
in a row-major format (i.e., all entries of row i should be entered before row i + 1) and print it
accordingly. Report ifMdescribes a magic square or not.
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n, i, j, sum = 0, new_sum = 0, flag = 1;
	
	printf("Enter a positive integer: ");  //obtaining order of matrix from user
	scanf("%d", &n);
	
	int **arr = (int **)malloc(n * sizeof(int *)); //dynamically allocating array arr
	
	for(i = 0; i < n; i++) {
	arr[i] = (int *)malloc(n * sizeof(int));
	}
	
	printf("Enter the input matrix M in a row-major format: ");
	
	for(i = 0; i < n; i++) {   //asking inputs of matrix
		for(j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			}
		}
		
	printf("The entered matrix M:\n");
	
	for(i = 0; i < n; i++) {  //printing matrix
		for(j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		
	for(i = 0; i < n; i++) { //checking sum of numbers in just 1st row
		sum = sum + arr[i][0];
		}
		
	for(i = 0; i < n; i++) { //using nested for to check individually sum of elemets of each row and compare to sum
		new_sum = 0;
		for(j = 0; j < n; j++) {
			new_sum = new_sum + arr[i][j];
			}
		if(new_sum != sum) {
			flag = 0;
			break;
			}
		}
		
	for(j = 0; j < n; j++) { // for columns
		new_sum = 0;
		for(i = 0; i < n; i++) {
			new_sum = new_sum + arr[i][j];
			}
		if(new_sum != sum) {
			flag = 0;
			break;
			}
		}
		
	i = 0, j = 0, new_sum = 0;
		
	while (i < n) { // for diagonal 1
		new_sum = new_sum + arr[i][j];
		i = i + 1;
		j = j + 1;
		}
		
	if(new_sum != sum) { flag = 0; }
		
	i = 0, j = n-1, new_sum = 0;
	
	while (i < n) { //for diagonal 2
		new_sum = new_sum + arr[i][j];
		i = i + 1;
		j = j - 1;
		}
		
	if(new_sum != sum) { flag = 0; }
				
	if(flag == 1) printf("it is a magic square\n");
	if(flag == 0) printf("it is NOT a magic square\n");
	
	return 0;
	
}
			
		
	
			
			
			
			
