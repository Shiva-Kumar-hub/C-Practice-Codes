#include <iostream>
#include<chrono>
using namespace std; 

int part_Subroutine(int a[], int pivot, int n) 
{ 
    int i = pivot, l = a[i]; 
    for (int j = pivot+1; j <= n; j++) { 
        if (a[j] <= l) 
            i++;
    } 
    swap(a[i], a[pivot]); 
    return i; 
}

int random_partSubroutine(int a[], int pivot, int n) 
{
    srand(time(NULL));
    int i = pivot + rand() % (n - pivot); 
    swap(a[i], a[pivot]); 
    return part_Subroutine(a, pivot, n); 
}

void randomized_QuickSort(int a[], int pivot, int n)
{ 
    if (pivot < n) 
    { 
        int k = random_partSubroutine(a, pivot, n); 
        randomized_QuickSort(a, pivot, k-1); 
        randomized_QuickSort(a, k+1, n); 
    } 
    else 
    { 
        return; 
    }
}

void display_array(int a[], int n)
{   
    for (int i = 0; i < n; i++)   
    {  
        cout << a[i] << " ";
    }
}

//MAin function
int main() 

{ 

    int i, n = 100, arr[n], number = 1;
    
    //declaring an array of size 100 and assigning
    // tehe array with random numbers from 1 to 100.
    for( i = 0; i < n; i++ )   
    { 
        arr[i] = number;   
        number++;    
    }
    
    cout << "Array before sorting:" << endl;   
    display_array(arr, n);
    clock_t startTime = clock();
    randomized_QuickSort(arr, 0, n-1);
    clock_t endTime = clock();
    double runningTime = ((double) (endTime - startTime) / (double) CLOCKS_PER_SEC);
    cout << endl << "Array after sorting:" << endl;   
    display_array(arr, n);
    cout << endl << "Running Time: " << runningTime << endl;
    return 0;
}

