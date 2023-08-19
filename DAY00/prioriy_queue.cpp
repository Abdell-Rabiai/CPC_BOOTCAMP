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

int main()
{
    int n, q; cin >> n >> q;// number of operations
    vector<priority_queue<int>> vq(n);
    while (q--)
    {
        int a; cin >> a;
        int b; cin >>b;
        if (a == 0)
        {
            int c; cin >>c;
            vq[b].push(c);
        }
        else if (a == 1 && !vq[b].empty())
            cout << vq[b].top() << "\n";
        else if (a == 2 && !vq[b].empty())
            vq[b].pop();
    }
    return 0;
}
