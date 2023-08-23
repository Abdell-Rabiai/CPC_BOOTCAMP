/*    In some social network, there are nn users communicating with each other in mm groups of friends. Let's analyze the process of distributing some news between users.

    Initially, some user xx receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.

    For each user xx you have to determine what is the number of users that will know the news if initially only user xx starts distributing it.*/
/*input :
    The first line contains two integers nn and mm (1≤n,m≤5⋅1051≤n,m≤5⋅105) — the number of users and the number of groups of friends, respectively.

    Then mm lines follow, each describing a group of friends. The ii-th line begins with integer kiki​ (0≤ki≤n0≤ki​≤n) — the number of users in the ii-th group. Then kiki​ distinct integers follow, denoting the users belonging to the ii-th group.

    It is guaranteed that ∑i=1mki≤5⋅105i=1∑m​ki​≤5⋅105.*/
/*output:
Print nn integers. The ii-th integer should be equal to the number of users that will know the news if user ii starts distributing it.*/

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

void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &grp)
{
    visited[start] = true;
    grp.push_back(start);
    for (auto v : adj[start])
    {
        if (!visited[v])
            dfs(v, adj, visited, grp);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; // number of users
    int m; cin >> m; // nimber of groups
    vector<vector<int>> adj(n);
    while (m--)
    {
        int k; cin >> k; // 3
        vector<int> group(k);
        for (int i = 0; i < k; i++)
        {
            int user; cin >> user; // 2 5 4
            group[i] = user - 1;
        }
        // connect between users in the same group
        for (int i = 1; i < k; i++)
        {
            adj[group[i - 1]].push_back(group[i]);
            adj[group[i]].push_back(group[i - 1]);
        }
    }
    vector<bool> visited(n, false);
    vector<int> count(n, 0);
    vector<int> grp;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, grp);
            for (int j = 0; j < grp.size(); j++)
                count[grp[j]] = grp.size();
            grp.clear();
        }
    }
    for (int i = 0; i < n; i++)
        cout << count[i] << " ";
}