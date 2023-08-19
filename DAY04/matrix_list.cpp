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
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] == 1)
                edges.push_back({i+1, j+1});
    for (auto e : edges)
        cout << e.first << " " << e.second << "\n";
    // print the edges
    // for (int i = 0; i < n; i++)
    //     for (int j = i + 1; j < n; j++)
    //         if (graph[i][j] == 1)
    //             cout << i+1 << " " << j+1 << "\n";   
}