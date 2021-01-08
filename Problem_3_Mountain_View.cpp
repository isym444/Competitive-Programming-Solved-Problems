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

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first)
    {
        return a.second > b.second; //bigger R (i.e. b) first
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("mountains");
/* change mountain definition from peak coordinate to L base + R base coordinates */
    int n; cin >> n;
    vector<pair<int,int>> peaks;
    vector<pair<int,int>> base;
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        auto c=make_pair(a,b);
        peaks.push_back(c);
        int d,e;
        d=peaks[i].first-peaks[i].second;
        e=peaks[i].first+peaks[i].second;
        auto f = make_pair(d,e);
        base.push_back(f);
        /* base[i].first = peaks[i].first-peaks[i].second; // x coordinate of L base
        base[i].second = peaks[i].first+peaks[i].second; // x coordinate of R base */
    }
/* order mountains in ascending order of L base coordinate + descending R coordinate if L base point the same */
    sort(base.begin(),base.end(),cmp);

/* go through array of mountains and count++ if R base coordinate is greater than previous item in array */
    int count=1;
    int prevmax=base[0].second;
    for(int i = 1; i<n; i++)
    {
        if(base[i].second>prevmax)
        {
            count++;
            prevmax=base[i].second;
        }
    }
    cout << count;
}


/*  x coordinates: L base is x-y, R base is x+y*/