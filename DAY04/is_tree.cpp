# include <iostream>
# include <algorithm>
# include <stack>
# include <queue>
# include <set>
# include <string>
# include <array>
# include <vector>
# include <cmath>
# include <map>
using namespace std;
long long MOD = 1e9 + 7;

void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[start] = true;
    for (auto v : adj[start])
        if (!visited[v])
            dfs(v, adj, visited);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; // number of cities in the graph
    cin >> n;
    // read the graoh as an adjacency matrix
    int nd;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> nd;
            if (nd == 1)
                edges.push_back({i, j});
            graph[i][j] = nd;
        }
    for (auto [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (edges.size() / 2 != n - 1)
    {
        cout << "NO\n";
        return 0;
    }
    // Check if the graph is all connected using dfs or bfs
    vector<bool> visited(n, false);
    dfs(0, adj, visited);
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
}