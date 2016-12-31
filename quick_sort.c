#include <stdio.h>

typedef int item_type;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void show_array(int arr[], int size) 
{
	int i, j;
	for(i=0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int partition(item_type s[], int lowerBound, int upperBound)
{
	int firsthigh;
	int i;
	int pivot;

	pivot = upperBound;
	firsthigh = lowerBound;

	for(i=lowerBound; i<upperBound; i++)
	{
		if (s[i] < s[pivot])
		{
			swap(&s[i], &s[firsthigh]);
			firsthigh++;
		}
	}
	swap(&s[pivot], &s[firsthigh]);

	return (firsthigh);
}

void quick_sort(item_type s[], int lowerBound, int upperBound)
{
	/* pick pivot point, perform q sort on both subsets */
	int p;
	if ((upperBound - lowerBound) > 0)
	{
		p = partition(s, lowerBound, upperBound);
		quick_sort(s, lowerBound, p-1);
		quick_sort(s, p+1, upperBound);
	}
}

void quicksort(item_type s[], int n)
{
	quick_sort(s, 0, n);
}

int main()
{
	int size = 10;
	item_type array[] = {9,7,8,5,6,3,4,2,1,0}; 
	quicksort(array, size);
	show_array(array, size);
	return(1);
}