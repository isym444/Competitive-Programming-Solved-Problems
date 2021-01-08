/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

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
    setIO("div7");
    ll i,j,n,sol=0; cin >> n;
    vector<ll> cows(n);
    fo(i,n)
    {
        cin >> cows[i];
    }
    //prefix sum
    vector<ll> ps(n);
    map<ll,ll> rem_ind; //remainder when div by 7 & index
    set<ll> rem_seen; // allows to check if remainder has been seen before
    fo(i,n)
    {
        if(i==0) ps[i]=cows[i];
        else
        {
            ps[i]=ps[i-1]+cows[i];
        }
        if(rem_seen.count(ps[i]%7)==0)
        {
            rem_ind[ps[i]%7]=i;
            rem_seen.insert(ps[i]%7);
        }
        else
        {
            ll temp = i - rem_ind[ps[i]%7];
            sol=max(sol,temp);
        }
    }
    cout << sol;
    //finding answer
    //for each prefix sum, find remainder when divided by 7 & store together with index
    //at each round if remainder not seen before (use set), add to map[key]=value
    //at each round if remainder seen before (use set), compare curr i to map[key] value, compare with ans to check if max
}