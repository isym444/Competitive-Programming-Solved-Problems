/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
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

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("homework");
    /* freopen(("int"), "r", stdin); */
    ll n,k,sum=0,lowest=10001; cin>>n;
    double cur_av=0;
    /* ll ans[2]={-1,-1}; */
    vector<pair<double,ll> > ans(1); //max average + index
    ans[0].first=-1;
    ans[0].second=-1;
    vector<ll> indexes;
    vector<ll> scores(n);
    for(int i=0;i<n;i++)
    {
        cin >> scores[i];
    }
    k=n-3; // k can be 1 to n-2 so in index: 0 to n-3
    lowest=scores[n-1];
    sum=scores[n-1];
    for(int i = k; i>=0; i--)
    {
        //at each round keep track of 1) lowest value, 2) sum of values 3) cur_av=(sum of values - lowest value)/(n-k-2) 4) ans=max(ans, cur_av) & i+1
        lowest=min(lowest,scores[i+1]);
        sum+=scores[i+1];
        cur_av=(sum-lowest)/((n-i-2)*1.0);
        if(cur_av==ans[0].first)
        {
            ans[0].second=i+1;
            indexes.push_back(ans[0].second);
        }
        if(cur_av>ans[0].first)
        {
            ans[0].first=cur_av;
            ans[0].second=i+1;
            indexes.clear();
            indexes.push_back(ans[0].second);
        }
    }
    /* cout << ans[1]; */
    sort(indexes.begin(),indexes.end());
    for(int i = 0; i<indexes.size();i++)
    {
        /* printf("%lli",indexes[i]); */
        cout << indexes[i];
        if(i<indexes.size()-1)
        {
            cout << endl;
            /* printf("\n"); */
        }
    }
    /* printf("%lli",ans[0].second); */
}