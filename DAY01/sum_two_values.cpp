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
    int size, sum;
    cin >> size >> sum;
    int curr_num;
    map<int, int> map; // map<value, index>
    for (int i = 1; i <= size; i++)
    {
        cin >> curr_num;
        if (map.find(sum - curr_num) != map.end())
        {
            cout << map[sum - curr_num] << " " << i << endl;
            return 0;
        }
        map[curr_num] = i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
