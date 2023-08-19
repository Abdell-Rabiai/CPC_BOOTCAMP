# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <vector>
# include <array>
using namespace std;
long long MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    //dp[i] represents the number of ways to construct a sum of i using dice throws.
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
    }
    cout << dp[n] << endl;
    return 0;
}
