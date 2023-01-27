#include <bits/stdc++.h>
using namespace std;

vector< vector<pair<int, int> > > a;

vector<int> dijiksra(vector< vector<pair<int, int> > > &vec, int &start)
{
    vector<int> len;
    int n = vec.size();
    for(int i = 0; i < n; i++)
    {
        len.push_back(1000000007);
    }

    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(start, 0));
    len[start] = 0;


    while(pq.empty() == false)
    {
        int u = pq.top().first;
        pq.pop();

        for(int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i].first;
            int weight = vec[u][i].second;

            if(len[v] > len[u] + weight)
            {
                len[v] = len[u] + weight;
                pq.push(make_pair(v, len[v]));
            }
        }
    }

    return len;
}

int main()
{
    const int N = 7;
    for(int i = 0; i < N; i++)
    {
        vector<pair<int, int> > r;
        a.push_back(r);
    }
    
    a[0].push_back(make_pair(1, 2));
    a[0].push_back(make_pair(2, 3));
    
    a[1].push_back(make_pair(0, 2));
    a[1].push_back(make_pair(5, 1));

    a[2].push_back(make_pair(0, 3));
    a[2].push_back(make_pair(5, 2));

    a[3].push_back(make_pair(1, 4));
    a[3].push_back(make_pair(4, 1));
    a[3].push_back(make_pair(6, 2));

    a[4].push_back(make_pair(3, 1));
    a[4].push_back(make_pair(5, 2));
    a[4].push_back(make_pair(6, 1));

    a[5].push_back(make_pair(1, 1));
    a[5].push_back(make_pair(2, 2));
    a[5].push_back(make_pair(4, 2));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 2));
    a[6].push_back(make_pair(4, 1));
    a[6].push_back(make_pair(5, 2));
    
    //n =node
    int n = 0;
    vector<int> length = dijiksra(a, n);
    for(int i = 0; i < length.size(); i++)
    {
        cout << "Shortest distance from node 0" << " to node " << i << " is: " << length[i] << endl;
    }
    
    return 0;
}