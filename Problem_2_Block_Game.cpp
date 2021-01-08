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
    setIO("blocks");
    int n;
    string a, b;
    cin >> n;
    int letters1[25], letters2[25], letters_total[25];
    for (int i = 0; i <= 25; i++)
    {
        letters_total[i] = 0;
    }
    while (n--)
    {
        cin >> a >> b;
        for (int i = 0; i <= 25; i++)
        {
            letters1[i] = 0;
            letters2[i] = 0;
        }
        for (int i = 0; i < a.length(); i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                if (a[i] == j)
                {
                    letters1[j - 'a']++;
                }
            }
        }
        for (int i = 0; i < b.length(); i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                if (b[i] == j)
                {
                    letters2[j - 'a']++;
                }
            }
        }
        for (int i = 0; i <= 25; i++)
        {
            letters_total[i] += max(letters1[i], letters2[i]);
        }
    }
    for (int i = 0; i <= 25; i++)
    {
        cout << letters_total[i] << "\n";
    }
}