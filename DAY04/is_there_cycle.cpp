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
# define VISITED 0;
# define UNVISITED 1;
# define CURRENTLY_VISITING 2;
long long MOD = 1e9 + 7;

bool dfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
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
            {
                edges.push_back({i, j});
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            graph[i][j] = nd;
            // adj[i].push_back(j);
            // adj[j].push_back(i);
        }
    // get the number of connected components using dfs
    vector<int> visited(n, UNVISITED);
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            count++;
            bool is_cycl = dfs(i, adj, visited);
        }
    cout << count << "\n";
}