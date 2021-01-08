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
void solve(string n, int ln)
{
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '4' || n[i] == '7')
        {
            ln++;
        }
    }
    string sln;
    sln = to_string(ln);
    for (int i = 0; i < sln.length(); i++)
    {
        if (sln[i] != '4' && sln[i] != '7')
        {
            cout << "NO";
            return;
        }
        cout << "YES";
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    string n;
    int ln = 0;
    cin >> n;
    solve(n, ln);
}