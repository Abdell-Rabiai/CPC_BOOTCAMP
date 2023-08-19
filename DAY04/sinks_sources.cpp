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
int check_if_sink(vector<vector<int>> graph, int n, int i)
{
    for (int j = 0; j < n; j++)
        if (graph[i][j] == 1)
            return 0;
    return 1;
}

int check_if_source(vector<vector<int>> graph, int n, int i)
{
    for (int j = 0; j < n; j++)
        if (graph[j][i] == 1)
            return 0;
    return 1;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; // number of cities in the graph
    cin >> n;
    // read the graoh as an adjacency matrix
    int nd;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> nd;
            graph[i][j] = nd;
        }
    int sources = 0, sinks = 0;
    vector<int> sinks_list, sources_list;
    for (int i = 0; i < n; i++)
    {
        if (check_if_sink(graph, n, i))
        {
            sinks++;
            sinks_list.push_back(i+1);
        }
        if (check_if_source(graph, n, i))
        {
            sources++;
            sources_list.push_back(i+1);
        }
    }
    cout << sources << " ";
    for (auto s : sources_list)
        cout << s << " ";
    cout << "\n";
    cout << sinks << " ";
    for (auto s : sinks_list)
        cout << s << " ";
    cout << "\n";
}