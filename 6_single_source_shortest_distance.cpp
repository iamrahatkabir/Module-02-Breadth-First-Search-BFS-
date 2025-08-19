#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_arr[1005];

int level[1005];


void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited_arr[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(auto child : adj_list[parent])
        {
            if(!visited_arr[child])
            {
                q.push(child);
                visited_arr[child] = true;
                level[child] = level[parent] + 1;
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

    memset(visited_arr, false, sizeof(visited_arr));
    memset(level, -1, sizeof(level));

    int src, destination;
    cin >> src >> destination;

    bfs(src);

    // for(int i = 0; i < n; i++)
    // {
    //     cout << i << "-> " << level[i] << endl;
    // }

    cout << level[destination] << endl;

    return 0;
}
