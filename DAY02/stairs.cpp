/**/
# include <iostream>
# include <algorithm>
# include <stack>
# include <queue>
# include <set>
# include <string>
# include <array>
# include <vector>
# include <cmath>
# include <map>
# include <numeric>
# include <utility>
# include <iomanip>
# include <bitset>
# include <unordered_map>
# include <unordered_set>
# include <complex>
# include <climits>

using namespace std;
# define int long long
long long MOD = 1e9 + 7;

int32_t main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int ans = sqrt(1 +(8*n)) - 1;
    cout << ans / 2 << "\n";
    return 0;
}