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
long long inverse(long long n)
{
    long long res = 1;
    long long p = MOD - 2;
    while (p)
    {
        if (p & 1)
            res = (res * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    string s;
    long long result;
    cin >> s;
    int len = s.size();

    int freq[26] = {0};
    for (char c : s)
        freq[c - 'a']++;
    
    long long x = 1;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 1)
             x = x * fact(freq[i]) % MOD;

    result = fact(len) * inverse(x) % MOD;
    cout << result << endl;
    return 0;
}
