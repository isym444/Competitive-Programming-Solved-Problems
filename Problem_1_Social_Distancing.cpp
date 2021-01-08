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
ll n,intervals,l,m,r;
vector<pair<ll,ll> > grass;

bool checker(ll cur)
{
    ll count=0;
    ll prev=grass[0].first;
    for(auto i: grass)
    {
        while(max(prev,i.first)<=i.second)
        {
            count++;
            if(max(prev,i.first)==i.first) prev=i.first;
            prev+=cur;
            if(count>=n) return(true);
        }
    }
    return(false);
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("socdist");
    /* freopen(("filename"), "r", stdin); */
    cin >> n >> intervals;
    grass.resize(intervals);
    for(int i = 0; i < n; i++)
    {
        cin >> grass[i].first >> grass[i].second;
    }
    sort(grass.begin(),grass.end());
    l=0;r=1e18;
    m=l+(r-l)/2;
    ll ans;
    while(l<=r)
    {
        if(checker(m))
        {
            l=m+1;
            ans = m;
        }
        else
        {
            r=m-1;
        }
        m=l+(r-l)/2;
    }
    cout << ans;
    /* printf("%lli",x); */
}