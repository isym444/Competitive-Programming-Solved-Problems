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

int result[2000]={};

void friday(int t1,vector<int> bl, vector<int>br)
{
    for(int i = 0; i<br.size(); i++)
    {
        vector<int> nbl = bl; nbl.pb(br[i]);
        vector<int> nbr = br; nbr.erase(nbr.begin()+i);
        result[t1+br[i]]=1;
    }
}
void thursday(int t1,vector<int> bl, vector<int>br)
{
    for(int i = 0; i<bl.size(); i++)
    {
        vector<int> nbr = br; nbr.pb(bl[i]);
        vector<int> nbl = bl; nbl.erase(nbl.begin()+i);
        friday(t1-bl[i], nbl, nbr);
    }
}

void wednesday(int t1,vector<int> bl, vector<int>br)
{
    for(int i = 0; i<br.size(); i++)
    {
        vector<int> nbl = bl; nbl.pb(br[i]);
        vector<int> nbr = br; nbr.erase(nbr.begin()+i);
        thursday(t1+br[i], nbl, nbr);
    }
}

void tuesday(int t1,vector<int> bl, vector<int>br)
{
    for(int i = 0; i<bl.size(); i++)
    {
        vector<int> nbr = br; nbr.pb(bl[i]);
        vector<int> nbl = bl; nbl.erase(nbl.begin()+i);
        wednesday(t1-bl[i], nbl, nbr);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("backforth");
    int t1=1000,t2=1000, ans=0, x;
    vector<int> bl(10,0);
    vector<int> br(10,0);
    for(int i = 0; i<10; i++)
    {
        cin >> x;
        bl[i] = x;
    }
    for(int i = 0; i<10; i++)
    {
        cin >> br[i];
    }
    tuesday(t1,bl,br);
    for(int i = 0; i<2001; i++)
    {
        if(result[i]==1)
        {
            ans+=1;
        }
    }
    cout << ans;
}