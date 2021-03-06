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

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int n, sum, a, b, c, sa, sb, sc;
    sa = 0;
    sb = 0;
    sc = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        sa += a;
        sb += b;
        sc += c;
    }
    if (sa || sb || sc != 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}