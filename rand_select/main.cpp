#include <iostream>
using namespace std;

int partition_Subroutine(int a[], int pivot, int n)
{
    int i = pivot, l = a[i];
    for (int j = pivot+1; j <= n; j++) 
    {
        if (a[j] <= l)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i], a[pivot]);
    return i;
}

int randomized_partition(int a[], int pivot, int n)
{
    srand(time(NULL));
    int i = pivot + rand() % (n - pivot);
    swap(a[i], a[pivot]);
    return partition_Subroutine(a, pivot, n);
}

int randomized_select(int a[], int p, int r, int i)
{
    if (p == r)
        return a[p];
    
    int q = randomized_partition(a, p, r);
    int k = q-p+1;
    
    if (i == k)
        return a[q];
    else if (i < k)
        return randomized_select(a, p, q-1, i);
    else
        return randomized_select(a, q+1, r, i-k);
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
    
    int result = randomized_select(a, 1, size, i);
    cout << "The" << " " << i <<"th smallest element is: " <<result << endl;
    return 0;
}