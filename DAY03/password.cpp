# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
using namespace std;
const int MOD = 1e9 + 7;

long long fact(int n)
{
    long long res = 1;
    for (int i = 1; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}

int choose(int k, int n)
{
    return (fact(n) / (fact(k) * fact(n - k)));
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    int m;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; // number of elements that were not in the password ex : 8
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
        }
        m = 10 - n; // 10 - 8
        cout << choose(2, m) * (fact(4) / (2 * fact(2))) << endl;
    }
    return 0;
}
