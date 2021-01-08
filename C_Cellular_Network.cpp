/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>

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
    setIO("cpp");
    int cities, towers, dist, ans=0; cin >> cities >> towers;
    set<int> tower;
    vector<int> city;
    for(int i = 0; i < cities; i++)
    {
        int temp; cin >> temp;
        city.push_back(temp);
    }
    for(int i = 0; i < towers; i++)
    {
        int temp; cin >> temp;
        tower.insert(temp);
    }
    for(int i = 0; i < cities; i++)
    {
        auto it = tower.lower_bound(city[i]);
        /* auto a = it;
        auto b = tower.end();
        auto c = tower.begin(); */
        if(it!=tower.end())
        {
            dist = (abs(*it - city[i]));
        }
        if(it!=tower.begin())
        {
            dist = (abs(*it - city[i]));
            auto it = prev(tower.lower_bound(city[i]));
            dist = min(dist,abs(city[i]-*it));
        }
        /* if(it==tower.begin())
        {
            dist = *it - city[i];
        }
        else if(*it==towers)
        {
            dist = city[i]-*tower.end();
        }
        else
        {
            dist = *it-city[i];
            dist=max(dist, city[i]-*it);
        } */
        ans = max(ans,dist);
    }
    cout << ans;
}