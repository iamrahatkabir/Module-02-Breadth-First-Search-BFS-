#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_arr[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited_arr[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_list[par]) //child will take the values of adj_list[par]-> this index;
        {
            if (!visited_arr[child])
            {
                q.push(child);
                visited_arr[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }

        // for (int i = 0; i < adj_list[par].size(); i++)
        // {
        //     int child = adj_list[par][i]; // manually access element
        //     if (!visited_arr[child])
        //     {
        //         q.push(child);
        //         visited_arr[child] = true;
        //         level[child] = level[par] + 1;
        //         parent[child] = par;
        //     }
        // }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited_arr, false, sizeof(visited_arr));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src, destination;
    cin >> src >> destination;

    bfs(src);

    vector<int> path;

    int node = destination;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << " ";
    }

    return 0;
}
