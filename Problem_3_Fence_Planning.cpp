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

const ll maxx = 1e5+2;
ll numcows,edges;
vector<ll> cowpos[maxx]; //position of all cows from 1 to numcows
vector<ll> adj[maxx]; //cows (1 to numcows) in connected component
vector<bool> visited(maxx);
vector<ll> perimeters;
pair<ll,ll> cc, mll, cll, mur, cur; //current coordinate, min lower left, current lower left, max upper right, current upper right

void dfs(ll node)
{
    visited[node]=true;
    cc=mp(cowpos[node][0],cowpos[node][1]);
    mll=mp(min(cc.first,mll.first/* x */),min(cc.second,mll.second/* y */));
    mur=mp(max(cc.first,mur.first/* x */),max(cc.second,mur.second/* y */));
    for(auto p: adj[node])
    {
        if(!visited[p]) dfs(p);
    }
}

ll calcper()
{
    return(2*(mur.first-mll.first)+2*(mur.second-mll.second));
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("fenceplan");
    cin >> numcows >> edges;
    for(int i = 1; i<=numcows; i++)
    {
        ll a,b;
        cin >> a >> b;
        cowpos[i].pb(a);cowpos[i].pb(b);
    }
    for(int i = 1; i<=edges; i++)
    {
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1; i<=numcows; i++)
    {
        for(ll u: adj[i])
        {
            cc=mp(cowpos[u][0],cowpos[u][1]);
            mll=mp(cowpos[u][0],cowpos[u][1]); mur=mp(0,0);
            if(!visited[u])
            {
                dfs(u);
                perimeters.pb(calcper());
            }
        }
    }
    ll ans=-1;
    for(ll t: perimeters)
    {
        if(ans==-1&&t!=0) ans=t;
        else if(t<ans&&t!=0)
        {
            ans=t;
        }
    }
    cout << ans;
    /* freopen(("filename"), "r", stdin); */
    //take input
    //build adjacency list based on mooing cows
    //go through all cows to calculate each net and each net enclosing rectangle perimeter
    //output perimeter of smallest rectangle != 0
    /* printf("%lli",x); */
}