#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if ((int)(name).size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int t[7];
    int minval = 1000000001;
    int a,b,c,sumvals=0;
    for(int i = 0; i<7; i++)
    {
        cin >> t[i];
        sumvals += t[i];
    }
    sort(t,t+7);
    a = t[0];
    b = t[1];
    int sumall=t[6];
    c = sumall-a-b;
    cout << a << " " << b << " " << c;
}
