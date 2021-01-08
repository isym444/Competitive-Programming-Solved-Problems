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

ll haybales, cows, power, l, m, r,sum;
const ll mm = 1e9;
vector<ll> hpos;
vector<pair<ll,ll> > difs;
vector<ll> spliter;
vector<ll> regions;

bool checker(ll m)
{
    ll cowtest=0;
    int i = 0;
    int j = 0;
    int temp=0;
    while(i<hpos.size())
    {
        while(hpos[j]<=hpos[i]+2*m&&j<hpos.size())
        {
            j++;
        }
        cowtest++;
        i=j;
    }
    return(cowtest<=cows);
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("angry");
    /* freopen(("filename"), "r", stdin); */
    cin >> haybales >> cows;
    for(int i = 0; i < haybales; i++)
    {
        ll temp;
        cin >> temp;
        hpos.pb(temp);
    }

    //info for checker
    sort(hpos.begin(),hpos.end());
    //binary search
    power = mm; l=0; r=mm;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(checker(m))
        {
            power = m;
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    cout << power;
    /* printf("%lli",x); */
}