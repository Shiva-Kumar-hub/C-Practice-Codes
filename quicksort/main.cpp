#include <iostream> 
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

 

void quickSort(int a[], int pivot, int n)
{ 
    if (pivot < n) 
    { 
        int k = part_Subroutine(a, pivot, n); 
        quickSort(a, pivot, k-1); 
        quickSort(a, k+1, n); 
    } 
    else 
    { 
        return; 
    }
}

void display_array (int a[], int n)
{   
    for (int i = 0; i < n; i++)   
    {  
        cout << a[i] << " ";
    }
}

//MAin function
int main() 

{ 

    int i, n = 100, arr[n], number = 100;
    
    //declaring an array of size 100 and assigning
    // tehe array with random numbers from 1 to 100.
    for( i = 0; i < n; i++ )   
    { 
        arr[i] = number;   
        number--;    
    }
    
    cout << "Array before sorting:" << endl;   
    display_array(arr, n);   
    quickSort(arr, 0, n-1);
    cout << endl << "Array after sorting:" << endl;   
    display_array(arr, n); 
    return 0;
}

