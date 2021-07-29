#include<iostream>
using namespace std;
template <size_t N>
void Input(char(&var)[N])
{
    if (!(cin.get(var, N, '\n')))
    {
        cin.clear();
        cin.sync();
    }
    cin.ignore(cin.rdbuf()->in_avail());
}