/*
Write a function to read an integer n (<100) and then read n integers to be stored in array A[]. Now read a key K, and search if
the value is present in the array A[]. You have to use the binary search algorithm. The function int RecBinSearch(n, A, K) should take
as input the value of n and array A[], along with the value K, and return 1 if K is in A[], and 0 otherwise. The function should be
recursive and use pointers.
*/

#include <stdio.h>
#include <stdlib.h>

//sorting function to sort array since binary search can only be applied on sorted arrays
void bubbleSort (int A[], int n) 
{
    int i, j, temp;
    
    //logic of bubblesort: if higher indexed element has lower value than it's preceeding element then they are swapped
    //extra variable temp is used for swapping here
    for (i = 0; i < n; i++) {
        for(j = 0; j < n - i -1; j++) {
            if(A[j] > A[j+1]) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int RecBinSearch(int n, int A[], int key) 
//recursive version of binary search with provided function statements
{
    int *mid; //mid pointer declared
    
    if (n <= 0) { return 0; } //condition for when key element is NOT found

    mid = A + n / 2;

    if (*mid == key) { return 1; } //condition for when key element is found
    
    //recursive call when mid element is lower than key - the element after mid becomes the starting element, last element reamins same
    else if (*mid < key) { return RecBinSearch(n/2, mid + 1, key); } 
    
    //recursive call when mid element is higher than key - starting element remains same, last element is either the mid element or the element preceeding it
    else if (*mid > key) { return RecBinSearch(n/2, A, key); }
}

int main ()
{
    int n, i, key, result;

    printf("Enter the number of elements, n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d array elements:\n", n);
    for ( i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    bubbleSort (arr, n); //sorting the array input by user before execting binary search

    printf("Enter the key to search: ");
    scanf("%d", &key);

    result = RecBinSearch(n, arr, key); //executing binary search

    if (result == 1) printf("Key found in the array.");
    if (result == 0) printf("Key not found in the array.");

    return 0;
}