# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
# include <vector>
# include <cmath>
# include <map>
using namespace std;
long long MOD = 1e9 + 7;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; // number of cities in the graph
    cin >> n;
    // read the graoh as an adjacency matrix
    int nd;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> nd;
            graph[i][j] = nd;
        }
    // print the graph
    cout << "The graph is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " :==> ";
        for (int j = 0; j < n; j++)
            if (graph[i][j] != 0)
            {
                cout << j << " ";
                edges.push_back({i, j});
            }
        cout << "\n";
    }

    cout << "The edges are:\n";
    for (auto e : edges)
        cout << e.first << ": --->" << e.second << "\n";
}