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
    setIO("paintbarn");
    /* freopen(("filename"), "r", stdin); */
    //figure out area of barn covered by exactly k layers of paint
    //
    /* printf("%lli",x); */
    int n, k;
    cin >> n >> k;
    int plane[1001][1001] = {0};
    int a,b,c,d;
    int area=0;
    //locations on the 2d plane where you would "pick up a bucket" and "put down a bucket".
    //The +1 value will spread within the rectangle in the next part of the program with the -1 at UL + LR corners preventing it from propagating beyond the limits of the rectangle.
    for(int i = 0; i<n; i++)
    {
        cin >> a >> b >> c >> d;
        plane[a][b]++;
        plane[c][d]++;
        plane[a][d]--;
        plane[c][b]--;
    }
    //Spreading the value using 2d prefix sum
    for(int i = 0; i<1001; i++)
    {
        for(int j = 0; j<1001; j++)
        {
            if(i>0)
            {
                plane[i][j]+=plane[i-1][j];
            }
            if(j>0)
            {
                plane[i][j]+=plane[i][j-1];
            }
            if(i>0&&j>0)
            {
                plane[i][j]-=plane[i-1][j-1];
            }
            if(plane[i][j]==k)
            {
                area++;
            }
        }
    }
    cout << area;
}