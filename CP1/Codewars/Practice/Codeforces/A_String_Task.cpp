/* #include <bits/stdc++.h> */
#include <cstdio>
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
    string a;
    cin >> a;
    string b = "aeiouy";
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = tolower(a[i]);
        int counter = 0;
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            cout << "." << a[i];
        }
    }
}