//Sophia Kropivnitkaia 
//Lab_Assignment_7
//03/08/2024
//COP 3502C

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int *totalSwaps)
{
   int i, j,temp;
   int* swaps = (int*)malloc(sizeof(int) * n);
   for (i = 0; i < n; i++) {
    swaps[i] = 0;
   }

   for (i = 0; i < n-1; i++)
   {
        for (j = 0; j < n-i-1; j++)
        {
           if (arr[j] > arr[j+1])
           {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;

             temp=swaps[j];
             swaps[j]=swaps[j+1];
             swaps[j+1]=temp;

             swaps[j]++;
             swaps[j+1]++;

            (*totalSwaps)++;
           }
        }
    }

   for (i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swaps[i]);
   }

   free(swaps);
}

void selectionSort(int arr[], int n, int *totalSwaps)
{
	int i, j, min_idx, temp;
    int* swaps = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        swaps[i] = 0;
    }

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		// Swap the found minimum element with the first element
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;

        temp=swaps[i];
        swaps[i] = swaps[min_idx];
        swaps[min_idx] = temp;

        swaps[i]++;
        swaps[min_idx]++;

        (*totalSwaps)++;
	}

    for (i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[i]);
    }

    free(swaps);
}

int main()
{
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int totalSwaps = 0;
    int totalSwaps2 = 0;
    int n = 9; 

    bubbleSort(arr, n, &totalSwaps);
    printf(" %d\n", totalSwaps);

    bubbleSort(arr2, n, &totalSwaps2);
    printf(" %d\n", totalSwaps2);

    int sarr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int sarr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    totalSwaps = 0;
    totalSwaps2 = 0;
    n = 9; 

    selectionSort(sarr, n, &totalSwaps);
    printf("%d\n", totalSwaps);

    selectionSort(sarr2, n, &totalSwaps2);
    printf(" %d\n", totalSwaps2);

    return 0;
}
