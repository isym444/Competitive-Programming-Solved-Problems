/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* using std::vector; */

#define fo(i, n) for (i = 0; i < n; i++)

#define ll long long
#define sz(x) (int)(x).size()
#define mp make_pair
typedef pair<ll, ll> pl;

#define pb push_back

//=======================

void setIO(string name)
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

int a[100], b[100], g[100];

int solve(int pebpos, int t)
{
    int counter = 0;
    for (int i = 0; i < t; i++)
    {
        if (pebpos == a[i])
        {
            pebpos = b[i];
        }
        else if (pebpos == b[i])
        {
            pebpos = a[i];
        }
        if (g[i] == pebpos)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("shell");
    int t, t2, maxguess, h;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> b[i] >> g[i];
    }
    for (int pebpos = 1; pebpos <= 3; pebpos++)
    {
        h = solve(pebpos, t);
        if (maxguess < h)
        {
            maxguess = h;
        }
    }
    cout << maxguess;
}