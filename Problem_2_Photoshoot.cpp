/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_set>


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

void solve(int N, vector<int> a)
{
    vector<int> c;
    for(int l = 0; l<N; l++)
    {
        c.erase(c.begin(),c.end());
        c.pb(l+1);
        for(int j = 0; j<N; j++)
        {
            c.pb(a[j]-c[j]);
        }
        unordered_set<int> set;
        set.insert(c.begin(),c.end());
        int p=count(c.begin(), c.end(), 0);
        for(int j = 0; j<N; j++)
        {
            if(c[j]<0)
            {
                p+=1;
            }
        }
        if(set.size()==N && p==0)
        {
            for(int k = 0; k<N-1; k++)
            {
                cout << c[k] << " ";
            }
            cout << c[N-1];
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int N,x; cin >> N;
    int sumofvec=0;
    vector<int> a,b;
    for(int i = 0; i<N; i++)
    {
        cin >> x;
        a.pb(x);
        b.pb(i+1);
        sumofvec+=i+1;
    }
    solve(N,a);
}