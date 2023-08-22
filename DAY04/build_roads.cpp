/*Byteland has nn cities, and mm roads between them. The goal is to construct new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input

The first input line has two integers nn and mm: the number of cities and roads. The cities are numbered 1,2,…,n1,2,…,n.

After that, there are mm lines describing the roads. Each line has two integers aa and bb: there is a road between those cities.

A road always connects two different cities, and there is at most one road between any two cities.

Output

First print an integer kk: the number of required roads.

Then, print kk lines that describe the new roads. You can print any valid solution.*/
/*
input 
4 2
1 2
3 4
output
1
2 3
*/
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
    {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; // number of cities
    int m; cin >> m; // number of roads
    vector<vector<int>> adj(n);
    while (m--)
    {
        int c1, c2;
        cin >> c1 >> c2;
        adj[c1 - 1].push_back(c2 - 1);
        adj[c2 - 1].push_back(c1 - 1);
    }
    vector<bool> vis(n, 0);
    vector<int> edges;
    int k = 0;
    for (int i = 0; i < n ; i++)
    {
        if (vis[i] == 0)
        {
            edges.push_back(i + 1);
            dfs(i, adj, vis);
            k++;
        }
    }
    cout << k - 1 << "\n";
    for (int i = 1; i < k; i++)
        cout << edges[i-1] << " " << edges[i] << "\n";
}