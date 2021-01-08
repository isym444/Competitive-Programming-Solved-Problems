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

struct triplet
{
    int a,b,c;
};


int main()
{
    ios_base::sync_with_stdio(0);
    setIO("bcount");
    //prefix sum of arr[[a,b,c]]

    //inputs
    ll i,n,q; cin >> n >> q;
    vector<ll> breeds(n);
    fo(i,n)
    {
        cin >> breeds[i];
    }
    vector<pair<ll,ll> > queries(q);
    fo(i,q)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    //prefix sum
    vector<triplet> breed_count(n);
    fo(i,n)
    {
        if(breeds[i]==1)
        {
            if(i!=0) breed_count[i]=breed_count[i-1];
            breed_count[i].a++;
        }
        else if(breeds[i]==2)
        {
            if(i!=0) breed_count[i]=breed_count[i-1];
            breed_count[i].b++;
        }
        else if(breeds[i]==3)
        {
            if(i!=0) breed_count[i]=breed_count[i-1];
            breed_count[i].c++;
        }
    }

    //executing queries
    //breed_count(2->5)=breed_count(0->5)-breed_count(0->1)
    fo(i,q)
    {
        ll f = queries[i].first-1, s = queries[i].second-1;
        if(f==0)
        {
            cout << breed_count[s].a << " " << breed_count[s].b << " " << breed_count[s].c << endl;
        }
        else
        {
            cout << breed_count[s].a-breed_count[f-1].a << " " << breed_count[s].b-breed_count[f-1].b << " " << breed_count[s].c-breed_count[f-1].c << endl;
        }
    }
}