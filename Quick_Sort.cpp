/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (vector<int> &arr, int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(vector<int> &arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(vector<int> &arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
    time_t start = time(NULL);
    int n;
    cin>>n;
	vector<int> arr(n);
    for(int i = 0;i<n;i++){
        arr[i] = rand();
    }
	quickSort(arr, 0, n - 1);
	// cout << "Sorted array: \n";
	// printArray(arr, n);
    time_t end = time(NULL);
    printf("%f\n",difftime(end,start));
    int diff = (int)difftime(end,start);
    int seconds = diff % 60;
    int minutes = ((diff - seconds)/60) % 60;
    int hours = ((diff -seconds - 60*minutes)/3600);
    printf("Time taken is %d:%d:%d\n",hours,minutes,seconds);
	return 0;
}

// This code is contributed by rathbhupendra
