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
    setIO("");
    int n;
    cin >> n;
    vector<pair<int, int>> myvec;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        myvec.pb(mp(a, 1));
        myvec.pb(mp(b, -1));
    }
    sort(myvec.begin(), myvec.end());
    int sum = 0;
    int ans = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        sum += myvec[i].second;
        ans = max(ans, sum);
    }
    cout << ans;
}

/* #include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

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
    ios::sync_with_stdio(false);
    setIO("cpp");
    int n;
    cin >> n;
    vector<pi> vals;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        vals.pb(mp(l, 1));
        vals.pb(mp(r, -1));
    }

    sort(all(vals));

    int sum = 0;
    int ans = 0;
    for (auto x : vals)
    {
        sum += x.s;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
} */
