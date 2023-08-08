# include <iostream>
# include <stack>
using namespace std;

int main(void)
{   
    std::ios::sync_with_stdio(false); 
    stack<int> my_stack;
    int num_queries;
    int i;
    int x;
    int y;

    cin >> num_queries;
    for (i = 0; i < num_queries; i++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            my_stack.push(y);
        }
        else if (x == 2 && !my_stack.empty())
            my_stack.pop();
        else if (x == 3 && !my_stack.empty())
            std::printf("%d\n", my_stack.top());
        else if (x == 3 && my_stack.empty())
            std::printf("Empty!\n");
    }
}