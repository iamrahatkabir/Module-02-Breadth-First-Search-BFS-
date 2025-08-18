#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_arr[1005];


void bfs(int src)
{
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        visited_arr[parent] = true;

        cout << parent << endl;

        for(int child : adj_list[parent])
        {
            if(visited_arr[child] == true)
            {
                q.push(child);
                visited_arr[child] = false;
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

    bfs(0);

    return 0;
}
