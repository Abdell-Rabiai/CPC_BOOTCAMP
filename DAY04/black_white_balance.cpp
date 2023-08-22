 /* You are given a rooted tree consisting of nn vertices numbered from 11 to nn. The root is vertex 11. There is also a string ss denoting the color of each vertex: if si=Bsi​=B, then vertex ii is black, and if si=Wsi​=W, then vertex ii is white.

    A subtree of the tree is called balanced if the number of white vertices equals the number of black vertices. Count the number of balanced subtrees.

    A tree is a connected undirected graph without cycles. A rooted tree is a tree with a selected vertex, which is called the root. In this problem, all trees have root 11.

    The tree is specified by an array of parents a2,…,ana2​,…,an​ containing n−1n−1 numbers: aiai​ is the parent of the vertex with the number ii for all i=2,…,ni=2,…,n. The parent of a vertex uu is a vertex that is the next vertex on a simple path from uu to the root.

    The subtree of a vertex uu is the set of all vertices that pass through uu on a simple path to the root. For example, in the picture below, 77 is in the subtree of 33 because the simple path 7→5→3→17→5→3→1 passes through 33. Note that a vertex is included in its subtree, and the subtree of the root is the entire tree.
    The picture shows the tree for n=7n=7, a=[1,1,2,3,3,5]a=[1,1,2,3,3,5], and s=WBBWWBWs=WBBWWBW. The subtree at the vertex 33 is balanced. */

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

void dfs(int start, string &colors, vector<vector<int>> &adj, vector<pair<int, int>> &black_white)
{
    for (int v: adj[start])
    {
        dfs(v, colors, adj, black_white);
        black_white[start].first += black_white[v].first;
        black_white[start].second += black_white[v].second;

    }
    if (colors[start] == 'B')
        black_white[start].first++;
    else
        black_white[start].second++;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; // number of test cases
    while(t--)
    {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 2; i < n + 1; i++)
        {
            int p; cin >> p;
            adj[p - 1].push_back(i);
        }
        string colors;
        cin >> colors;
        // vector<bool> visited(n, false);
        vector<pair<int, int>> black_white(n); // vector of pairs that holds the number of white and black nodes in the subtree of each node
        dfs(0, colors, adj, black_white);
        int num_blance = 0;
        for (auto [x,y]: black_white)
            if (x == y)
                num_blance++;
        cout << num_blance << "\n";
    }
}