/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

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

const ll mm = 1e9;
ll barns, roads;
vector<ll> adjl[mm];
vector<pair<ll,ll> > connections(mm);
bool visited[mm];

void dfs(ll x)
{
    visited[x]=true;
    for(ll u: adjl[x])
    {
        dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("cpp");
    /* freopen(("filename"), "r", stdin); */
    cin >> barns >> roads;
    for(int i = 0; i < roads; i++)
    {
        ll a,b;
        cin >> a >> b;
        connections[i].first=a;
        connections[i].second=b;
        /* adjl[a].pb(b);
        adjl[b].pb(a); */
    }
    //rebuild adjacency list
    for(int i = 0; i < roads; i++)
    {
        ll a = connections[i].first;
        ll b = connections[i].second;
        adjl[a].pb(b);
        adjl[b].pb(a);
    }
    /* printf("%lli",x); */
}