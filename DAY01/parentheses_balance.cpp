# include <iostream>
# include <algorithm>
# include <stack>
# include <string>
# include <array>
using namespace std;

char matching(char c)
{
    if (c == '(')
        return ')';
    else if (c == '[')
        return ']';
    else    
        return 0;
}

bool is_valid_string(string s)
{
    int i = 0;
    stack<char> stk;

    if (s.length() % 2 != 0)
        return false;
    if (s.length() == 0)
        return true;
    while(s[i])
    {
        if (s[i] == '(' || s[i] == '[')
            stk.push(matching(s[i]));
        else if (!stk.empty() && s[i] == stk.top())
            stk.pop();
        else
            return false;
        i++;
    }
    if (stk.empty())
        return true;
    else
        return false;
}

int main()
{
    int num_strings;
    string str;
    int i;

    cin >> num_strings;
    for (i = 0; i < num_strings; i++)
    {
        getline(cin >> ws, str);
        if (is_valid_string(str))
            cout<< "Yes"<< endl;
        else
            cout<< "No"<< endl;
    }
}