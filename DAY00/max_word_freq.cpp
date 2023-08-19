# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
# include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    map<string, int> words;
    int n;
    int max_freq = 0;
    string max_key;

    cin >> n;
    int key = 1;
    for (int i = 0; i < n; i++)
    {
        string curr_str;
        cin >> curr_str;
        words[curr_str]++;
    }
    for (auto &i : words)
    {
        if (i.second >= max_freq && i.first > max_key)
        {
            max_freq = i.second;
            max_key = i.first;
        }
    }
    cout << max_key << " "  << max_freq << endl;
    return (0);
}
