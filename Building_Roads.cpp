/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <set>

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

const long long maxx=1e5+10; //CHANGE TO 1e5+10
long long cities, roads;
vector<long long> adjlist[maxx];
bool visited[maxx];

void dfs(long long node)
{
    visited[node]=true;
    for(long long all: adjlist[node])
    {
        if(!visited[all])
        {
            dfs(all);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    /* freopen(("filename"), "r", stdin); */
    cin >> cities >> roads;
    //create adjacency list
    for(int i = 0; i<roads; i++)
    {
        long long a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    //create dfs function
    //find # of connected components + keep track of a node in each one: cout #-1
    long long count = 0;
    vector<long long> tracker;
    for(int i = 1; i<=cities; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            tracker.push_back(i);
            count++;
        }
    }
    cout << count-1 << endl;
    //cout edges of single node kept track of in connected components
    for(int i = 1; i<tracker.size(); i++)
    {
        cout << tracker[i-1] << " " << tracker[i] << endl;
    }
    /* printf("%lli",x); */
}