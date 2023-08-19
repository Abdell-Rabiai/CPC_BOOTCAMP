# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <unordered_set>
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
    vector<vector<int>> list(n);
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
            list[u - 1].push_back(v);
            list[v - 1].push_back(u);
        }
        else if (add_print == 2)
        {
            cin >> vert;
            for (auto v : list[vert - 1])
                cout << v << " ";
            cout << "\n";
        }
    }
}