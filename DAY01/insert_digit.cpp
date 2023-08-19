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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int len; cin  >> len;
        int digit; cin >> digit;
        string s; cin >> s;
        for (int i = 0; i < len; i++)
        {
            if (s[i] - '0' < digit)
            {
                s.insert(i, to_string(digit));
                break;
            }
        }
        if (s.length() == len)
            s += to_string(digit);
        cout << s << "\n";
    }
}
