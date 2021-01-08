/* #include <bits/stdc++.h> */
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    /* sum of all values
    order in descending order
    progressive addition until sum > totalsum-sum */
    int a, i, value;
    int totalsum = 0;
    int sum = 0;
    int counter = 0;
    vector<int> b;
    cin >> a;
    for (i = 0; i < a; i++)
    {
        cin >> value;
        b.pb(value);
    }
    fo(i, a)
    {
        totalsum += b[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    fo(i, a)
    {
        sum += b[i];
        counter++;
        if (sum > totalsum - sum)
        {
            cout << counter;
            break;
        }
    }
}