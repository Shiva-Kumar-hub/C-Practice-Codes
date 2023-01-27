#include<iostream>
#include<climits>
#include<algorithm>
#include <cstring>
using namespace std;

int b[100][100];

void print_lcs(char *X, int m, int n)
{
    int i = m, j = n;
    if (i == 0 || j == 0)
        return;
        
    if ( b[i][j] == -1)
    {
        print_lcs(X, i-1, j-1);
        cout << X[i-1];
    }
    else if (b[i][j] == 0)
        print_lcs(X, i-1, j);
    else if (b[i][j] == 1)
        print_lcs(X, i, j-1);
}

int lcs(char* X, char* Y, int m, int n)
{
    int i, j, c[m+1][n+1];
 
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                c[i][j] = 0;
  
            else if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = -1; // -1 represents top left arrow
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 0; // 0 represents up arrow 
            }
            else if(c[i - 1][j] < c[i][j - 1])
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 1; // 1 represents left arrow
            }
        }
    }
    cout << "Common subsequence of " << X << ", " << Y << " : ";
    print_lcs(X, m, n);
    return c[m][n];
}

int main()
{
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    
    int m = strlen(X);
    int n = strlen(Y);

    int result =  lcs(X, Y, m, n);
    cout << endl << "Length of LCS is: " << result << endl;
    
    return 0;
}
