/*
A square matrix A = (ai,j)i,j∈[n] of size n × n is called symmetric if ai,j = aj,i for all indices
i, j ∈ [n]. A is called skew-symmetric if ai,j = −aj,i for all indices i, j ∈ [n] for all indices
i, j ∈ [n] with i ̸= j. Write a C program that first reads a positive integer n as input and uses
dynamic memory allocation to create a 2-D array A describing an n × n matrix A in the main
function. Input the matrix A in a row-major format and print it from the main function. Next, write
a function Sym-SSym() that inputs A, computes a symmetric matrix B and a skew-symmetric
matrix C satisfying A = B + C. Print the matrices B and C from within the function.
*/

#include <stdio.h>
#include <stdlib.h>

int** transpose (int** A, int n) // function which does transpose and stores in another matrix B, returns double pointer B
{
	int i, j, temp;
	
	int **B = (int **)malloc(n * sizeof(int *));
	
	for(i = 0; i < n; i++) {
	B[i] = (int *)malloc(n * sizeof(int));
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			B[i][j] = A[i][j];
			}
		}
	
	for(i = 0; i < n-1; i++) {
		for(j = i + 1; j < n; j++) {
			temp = B[i][j];
			B[i][j] = B[j][i];
			B[j][i] = temp;
			}
		}
		
	return B;
	
}
			
	
	

void Sym_SSym (int **A, int n) // function prints symmetric and skew symmetric arrays using mathematical defn
{
	int i, j;
	
	int **B = transpose (A, n);
	
	printf("The symmetric matrix B is: \n");
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%.1f  ", ((float) (A[i][j] + B[i][j]) /2.0));
			}
			printf("\n");
		}
			
	printf("The skew symmetric matrix C is: \n");
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%.1f  ", ((float) (A[i][j] - B[i][j]) /2));
			}
			printf("\n");
		}
	
}
		
int main ()
{

	int n, i, j;
	
	printf("Type a positive integer, n: "); //input from user, order of matrix
	scanf("%d", &n);
	
	int **arr = (int **)malloc(n * sizeof(int *));
	
	for(i = 0; i < n; i++) {
	arr[i] = (int *)malloc(n * sizeof(int));
	}
	
	printf("Enter the input matrix A in a row-major format: ");
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			}
		}
		
	printf("The entered matrix A:\n");
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		
	Sym_SSym (arr, n);
	
	return 0;
}
