/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
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

long long n,tmax, t, k, ans, m,l,r;
vector<long long> dance_duration;
priority_queue<long long> pq;
long long cow;
long long temp;

bool checker(long long m)
{
    //if output<=Tmax return true
    //k=numbers of simultaneous cows on stage
    t=0;
    cow = 0;
    //while cows remaining + priority queue size<=k: add cows to priority queue
    while(cow<n && pq.size()<m)
    {
        pq.push(-dance_duration[cow]);
        cow++;
    }
    while(pq.size()>0)
    {
        t+=max((long long) 0,(-pq.top()-t)); //top - t because top was dancing during previous cow time, which is accounted for in t as top cow dance time added to t at each round. If this value is negative, it means that the cow would have finished whilst previous cow was still dancing so no new time should be added to t
        pq.pop();
        if(cow<n)
        {
            pq.push(-(dance_duration[cow]+t)); //next cow + t because have been waiting time elapsed thus far (t) whilst previous cows were dancing
            cow++;
        }
    }
    return(t<=tmax);
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("cowdance");
    /* freopen(("filename"), "r", stdin); */
    cin >> n >> tmax;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        dance_duration.push_back(temp);
    }
    //find smallest k for t<tmax
    k=n;
    l=0;r=n-1;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(checker(m))
        {
            k=m;
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    cout << k;
    /* printf("%lli",x); */
}