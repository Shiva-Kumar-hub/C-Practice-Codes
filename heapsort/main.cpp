#include<iostream>
using namespace std;

void max_heapify(int a[], int N, int i)
{
    int left, right, largest;
    
        left = 2*i + 1;
        right = 2*i + 2;
        if (left < N && a[left] > a[i])
            largest = left;
        else 
            largest = i;
        
        if (right < N && a[right] > a[largest] )
            largest = right;
            
        if (largest != i)
        {
            swap(a[i], a[largest]);
            max_heapify(a, N, largest);
        }
}

//function for swaping two array elements 
void swap(int a[], int l)
{
    int temp = a[l];
    a[l] = a[0];
    a[0] = temp;
}

int main()
{
    int i, j, n = 100, arr[n];
    // Generating random permutation of numbers 
    // between 1 to 100 and storing it to an array.
    for ( i = 0; i < 100; i++ )
    {
          int num = 1 + (rand() % 100);
          arr[i] = num;
    }
    //Printing the array elements before sorting
    cout << "Array elements before performing heap sort: " << endl;
    for (i = 0; i < n; i ++)
        cout << arr[i] << "  ";
        
    cout<< endl << endl;

    //creating max heap arrays
    for(i = n/2 - 1; i >= 0; i--)
    {
    max_heapify(arr, n, i);
    }
    
    for (i = n-1; i > 0; i --)
    {
        swap(arr[i], arr[0]);
        max_heapify(arr, i, 0);
    }
    
    //printing the array elements after performing heap sort
    cout << "Array elements after heap sort: " << endl;
    for ( i = 0; i < n; i ++)
    cout << arr[i] << "  ";
    
return 0;
}
