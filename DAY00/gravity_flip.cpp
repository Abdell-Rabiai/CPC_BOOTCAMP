# include <iostream>
# include <algorithm>
# include <array> 
using namespace std;

/*
4
3 2 1 2
*/

void print(int *tab, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}
int main(void)
{
    int n; // number of columns
    int *tab; // array of columns
    int i; // iterator

    /*first step : store the data*/
    cin >> n;
    tab = new int[n];
    for (i = 0; i < n; i++)
        cin >> tab[i];
    //second step : sort the array
    sort(tab, tab + n);
    // third : print the array
    print(tab, n);
    return (0);
}