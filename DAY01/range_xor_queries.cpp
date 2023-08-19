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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// read the first line, n number of values, q number of queries
	int n, q;
	cin >> n >> q;
	// read the second line, n values, the array values
	vector<int> arr(n);
	for (size_t i = 0; i < n; i++)
		cin >> arr[i];
	// create an array fo prefix sums of n elements in the array
	vector<long long> pref(n + 1, 0);
	for (size_t i = 1; i < n + 1; i++)
		pref[i] = pref[i - 1] ^ arr[i - 1];

	for (size_t i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << ( pref[r] ^ pref[l - 1] ) << "\n";
	}
	
}
