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

long long n, buses, capacity,t,l,m,r;
vector<long long> cows;

bool checker(long long m)
{
    long long p=0,L=0,R=0,locount=0;
    while(R<n)
    {
        while(R-L+1<=capacity && cows[R]-cows[L]<=m)//m is time diference being checked
        {
            R++;
            if(R>=n){
                break;
            }
        }
        L=R;
        locount++;
    }
    return(locount<=buses);
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("convention");
    /* freopen(("filename"), "r", stdin); */
    //N M C #cows, #buses (N.B. don't have to be full before leave), #cows that fit within each bus
    cin >> n >> buses >> capacity;
    for(int i = 0; i<n; i++)
    {
        long long temp;
        cin >> temp;
        cows.push_back(temp);
    }
    //sort arrival times of cows
    sort(cows.begin(),cows.end());
    //change time interval between sorted cows to place them into 'buses' (i.e. before counter++) WHILST maintaing #cows/bus<=C -> return checker true if buses used <= buses;
    t=1000000000;
    l=0;
    r=1000000000;
    while(l<=r)
    {
        m=l+(r-l)/2; //m is time difference being checked
        if(checker(m)){
            t=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout << t;
    //binary search until find smallest time interval where #buses used<=M
    /* printf("%lli",x); */
}