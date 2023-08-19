#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int tab[a];
    for (int i = 0; i < a; i++)
        cin >> tab[i];
    for (int i = 0; i < a; i++)
    {
        if (tab[i] >= 0 && tab[i] <= 100)
            tab[i] = tab[i] + 2;
        cout << tab[i] << " ";
    }
    cout << endl;
    return 0;
}