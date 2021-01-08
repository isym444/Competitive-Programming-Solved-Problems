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

long long maxx;
long long n,k,ans;
vector<long long> v;

bool f2(long long p)
{
    //return true if # operations needed <= i (target);
    long long sum=0;
    for(int t=n/2;t<n;t++)
    {
        sum+=max((long long) 0,p-v[t]);
    }
    return(sum<=k);
}

long long f1()
{
    for(int j = maxx; j>=1; j/=2)
    {
        while(f2(ans+j)) ans+=j;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    /* freopen(("filename"), "r", stdin); */
    cin >> n >> k;
    maxx = (long long) 2E9;
    for(int i = 0; i<n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << f1();
    /* printf("%lli",x); */
}