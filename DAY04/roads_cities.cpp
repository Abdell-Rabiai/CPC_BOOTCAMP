
/*n the galaxy of "Milky Way" on the planet "Neptune" there are n cities, some of them are connected by roads. Emperor "Maximus" of Galaxy "Milky Way" has decided to make an inventory of roads on the planet "Neptune". But as it turned out he was not good at math, so he asks you to count the number of roads.
Input data

The first line contains the number n (0 ≤ n ≤ 100). Each of the next n lines contains n numbers, each of which is one or zero. Moreover, if the position (i, j) of square matrix is one, then the i-th and j-th city are connected by road, and if zero, it is not connected.
*/
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
    int number_of_edges = 0;
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
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (graph[i][j] == 1)
                number_of_edges++;
    cout << number_of_edges << "\n";
}