# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
# include <map>
# include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int size;
	long long target_sum;
	long long res = 0;
	cin >> size >> target_sum;
	vector<int> arr(size);
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	map<long long, int> pref; // map of prefixsums as key and thier count as value;
	long long cum_sum = 0;
	pref[0] = 1;
	long long diff = 0;
	for (int i = 0; i < size; i++)
	{
		cum_sum += arr[i];
		diff = cum_sum - target_sum;
		if (pref.find(diff) != pref.end())
			res += pref[diff];
		pref[cum_sum] = pref[cum_sum] + 1;
	}
	
	cout << res <<"\n";
	return 0;
}
