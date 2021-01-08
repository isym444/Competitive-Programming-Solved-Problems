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

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int n, first, curr, totc, totp, ans; cin >> n;
    vector<int> s;
    totc=1;
    totp=0;
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> curr;
        s.pb(curr);
    }
    for(int i = 1; i < n; i++)
    {
        if(s[i]==s[i-1])
        {
            totc+=1;
        }
        else
        {
            ans = max(ans,min(totp, totc));
            totp = totc;
            totc = 1;
        }
    }
    ans = max(ans,min(totp, totc));
    cout << ans*2;
}