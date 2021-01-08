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
    setIO("herding");
    int a, b, c;
    int dif_first_2, dif_last_2;
    int ans1, ans2;
    cin >> a >> b >> c;
    dif_first_2 = b - a;
    dif_last_2 = c - b;
    ans1 = min(dif_first_2, dif_last_2) - 1;
    ans2 = max(dif_first_2, dif_last_2) - 1;
    if(ans1==0)
    {
        ans1=ans2-1;
        cout << ans1 << "\n";
        cout << ans2;
    }
    else if(ans2==0)
    {
        ans2=ans1-1;
        cout << ans1 << "\n";
        cout << ans2;
    }
    else
    {
        cout << ans1 << "\n";
        cout << ans2;
    }
}

/* 4 7 9
3 2

3 7 9 -> 4, 2 -> 3, 1 -> min dif btwn # - 1, max dif btwn # - 1
3 6 7
3 5 6
3 4 5 */



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

