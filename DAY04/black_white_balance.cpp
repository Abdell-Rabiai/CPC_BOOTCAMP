
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

void dfs(int start, string colors, vector<vector<int>> &adj, vector<pair<int, int>> &black_white)
{
    if (colors[start] == 'B')
        black_white[start].first++;
    else
        black_white[start].second++;
    for (auto v : adj[start])
    {
        dfs(v, colors, adj, black_white);
        black_white[start].first += black_white[v].first;
        black_white[start].second += black_white[v].second;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; // number of cities in the graph
        cin >> n;
        // read the graoh as an adjacency matrix
        vector<int> parents(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++)
        {
            cin >> parents[i];
            adj[parents[i] - 1].push_back(i);
        }
        string colors;
        cin >> colors;
        vector<pair<int, int>> black_white(n, {0, 0});
        dfs(0, colors, adj, black_white);
        int count = 0;
        for (int i = 0; i < n; i++)
            if (black_white[i].first == black_white[i].second)
                count++;
        cout << count << "\n";
    }
}