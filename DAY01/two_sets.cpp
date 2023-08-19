/* Your task is to divide the numbers 1,2,…,n1,2,…,n into two sets of equal sum.

Input

The only input line contains an integer nn.

Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.*/

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
int mx = 2147483647;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int j = 0; j < n; j++)
        cin >> coins[j];
    
}
