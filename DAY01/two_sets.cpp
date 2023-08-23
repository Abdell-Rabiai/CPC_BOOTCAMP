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
# define int long long

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
    cin >> n; // DIVIDE IT INTO TWO SETS OF EQUAL SUM
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 0)
    {
        cout << "YES ";
        vector<int> set1, set2;
        int som = sum / 2;
        while (n)
        {
            if (som - n >= 0)
            {
                set1.push_back(n);
                som -= n;
            }
            else
                set2.push_back(n);
            n--;
        }
        cout << set2.size() << " ";
        for (auto i : set2)
            cout << i << " ";
        cout <<  set1.size() << " ";
        for (auto i : set1)
            cout << i << " ";
    }
    else
        cout << "NO\n";
}
