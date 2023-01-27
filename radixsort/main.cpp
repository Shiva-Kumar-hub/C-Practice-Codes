#include<iostream>
using namespace std;


void countingSort(int a[], int N, int d)
{
    int  k = d, i, j, countArray[10], output[N];
    
    //initializing the counting array with zeros
    for (i = 0; i < 10; i++)
    {
        countArray[i] = 0;
    }
    
    //counting the input array elements and storing 
    //the count value in countArray
    for (i = 0; i < N; i++)
    {
        countArray[ (a[i]/k)%10 ]++;
    }
    
    //findind the cummulative sum and storing the
    // result in countArray
    for (i = 1; i < 10; i++)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }
    
    // Find the index of each element of the original array 
    //in count array, and place the elements in output array
    for (i = N-1; i >= 0; i--) 
    { 
        output[countArray[ (a[i]/k)%10 ] - 1] = a[i];
        countArray[ (a[i]/k)%10 ]--;
    }
    
    //copying the output array elements to original array a
    for ( i = 0; i < N; i++)
    a[i] = output[i];
}

//function to print the array 
void displayArray(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
}

//Main function
int main()
{
    int i, n, max, arr[]={329, 457, 657, 839, 436, 720, 353};
    
    max = arr[0];
    n = sizeof(arr)/sizeof(arr[0]);
    
    //Findind the max number of the array arr.
    for (i = 0; i < n; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }
    cout << "Array before performing Radix sort:"<< endl;
    displayArray(arr, n);
    
    //radix sort
    for ( int d = 1; max/d > 0 ; d *= 10)
    {
        countingSort(arr, n, d);
    }
    
    cout << "Array after performing Radix sort:"<< endl;
    displayArray(arr, n);

    return 0;
}