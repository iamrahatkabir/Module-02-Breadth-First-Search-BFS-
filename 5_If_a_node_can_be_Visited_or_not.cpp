#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_array[1005];


void bsf(int src)
{
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        visited_array[parent] = true;

        // cout << parent << " ";

        for(auto child : adj_list[parent])
        {
            if(!visited_array[child])
            {
                q.push(child);
                visited_array[child] = true;
            }
        }

    }
    
}


int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited_array, false, sizeof(visited_array));

    int src, destination;
    cin >> src >> destination;

    bsf(src);

    if(visited_array[destination])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
