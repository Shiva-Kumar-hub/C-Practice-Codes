// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
using namespace std;

int INF = 9999999;
#define V 5

 int G[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

void prims(int selected[], int no_edge)
{
    int x, y;
    cout << endl;
    while (no_edge < V - 1) 
    {
        int min = INF;
        x = 0;
        y = 0;  
    
        for (int i = 0; i < V; i++) 
        {
          if (selected[i]) 
          {
            for (int j = 0; j < V; j++) 
            {
              if (!selected[j] && G[i][j]) 
              {
                  if (min > G[i][j]) 
                  {
                  min = G[i][j];
                  x = i;
                  y = j;
                }
              }
            }
          }
        }
        cout << "Weight of edge " << x << " to edge " << y << " : " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
  }
}
int main() 
{
    int no_edge = 0;
    int selected[V];
    memset(selected, 0, sizeof(selected));
    selected[0] = 1;
    prims(selected, no_edge);

return 0;
}