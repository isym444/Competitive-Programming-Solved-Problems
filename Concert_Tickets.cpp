/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <queue>
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

bool cmp(int a, int b)
{
    return a>b;
}
#define lli long long int

/* int main()
{
    ios_base::sync_with_stdio(0);
    setIO("cpp");
    lli n, m, curr, ticket;
    cin >> n >> m;
    multiset<lli, greater<int>> tickets;

    while (n--)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }

    while (m--)
    {
        cin >> curr;
        auto it = tickets.lower_bound(curr);
        if (it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return 0;
} */



int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int tickets, customers, temp; cin >> tickets >> customers;
    multiset<int, greater<int>> t;
    vector<int> c;
    for(int i = 0; i < tickets; i++)
    {
        cin >> temp;
        t.insert(temp);
    }
    for(int i = 0; i < customers; i++)
    {
        cin >> temp;
        c.push_back(temp);
    }
    for(int i = 0; i < customers; i++)
    {
        auto it = t.lower_bound(c[i]);
        if(it==t.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            t.erase(it);
        }
    }
}