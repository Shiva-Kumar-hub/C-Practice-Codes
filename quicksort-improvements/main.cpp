#include<iostream>
using namespace std;

void three_way_partition(int arr[],  int &b, int &e, int lo, int hi)
{
  int pivot=arr[lo];
  b=lo, e=hi;
  for(int i=b+1 ; i<=e; i++)
  {
    if(arr[i] < pivot)
    {
      swap(arr[i], arr[b]);
      b++;
    }
    else if(arr[i] > pivot)
    {
      swap(arr[i], arr[e]);
      e--; 
      i--;
    }
  }
}

void quickSort(int arr[], int lo, int hi)
{
  if(lo >= hi)
  {
    return;
  }
  int b, e;
  three_way_partition(arr, b, e, lo, hi);
  quickSort(arr, lo, b-1);
  quickSort(arr, e+1, hi);
}

void display_array(int a[], int n)
{   
    for (int i = 0; i < n; i++)   
    {  
        cout << a[i] << " ";
    }
}

int main() 
{ 
    int i, n;
    cout << "Enter the array size: ";
    cin >> n;
    int arr[n];
    cout <<"Please enter " << n << " repeted elements" << endl;
    for ( i = 0; i < n; i++)
    cin >> arr[i];
    cout << "Array before sorting:" << endl;   
    display_array(arr, n);
    quickSort(arr, 0, n-1);
    cout << endl << "Array after sorting:" << endl;   
    display_array(arr, n);
    return 0;
}
