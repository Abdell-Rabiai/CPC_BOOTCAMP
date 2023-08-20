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

void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &subs)
{
    int cc = 0;
    visited[start] = true;
    for (auto v : adj[start])
        if (!visited[v])
        {
            dfs(v, adj, visited, subs);
            cc += subs[v] + 1;
        }
    subs[start] = cc;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; // number of cities in the graph
    cin >> n;
    // read the graoh as an adjacency matrix
    int nd;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        //1 1 2 3
        cin >> nd;
        adj[nd - 1].push_back(i);
    }
    // print the list
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << " : ";
    //     for (auto i: adj[i])
    //         cout << i + 1 << " ";
    //     cout << "\n";
    // }
    vector<int> subs(n, 0);
    vector<bool> visited(n, false);
    dfs(0, adj, visited, subs);
    for (auto v: subs)
        cout << v <<" ";
    cout << "\n";
}