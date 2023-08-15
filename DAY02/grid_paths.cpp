# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
# include <queue>
# include <vector>
# include <utility>
# include <functional>
# include <deque>
# include <list>
# include <map>
using namespace std;

void print_grid(vector<vector<char>> &grid)
{
    printf("\n______________________\n");
    for (auto &row : grid)
    {
        for (auto &cell : row)
            cout << cell;
        cout << endl;
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    const int MOD = 1e9 + 7;

    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    vector<vector<int>> path(n, vector<int>(n));
    if (grid[0][0] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    path[0][0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
                path[i][j] = 0;
            else
            {
                if (i > 0)
                    path[i][j] += path[i-1][j] % MOD;
                if (j > 0)
                    path[i][j] += path[i][j-1] % MOD;
            }
        }
    }
    cout << (path[n-1][n-1] % MOD) << endl;
}