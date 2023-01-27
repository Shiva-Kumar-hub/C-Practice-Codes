#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int partition(int a[], int p, int q, int r)
{
	int i;
	for (i = p; i < q; i++)
		if (a[i] == r)
		break;
	
	swap(a[i], a[q]);
	i = p;
	for (int j = p; j <= q - 1; j++)
	{
		if (a[j] <= r)
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[q]);
	return i;
}

//function to find the median
int findMedian(int a[], int n)
{
	sort(a, a+n);
	return a[n/2];
}

int select_kth_smallest(int a[], int p, int q, int k)
{
	
	if (k > 0 && k <= q - p + 1)
	{
		int n = q-p+1, i, med[(n+4)/5];
		
		for (i=0; i<n/5; i++)
			med[i] = findMedian(a+p+i*5, 5);
			
		if (i*5 < n)
		{
			med[i] = findMedian(a+p+i*5, n%5);
			i++;
		}
		
		int medOfMedian = (i == 1)? med[i-1] : select_kth_smallest(med, 0, i-1, i/2);

		int position = partition(a, p, q, medOfMedian);

		if (position-p == k-1)
			return a[position];
		if (position-p > k-1)
			return select_kth_smallest(a, p, position-1, k);

		// Else recur for right subarray
		return select_kth_smallest(a, position+1, q, k-position+p-1);
	}

	return INT_MAX;
}

int main()
{
    int size = 100, n = 100, a[size], i, j;
    
    //initializing the array
    for(int i = 1; i <= size; i++)
    {
        a[i] = i;
    }
    
    //generating random permutation from 1 to 100
    //and storing into the array    
    for(int i = 1; i <= size; i++)
    {
        int randIdx = rand() % size;
        swap(a[i], a[randIdx]);
    }
    
    cout << "The input array is: " << endl;
    for (j = 1; j <= size; j ++)
    {
        cout << a[j] << " ";
    }
    
    cout << endl;
    
    cout << "Enter the smallest element you want to find out: ";
    cin >> i;
    
    int result = select_kth_smallest(a, 1, n, i);
	cout << i << "'th smallest element is: "
		<< result ;
	return 0;
}

/*
same program with comments from geeks for geeks

// C++ implementation of worst case linear time algorithm
// to find k'th smallest element
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int partition(int arr[], int l, int r, int k);

// A simple function to find median of arr[]. This is called
// only for an array of size 5 in this program.
int findMedian(int arr[], int n)
{
	sort(arr, arr+n); // Sort the array
	return arr[n/2]; // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1; // Number of elements in arr[l..r]

		// Divide arr[] in groups of size 5, calculate median
		// of every group and store it in median[] array.
		int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+l+i*5, 5);
		if (i*5 < n) //For last group with less than 5 elements
		{
			median[i] = findMedian(arr+l+i*5, n%5);
			i++;
		}

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		int medOfMed = (i == 1)? median[i-1]:
								kthSmallest(median, 0, i-1, i/2);

		// Partition the array around a random element and
		// get position of pivot element in sorted array
		int pos = partition(arr, l, r, medOfMed);

		// If position is same as k
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1) // If position is more, recur for left
			return kthSmallest(arr, l, pos-1, k);

		// Else recur for right subarray
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(int arr[], int l, int r, int x)
{
	// Search for x in arr[l..r] and move it to end
	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);

	// Standard partition algorithm
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

// Driver program to test above methods
int main()
{
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int n = sizeof(arr)/sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is "
		<< kthSmallest(arr, 0, n-1, k);
	return 0;
}
*/            
