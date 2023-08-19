#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[N] << endl;

    return 0;
}
