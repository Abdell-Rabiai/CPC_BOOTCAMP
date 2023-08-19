#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Calculate factorial modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

// Calculate modular inverse using Fermat's Little Theorem
long long mod_inverse(long long base) {
    long long result = 1;
    long long exp = MOD - 2;  // For MOD prime, a^(p-2) is the inverse of a modulo p
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Calculate binomial coefficient modulo MOD using Lucas Theorem
long long binomial_coefficient(int n, int k) {
    if (k == 0) {
        return 1;
    }
    int ni, ki;
    long long result = 1;
    while (n > 0) {
        ni = n % MOD;
        ki = k % MOD;
        result = (result * factorial(ni) % MOD * mod_inverse(factorial(ki) * factorial(ni - ki) % MOD)) % MOD;
        n /= MOD;
        k /= MOD;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << binomial_coefficient(a, b) << endl;
    }

    return 0;
}

