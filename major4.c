/*
 * This program performs various operations on a list of words provided by the user.
 *
 * Features:
 * 1. Accepts 'N' words with a maximum length of 'M' characters from the user.
 * 2. Sorts the words lexicographically using the LexSort function.
 * 3. Displays word statistics:
 *    - Sorted list of words.
 *    - Count of words based on length categories (1-2, 3-5, 6-10, >10).
 * 4. Computes alphabet statistics:
 *    - Total number of letters.
 *    - Count of vowels and consonants.
 *    - Percentage distribution of each letter (a-z) visualized as a histogram.
 * 5. Identifies and prints duplicate words in the list.
 * 6. Efficiently manages memory by dynamically allocating and freeing memory for word storage.
 */


 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LexSort (char **arr, int N, int M) //lexsort function that sorts words lexicographically
{
	int i, j;
	char temp1[M], temp2[M];
	
	for(i = 0; i < N; i++)
	{
		for(j = i +1; j < N; j++)
		{
			if(strcmp(arr[i], arr[j]) > 0) 
			{
				strcpy(temp1, arr[i]);
				strcpy(temp2, arr[j]);
				arr[i] = (char *) realloc(arr[i], (strlen(arr[j]) + 1)*sizeof(char));
				arr[j] = (char *) realloc(arr[j], (strlen(arr[i]) + 1)*sizeof(char));
				strcpy(arr[j], temp1);
				strcpy(arr[i], temp2);
			}
		}
	}
}

int main ()
{
	int M, N, i;
	char temp[M+5];
	
	printf("Enter Number of Words: ");
	scanf("%d", &N);
	printf("Enter Maximum Length of Words: ");
	scanf("%d", &M);
	
	char **arr = (char **) malloc(N * sizeof(char *)); //dynamically allocating 2D array for strings
	
	printf("Enter %d Words into Words-Array:\n", N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%s", temp);
		if( strlen(temp) > M)
		{
			printf("One of the words have more than 30 charecters, type entire sentence again:\n");
			i--;
			continue;
		}
		
		else 
		{
		arr[i] = (char *) malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(arr[i], temp);
		}
	}
	
	LexSort (arr, N, M); //calling lexsort function
	
	printf("\n+++ Word Statistics +++");
	printf("\n-- Sorted 20 Words from Words-Array --\n");
	
	for (i = 0; i < N; i++)
	{
		printf("%s, ", arr[i]);
	}
	
	int x = 0, y = 0, z = 0, w = 0;
	printf("\n-- The Word Length Statistics --");
	
	for(i = 0; i < N; i++)  //printing number of words with different lengths
	{
		if(strlen(arr[i]) >= 1 && strlen(arr[i]) <= 2) x++;
		if(strlen(arr[i]) >= 3 && strlen(arr[i]) <= 5) y++;
		if(strlen(arr[i]) >= 6 && strlen(arr[i]) <= 10) z++;
		if(strlen(arr[i]) > 10) w++;
	}
	
			
	printf("\nNumber of Words with Length 1-2: %d", x);
	printf("\nNumber of Words with Length 3-5: %d", y);
	printf("\nNumber of Words with Length 6-10: %d", z);
	printf("\nNumber of Words with Length greater than 10: %d", w);
	
	printf("\n-- The Alphabet Distribution --");
	
	int sum = 0;
	
	//sum stores total number of letters
	for(i = 0; i < N; i++)
	{
		sum = sum + strlen(arr[i]);
	}
	
	printf("\nTotal Number of Letters Present = %d", sum);
	
	int j, vowels = 0, consonants = 0;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < strlen(arr[i]); j++)
		{
			if(arr[i][j] == 'a' || arr[i][j] == 'e' || arr[i][j] == 'i' || arr[i][j] == 'o' || arr[i][j] == 'u') vowels++;
			else consonants++;
		}
	}
	
	printf("\nTotal Number of Vowels Present = %d", vowels);
	printf("\nTotal Number of Consonants Present = %d", consonants);
	
	printf("\n-- The Percentage Distribution of the Letters a-z --\n");
	
	
	int percentDistribution[26], k;  //percentdistribution array stores number of times each letter occurs
	
	for(i = 0; i<26; i++)
	{
		percentDistribution[i] = 0;
	}
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < strlen(arr[i]); j++)
		{
			for(k = 0; k < 26; k++)
			{
				if(arr[i][j] == 'a' + k || arr[i][j] == 'A' + k) percentDistribution[k]++;
			}
		}
	}
	
	char alpha = 'a';
	for(k = 0; k < 26; k++) //this for loop prints the graph 
	{
		printf("%c[%.0f percent ]: ", alpha + k, (float) (percentDistribution[k]*100)/sum);
		for(i = 0; i < percentDistribution[k]; i++)
			{
				printf("=");
			}
		printf("\n");
	}
	
	printf("\n-- Duplicate Words --\n ");
	
	for(i = 0; i < N; i++) //for loop for finding duplicate words
	{
		for(j = i+1; j < N; j++)
		{
			if(strcmp(arr[i], arr[j]) == 0) printf("%s", arr[i]);
		}
	}
	
	printf("\n--------------------");
	
	for(i = 0; i < N; i++)
	{
		free(arr[i]);
	}
	
	free(arr);
	
	return 0;
	
}