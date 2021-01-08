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

const ll maxx=201;//change to 201!!!!!!!!!!!!!
ll n;
vector<ll> cows[maxx];
vector<ll> adj[maxx];
vector<bool> visited(maxx);
ll counter;

ll dfs(ll node)
{
    visited[node]=true;
    counter++;
    for(ll u: adj[node])
    {
        if(!visited[u]) dfs(u);
    }
    return(counter);
}

bool checker(vector<ll> x,vector<ll> y)
{
    //return whether x can reach y
    if(x[2]*x[2]>=abs(x[0]-y[0])*abs(x[0]-y[0])+abs(x[1]-y[1])*abs(x[1]-y[1]))
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("moocast");
    /* freopen(("filename"), "r", stdin); */
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        cows[i].pb(a);
        cows[i].pb(b);
        cows[i].pb(c);
        cows[i].pb(i+1); //index of cow starting at 1, ending at n
    }
    //for each cow check if can reach every other cow and if so, add edge to adjacency matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i!=j)
            {
                if(checker(cows[i],cows[j]))
                {
                    //add edge to adjacency list
                    adj[cows[i][3]].pb(cows[j][3]);
                }
            }
        }
    }
    //run through adjacency matrix with dfs starting from each dif vertex keeping a max visitable other vertices (incl original cow)
    ll ans=0;
    for(ll i = 1; i<=n; i++)
    {
        counter = 0;
        fill(visited.begin(),visited.end(),0);
        ll temp = dfs(i);
        ans=max(ans,temp);
    }
    /* printf("%lli",x); */
    cout << ans;
}