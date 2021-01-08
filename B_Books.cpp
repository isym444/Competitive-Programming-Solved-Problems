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
    int n,t; cin >> n >> t;
    vector<int> inpt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> inpt[i];
    }
    /* sort(inpt.begin(),inpt.end()); */
    int l=0,count=0,sum=0;
    for(int r = 0; r<n; r++)
    {
        sum+=inpt[r];
        if(sum<=t)
        {
            count++;
        }
        else
        {
            sum-=inpt[l];
            l++;
        }
    }
    cout << count;
    /* printf("%lli",x); */
}


