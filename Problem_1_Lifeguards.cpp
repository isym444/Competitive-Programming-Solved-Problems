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
    setIO("cpp");
    int n;
    cin >> n;
    vector<pair<int, int>> lg_io;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lg_io.pb(mp(a, 1));
        lg_io.pb(mp(b, -1));
    }
    sort(begin(lg_io), end(lg_io));
    int num_working = 0;
    int min_alone_time = 0;
    int cur_alone_time = 0;
    int total_work_time = 0;
    cur_alone_time = lg_io[1].first - lg_io[0].first;
    num_working = 1;
    min_alone_time = cur_alone_time;
    for (int i = 1; i < 2 * n - 1; i++)
    {
        num_working += lg_io[i].second;
        if (num_working == 1)
        {
            cur_alone_time = lg_io[i + 1].first - lg_io[i].first;
            min_alone_time = min(min_alone_time, cur_alone_time);
        }
    }
    num_working = 0;
    num_working += 1;
    for (int i = 1; i < 2 * n; i++)
    {
        num_working += lg_io[i].second;
        if (num_working > 0)
        {
            total_work_time += lg_io[i].first - lg_io[i - 1].first;
        }
    }
    cout << total_work_time - min_alone_time;
    /* time working alone for each lifeguard -> when number working is 1, subtract start time of next lifeguard - start time of alone lifeguard
    find min time any lifeguard is working alone
    subtract from total time covered by all lifeguards */
}