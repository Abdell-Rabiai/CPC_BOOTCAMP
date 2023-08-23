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

bool is_valid(pair<int, int> move, int n, int m, vector<vector<bool>> &vis)
{
    int i = move.first;
    int j = move.second;
    return (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false);
}

void dfs(pair<int, int> start, vector<pair<int, int>> &moves, vector<vector<bool>> &visited, int n, int m)
{
    int i = start.first;
    int j = start.second;
    visited[i][j] = true;
    for (auto mv : moves)
    {
        mv = {i + mv.first, j + mv.second};
        if (is_valid(mv, n, m, visited))
            dfs(mv, moves, visited, n, m);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // THIS IS A MAP (N * M);
    int n; cin >> n; // height of the map
    int m; cin >> m; // width of the map (number of characters in each line)
    int rooms = 0;
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right left down up
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            char c; cin >> c;
            if (c == '#')
                vis[i][j] = true;
            else
                vis[i][j] = false;
        }
    }
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            if (vis[i][j] == false)
            {
                dfs({i, j}, moves, vis, n, m);
                rooms++;
            }
        }
    }
    cout << rooms << "\n";
}