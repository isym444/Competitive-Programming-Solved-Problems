/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
/* using std::vector; */

#define fo(i, n) for (i = 0; i < n; i++)

#define ll long long
#define sz(x) (ll)(x).size()
#define mp make_pair
typedef pair<ll, ll> pl;

#define pb push_back

//=======================

/* void setIO(string name = "")
{ // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
        freopen((name + ".out").c_str(), "w", stdout);
    }
} */

int main()
{
    ios_base::sync_with_stdio(0);
    /* setIO("int"); */
    freopen(("int"), "r", stdin);
    ll i, n,t=0, current_finish=0; cin >> n;
    // remaining cows: sorted by start time + extra field for seniority (original order in input)
    vector<pair<pair<ll, ll>,ll> > remaining_cows(n); // start time, time spent eating, seniority
    fo(i,n)
    {
        cin >> remaining_cows[i].first.first >> remaining_cows[i].first.second;
        remaining_cows[i].second = i;
    }
    sort(remaining_cows.begin(), remaining_cows.end());
    ll r_c = 0;
    priority_queue<pair<ll,ll> > waiting; //seniority (original index) + (ordered) index i.e. r_c
    ll cur_waiting = 0, max_waiting = 0;
    current_finish=remaining_cows[0].first.first+remaining_cows[0].first.second;
    r_c++;
    while(r_c<n||!waiting.empty())
    {
        while(remaining_cows[r_c].first.first<=current_finish && r_c<n)
            {
                waiting.push(make_pair(-remaining_cows[r_c].second,r_c));
                r_c++;
            }
        if(waiting.empty()&&r_c<n)
        {
            current_finish=remaining_cows[r_c].first.first+remaining_cows[r_c].first.second;
            r_c++;
        }
        else
        {
            while(!waiting.empty())
            {
                cur_waiting = current_finish-remaining_cows[waiting.top().second].first.first;
                max_waiting = max(max_waiting,cur_waiting);
                current_finish += remaining_cows[waiting.top().second].first.second;
                waiting.pop();
            }
        }

    }
    /* cout << max_waiting; */
    printf("%lli\n", max_waiting);
}