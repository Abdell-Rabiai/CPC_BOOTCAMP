/*
As you know, Andry Sergeevich is an ardent collector of butterflies. He has a huge collection, the exhibits of which are collected from around the world. We assume that there are 2 * 10^9 species of butterflies in the world.

In order not to get confused, Andrei Sergeevich assigned a unique number to each species. Butterfly numbering always starts from one. Now he wants to know if there is a butterfly with a number k in his collection, or he will have to get it, spending a lot of effort and money.
Input data

First line contains the number of species of butterflies n (1 ≤ n ≤ 10^5) in the collection of Andrei Sergeevich. Next line contains n numbers in ascending order - the numbers of butterfly species in the collection. All kinds of butterflies in the collection have different numbers.

Third line contains the number of species of butterflies m (1 ≤ m ≤ 10^5), about which Andrei Sergeevich wants to know if he has them in the collection or not. The last line contains m numbers - numbers of species of butterflies, the presence of which must be checked.
Output data

Print m lines. For each query print "YES", if the butterfly with the given number exists in his collection and "NO" otherwise.
*/
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
    int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		if (binary_search(vec.begin(), vec.end(), x))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
