#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
//declaring a 2 dimensional array to store the sum of different array group elements
int c[N][N];

//function to calculate the max sum of different array group elements
int max_min_sum(int arr[], int n, int m)
{
    int i = n, j = m, maxMinSum = -1;
    
    if(i < j)
        return -1;
        
    if(c[i][j] != 0)
        return c[i][j];
    
    //looping from j-1 (no of partitions - 1) to i (array size)
    for(int k = j-1; k < i; k++) // loop for top-down approach
    //for(int k = i-1; k >= j-1; k--) //loop for bottom up approach 
    {
        int minSum = min(max_min_sum(arr,k,j-1), c[i][1]-c[k][1]);
        if(maxMinSum < minSum) 
        {
            maxMinSum = minSum;
        }
    }

c[i][j] = maxMinSum;
return maxMinSum;

}

//function to calculate the grouping to given array depending on the
//max min sum from above function
int *MaxMinGrouping(int arr[], int n, int m)
{
    int result = max_min_sum(arr, n, m);
    cout << "The maximum of the minimum element sum is: "<< result << endl;
    
    //g array, used to store the number of elements in
    //each group and initilaizing the array with 0.
    int *g = new int[m];
    memset(g, 0, sizeof(g));
    
    int j = 1, k = 0;
    
    //calculating the number of elements in each group 
    //using c[][] array
    for (int i = 1; i <= n; i++)
    {
        k++;
        if(c[i][j] >= result)
        {
            g[j] = k;
            j++;
            k = 0;
        }
    }
    
    return g;
}
    
//main function
int main()
{
    int arr[N], i, j, n, m;
    
    cout << "Enter the number of array elements" << endl;
    cin >> n;
    
    cout << "Enter the array elements" << endl;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the number of divisions" << endl;
    cin >> m;
    
    //initializing all the elements of array c[][] with value 0
    memset(c, 0, sizeof(c));
    
    //calculating c[i][1], which is just the sum of
    //precedding array elements of arr[i].
    c[1][1] = arr[1];
    for(i = 2; i <=n; i++)
    {
        c[i][1] = c[i-1][1] + arr[i]; 
    }
    
    int *G = MaxMinGrouping(arr, n, m);
    
    cout << "the sizes of the" << " " << m  << " " << "are: ";
    for(i = 1; i <= m; i++)
    {
        cout << G[i] << " ";
    }
    
    cout << endl << endl;
    return 0;
    
}

