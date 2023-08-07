# include <iostream>
# include <stack>
using namespace std;

void push_to_stack(string str, stack<int> &my_stack)
{
    int number;
    number = stoi(str.substr(2, str.length()));
    my_stack.push(number);
}

void print_stack(stack<int> my_stack)
{
    while (!my_stack.empty())
    {
        cout << my_stack.top() << endl;
        my_stack.pop();
    }
}

void pop_or_print(string str, stack<int> &my_stack)
{
    int number;

    number = stoi(str);
    if (number == 2 && !my_stack.empty())
        my_stack.pop();
    if (number == 3 && !my_stack.empty())
        cout << my_stack.top() << endl;
    else if (number == 3 && my_stack.empty())
        cout << "Empty!" << endl;
}

int main(void)
{
    stack<int> my_stack;
    int num_queries;
    int i;

    cin >> num_queries;
    string strs[num_queries];
    for (i = 0; i < num_queries; i++)
    {
        getline(cin >> ws, strs[i]);
        if (strs[i].length() > 1)
            push_to_stack(strs[i], my_stack);
        if (strs[i].length() == 1)
            pop_or_print(strs[i], my_stack);
    }
}