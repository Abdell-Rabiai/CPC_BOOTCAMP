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

int fibonacci(int n)
{
    vector<int> v(n + 1, 1);

    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2];
    return v[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;
}