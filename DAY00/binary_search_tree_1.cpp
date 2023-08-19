# include <iostream>
# include <algorithm>
# include <stack>
# include <set>
# include <string>
# include <array>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    string str;
    int number;
    set<int> st;
    while (cin >> str >> number)
    {
        if (str == "insert")
            st.insert(number);
        else if (str == "exists")
        {
            if (st.find(number) != st.end())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (str == "delete")
            st.erase(number);
    }
    return (0);
}
