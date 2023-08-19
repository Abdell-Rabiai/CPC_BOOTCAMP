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
    int n; // number of vertices in a graph
    cin >> n;
    // vector<vector<int>> graph(n, vector<int>(n));
    vector<pair<int, int>> edges;
    vector<int> vertices_to_print;
    int op;
    cin >> op;
    int add_print, u, v;
    int vert;
    while (op--)
    {
        cin >> add_print;
        if (add_print == 1)
        {
            cin >> u;
            cin >> v;
            edges.push_back({u, v});
        }
        else if (add_print == 2)
        {
            cin >> vert;
            vertices_to_print.push_back(vert);
        }
    }
    for (auto [x, y] : edges)
    {
        graph[x - 1][y - 1] = 1;
        graph[y - 1][x - 1] = 1;
    }
    // print the graph
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //             cout << graph[i][j] << " ";
    //     cout << "\n";
    // }
    for (auto v : vertices_to_print)
    {
        for (int i = 0; i < n; i++)
            if (graph[v - 1][i] == 1)
                cout << i + 1 << " ";
    }
}

// 50 / 100