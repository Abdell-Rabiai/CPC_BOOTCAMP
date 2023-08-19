# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
using namespace std;
long long MOD = 1e9 + 7;
long long factt[1000001];
long long inv[1000001];

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

void preprocessing()
{
    factt[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        factt[i] = (i * factt[i - 1]) % MOD;
    // inv[0] = 1;
    // for (int i = 1; i <= 1000000; i++)
    //     inv[i] = inverse(factt[i]);
}
// choose func calculates the binomial coefficient of a from b
long long choose(int a, int b)
{
    long long res;
    long long num = factt[a];
    long long den = (factt[b] * factt[a - b] % MOD);
    res = (num * inverse(den)) % MOD;
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    preprocessing();   // function to precompute the factorials and inverse factorials
    int n;
    int a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        cout << choose(a, b) << endl;
    }
    return 0;
}
