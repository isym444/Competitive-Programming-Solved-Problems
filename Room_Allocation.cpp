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
    int i, n,db; cin >> n;
    vector<pair<pair<int,int>, int> > times(n);
    fo(i,n)
    {
        cin >> times[i].first.first >> times[i].first.second; //start and end time
        times[i].second=i; //original index before sorting
    }
    sort(times.begin(),times.end());
    priority_queue<pair<int, int> > tr;//keep track of leaving times i.e. when rooms will become available + room number
    int room=0;
    int curr_occupied_rooms=0;
    int max_occupied_rooms=0;
    int ans[n];
    fo(i,n)
    {
        if(tr.empty())
        {
            room++;
            tr.push(make_pair(-times[i].first.second, room));
            ans[times[i].second]=room;
            curr_occupied_rooms++;
        }
        else
        {
            if(-tr.top().first<times[i].first.first) //? -ve
            {
                db=tr.top().first;
                int temp = tr.top().second;
                tr.pop();
                tr.push(make_pair(-times[i].first.second, temp));
                ans[times[i].second]=temp;
            }
            else
            {
                db=tr.top().first;
                room++;
                tr.push(make_pair(-times[i].first.second, room));
                ans[times[i].second]=room;
                curr_occupied_rooms++;
            }
        }
/*         max_occupied_rooms=max(max_occupied_rooms,curr_occupied_rooms); */
    }
    cout << curr_occupied_rooms << endl;
    fo(i,n)
    {
        cout << ans[i] << " ";
    }
}