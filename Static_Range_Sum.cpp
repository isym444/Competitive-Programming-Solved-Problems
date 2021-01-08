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
#define sz(x) (ll)(x).size()
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
    ll i,n,q; cin >> n >> q;
    /* ll ar[n]; */
    vector<ll> ar(n);
    //inputs
    fo(i,n)
    {
        cin >> ar[i];
    }
    vector<pair<ll,ll> > quer(q);
    fo(i,q)
    {
        cin >> quer[i].first >> quer[i].second;
    }
    //prefix sum
    ll ps[n];
    ps[0]=ar[0];
    for(ll i = 1; i<n; i++)
    {
        ps[i]=ar[i]+ps[i-1];
    }
    //calc output
    ll ans;
    fo(i,q)
    {
        ll a = quer[i].first;
        ll b = quer[i].second-1;
        /* s(2->4)=s(0->4)-s(0->1) */
        /* s(a->b)=s(0->b)-s(0->a-1) */
        if(a==0)
        {
            cout << ps[b] << endl;
        }
        else
        {
            cout << ps[b]-ps[a-1] << endl;
        }
    }
}