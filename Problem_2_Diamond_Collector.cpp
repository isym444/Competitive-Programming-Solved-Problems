/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
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

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("diamond");
    /* freopen(("cpp.in"), "r", stdin); */
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    //sort the array
    sort(a.begin(),a.end());
    //2 pointer technique to see max + second-max consecutive array elements s.t. r<=l+k
    int r=0;
    /* int ccur=0,cmax=0,csec=0,prevmax=1; */

    vector<int> max_dia_given_l(n+1);
    for(int l = 0; l<n; l++)
    {
        while(a[r]-a[l]<=k&&r<n)
        {
            r++;
        }
        max_dia_given_l[l]=r-l;
    }

    vector<int> max_collec_to_right_of_given_l_group_end(n+1);
    for(int l = n-1; l>=0; l--)
    {
        max_collec_to_right_of_given_l_group_end[l]=max(max_collec_to_right_of_given_l_group_end[l+1],max_dia_given_l[l+1]);
    }

    int ans=0;
    for(int l = 0; l<n; l++)
    {
        ans = max(ans,max_dia_given_l[l]+max_collec_to_right_of_given_l_group_end[l+max_dia_given_l[l]-1]);
    }

    cout << ans;

    /* cout << cmax + csec; */
    /* sort(ans.begin(),ans.end(),greater<int>());
    cout << ans[0] + ans[1]; */
    /* printf("%i",cmax+csec); */
    /* printf("%lli",x); */
}