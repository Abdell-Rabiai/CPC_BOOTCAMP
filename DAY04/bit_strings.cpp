# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
using namespace std;
const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    
    long long result = 1;
    // 2^n
    for (int i = 0; i < n; i++)
        result = (result * 2) % MOD;
    
    cout << result % MOD << endl;
    return 0;
}
