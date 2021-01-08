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
    setIO("blist");
    int N; cin >> N;
    int si[101]={}, ti[101]={}, bi[101]={}, maxbuckets=0, maxmaxbuckets=0;
    for(int i = 0; i < N; i++)
    {
        cin >> si[i] >> ti[i] >> bi[i];
    }
    int a[1001]={};
    for(int i = 0; i<N; i++)
    {
        a[si[i]]+=bi[i];
        a[ti[i]]-=bi[i];
    }
    for(int i = 0; i<1001; i++)
    {
        maxbuckets+=a[i];
        maxmaxbuckets=max(maxbuckets,maxmaxbuckets);
    }
    /* for(int i = 0; i<1001; i++)
    {
        maxbuckets = 0;
        for(int j = 0; j<N; j++)
        {
            if(si[j]<=i && ti[j]>=i)
            {
                maxbuckets+=bi[j];
            }
        }
        maxmaxbuckets=max(maxmaxbuckets,maxbuckets);
    } */
    cout << maxmaxbuckets;
}