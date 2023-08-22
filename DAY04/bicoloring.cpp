/* Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

Input

The first input line has an integer nn: the number of employees. The employees are numbered 1,2,…,n1,2,…,n, and employee 11 is the general director of the company.

After this, there are n−1n−1 integers: for each employee 2,3,…,n2,3,…,n their direct boss in the company.

Output

Print nn integers: for each employee 1,2,…,n1,2,…,n the number of their subordinates.

Constraints

    1≤n≤2⋅1051≤n≤2⋅105*/
/*
input 
5
1 1 2 3
output
4 1 1 0 0
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
#define RED 1
#define BLUE 2
#define UNCOLORED 0
bool dfs(int start, int start_color, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &colored)
{
    visited[start] = true;
    colored[start] = start_color;
    for (auto v : adj[start])
    {
        if (!visited[v])
        {
            if (!dfs(v, start_color == RED ? BLUE : RED, adj, visited, colored))
                return false;
        }
        else if (colored[v] == colored[start])
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1)
    {
        int n; // number of cities in the graph
        cin >> n;
        if (!n)
            break;
        // read the graoh as an adjacency matrix
        int m;
        cin >> m;
        vector<vector<int>> adj(n);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        vector<int> colored(n, UNCOLORED);
        vector<bool> visited(n, false);
        bool is_colorable = dfs(0, RED, adj, visited, colored);
        if (is_colorable)
            cout << "BICOLOURABLE.\n";
        else
            cout << "NOT BICOLOURABLE.\n";
    }
}