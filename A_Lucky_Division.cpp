/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
/* using std::vector; */

#define fo(i, n) for (i = 0; i < n; i++)

#define ll long long
#define sz(x) (int)(x).size()
#define mp make_pair
typedef pair<ll, ll> pl;

#define pb push_back

//=======================

void setIO(string name = "")
{ // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
void solve(int a)
{
    for (int i = 1; i <= a; i++)
    {
        int check = 0;
        int numdig = 0;
        numdig = log10(i) + 1;
        int itemp = i;
        for (int j = 1; j <= numdig; j++)
        {
            if (itemp % 10 != 4 && itemp % 10 != 7)
            {
                check = 1;
            }
            itemp = itemp / 10;
        }
        if (check == 0)
        {
            if (a % i == 0)
            {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int a;
    cin >> a;
    solve(a);
}