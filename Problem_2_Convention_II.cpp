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
    int i, n,t=0, current_finish=0; cin >> n;
    // remaining cows: sorted by start time + extra field for seniority (original order in input)
    vector<pair<pair<int, int>,int> > remaining_cows(n); // start time, time spent eating, seniority
    fo(i,n)
    {
        cin >> remaining_cows[i].first.first >> remaining_cows[i].first.second;
        remaining_cows[i].second = i;
    }
    sort(remaining_cows.begin(), remaining_cows.end());
    // waiting cows: sorted by seniority (original order in input), keep start + time eating NOT ENDING time information
    vector<pair<int,pair<int,int> > > waiting_cows;
    // eating cow: start time + eating time NOT end time
    vector<pair<int,int> > eating_cow;
    // cur_waiting & max_waiting
    int cur_waiting = 0, max_waiting = 0;
    // if no cows eating: cow eating: remove from remaining cows vector with earliest start time (if same start time, seniority) -> put into eating cow vector
    while(!remaining_cows.empty())
    {
        if(eating_cow.empty())
        {
            // if doesn't AC, add if else for if 2 cows have same start time
            eating_cow.push_back(make_pair(remaining_cows[0].first.first, remaining_cows[0].first.second));
            remaining_cows.erase(remaining_cows.begin());
        }
        // if cow eating: from remaining cows vector remove cows into a waiting cows vector -> sort by seniority -> replace into eating cow vector in turn -> keep track of waiting time -> max waiting time
        else
        {
            if(remaining_cows[0].first.first>(eating_cow[0].first+eating_cow[0].second) && !remaining_cows.empty())
            {
                eating_cow.erase(eating_cow.begin());
                eating_cow.push_back(make_pair(remaining_cows[0].first.first, remaining_cows[0].first.second));
                remaining_cows.erase(remaining_cows.begin());
            }
            while(remaining_cows[0].first.first<=(eating_cow[0].first+eating_cow[0].second) && !remaining_cows.empty())
            {
                waiting_cows.push_back(make_pair(remaining_cows[0].second,make_pair(remaining_cows[0].first.first,/* remaining_cows[0].first.first+ */remaining_cows[0].first.second)));
                remaining_cows.erase(remaining_cows.begin());
            }
            sort(waiting_cows.begin(),waiting_cows.end());
            while(!waiting_cows.empty())
            {
                //first time current_finish = eating_cow[0].first+eating_cow[0].second;
                //subsequent times, current_finish = current+finish+eating_cow[0].second;
                if(t==0)
                {
                    current_finish = eating_cow[0].first+eating_cow[0].second;
                    t++;
                }
                else
                {
                    current_finish = current_finish+eating_cow[0].second;
                }
                //int current_finish = eating_cow[0].second; PROBLEM: eating_cow[0] is recording original ending time not taking into account waiting delay
                eating_cow.erase(eating_cow.begin());
                eating_cow.push_back(make_pair(waiting_cows[0].second.first,waiting_cows[0].second.second));
                cur_waiting = current_finish-waiting_cows[0].second.first;
                max_waiting = max(max_waiting,cur_waiting);
                waiting_cows.erase(waiting_cows.begin());
            }
            t=0;
        }
    }
    cout << max_waiting;
}