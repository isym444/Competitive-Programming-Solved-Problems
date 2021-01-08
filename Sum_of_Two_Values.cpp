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

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    /* freopen(("filename"), "r", stdin); */
    int n,target; cin >> n >> target;
    vector<pair<int,int> > inpt(n); //number & (orig index + 1)
    for(int i = 0; i<n; i++)
    {
        cin >> inpt[i].first;
        inpt[i].second = i+1;
    }
    sort(inpt.begin(),inpt.end());
    int a=0,b=n-1;
    while((inpt[a].first+inpt[b].first)!=target && a!=b)
    {
        if(inpt[a].first+inpt[b].first>target)
        {
            b--;
        }
        else if(inpt[a].first+inpt[b].first<target)
        {
            a++;
        }
    }
    if(a==b)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        int sol1 = min(inpt[a].second,inpt[b].second);
        int sol2 = max(inpt[a].second,inpt[b].second);
        cout << sol1 << " " << sol2;
    }
    /* printf("%lli",x); */
}