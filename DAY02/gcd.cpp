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
long long MOD = 1e9 + 7;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int ans = v[0];
    for (int i = 1; i < n; i++)
        ans = gcd(ans, v[i]);
    cout << ans << "\n";
    return 0;
}