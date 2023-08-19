/* Consider a money system consisting of nn coins. Each coin has a positive integer value. Your task is to produce a sum of money xx using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7}{1,5,7} and the desired sum is 1111, an optimal solution is 5+5+15+5+1 which requires 33 coins.

Input

The first input line has two integers nn and xx: the number of coins and the desired sum of money.

The second line has nn distinct integers c1,c2,…,cnc1​,c2​,…,cn​: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1−1.*/
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
int minimum_coins(vector<int> coins, int n, int x)
{
    vector<int> dp(x + 1, mx);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int j = 0; j < n; j++)
            if (i - coins[j] >= 0 && dp[i - coins[j]] != mx)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
    return (dp[x] == mx ? -1 : dp[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int j = 0; j < n; j++)
        cin >> coins[j];

    printf("%d\n", minimum_coins(coins, n, x));
}
