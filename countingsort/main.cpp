#include<iostream>
using namespace std;

void countingSort(int a[], int N, int range)
{
    
    int  k = range, i, j, countArray[k], output[N];
    //initializing the counting array with zeros
    for (i = 0; i < k; i++)
    {
        countArray[i] = 0;
    }
    

    //counting the input array elements and storing 
    //the count value in countArray
    for (i = 0; i < N; i++)
    {
        countArray[a[i]]++;
    }
    /*
    for(i = 0; i <= k; i++)
    cout << countArray[i] << " ";
    cout << endl;
    */
    //findind the cummulative sum and storing the
    // result in countArray
    for (i = 1; i < k; i++)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }
    /*
    for(i = 0; i <= k; i++)
    cout << countArray[i] << " ";
    */
    // Find the index of each element of the original array 
    //in count array, and place the elements in output array
    for (i = N-1; i >= 0; i--) 
    { 
        output[countArray[a[i]] - 1] = a[i];
        countArray[a[i]]--;
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


int main()
{
    int i, n, range, arr[]={20, 18, 5, 7, 16, 
    10, 9, 3, 12, 14, 0};
    
    range = arr[0];
    n = sizeof(arr)/sizeof(arr[0]);
    
    //Findind the range of the array arr.
    for (i = 0; i < n; i++)
    {
        if(arr[i] > range)
        range = arr[i];
    }
    cout << "Array before performing counting sort:"<< endl;
    displayArray(arr, n);
    countingSort(arr, n, range);
    cout << "Array after performing counting sort:"<< endl;
    displayArray(arr, n);

    return 0;
}