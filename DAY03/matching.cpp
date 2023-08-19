/*    An integer template is a string consisting of digits and/or question marks.

    A positive (strictly greater than 00) integer matches the integer template if it is possible to replace every question mark in the template with a digit in such a way that we get the decimal representation of that integer without any leading zeroes.

    For example:

        4242 matches 4?;
        13371337 matches ????;
        13371337 matches 1?3?;
        13371337 matches 1337;
        33 does not match ??;
        88 does not match ???8;
        13371337 does not match 1?7.

    You are given an integer template consisting of at most 55 characters. Calculate the number of positive (strictly greater than 00) integers that match it.
Input

    The first line contains one integer tt (1≤t≤2⋅1041≤t≤2⋅104) — the number of test cases.

    Each test case consists of one line containing the string ss (1≤∣s∣≤51≤∣s∣≤5) consisting of digits and/or question marks — the integer template for the corresponding test case.
Output

    For each test case, print one integer — the number of positive (strictly greater than 00) integers that match the template.*/
# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
# include <vector>
# include <cmath>
# include <map>
using namespace std;
long long MOD = 1e9 + 7;

int count_matching_integers(string s)
{
    int sum = 1;
    if (s[0] == '0')
        sum = 0;
    else
    {
        if (s[0] == '?')
            sum *= 9;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '?')
                sum *= 10;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << count_matching_integers(s) << endl;
    }
    return 0;
}
