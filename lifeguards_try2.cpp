/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <limits.h>

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
    /* process input */
    /* order lifeguards by working start time */
    /* at each time point check how many lifeguards are working */
    /* at each time point, if >=1 lifeguards are working, +=1 to TOTAL TIME COVERED */
    /* if only one lifeguard is working, track how much time that lifeguard works alone */
    /* find MINIMUM TIME ANY LIFEGUARD WORKS ALONE */
    /* ans = TOTAL TIME COVERED - MINIMUM TIME ANY LIFEGUARD WORKS ALONE */

    /* process input */
    ll a, b, last_work=0;
    ll N; cin >> N;
    vector<pair<ll,ll>> lifeguard_shifts;
    for(ll i = 0; i<N; i++)
    {
        cin >> a >> b;
        auto c = make_pair(a, b);
        lifeguard_shifts.push_back(c);
    }
    /* order lifeguards by working start time */
    sort(lifeguard_shifts.begin(),lifeguard_shifts.end());
    /* find last lifeguard working time */
    ll first_work=20;
    for(ll i = 0; i<N; i++)
    {
        last_work = max(last_work, lifeguard_shifts[i].second);
        first_work = min(first_work, lifeguard_shifts[i].first);
    }
    cout << "last_work" << last_work << "\n";
    cout << "first_work" << first_work << "\n";

    /* 1 4, 3 7, 5 9 */

    /* check time worked for lifeguard i*/
    ll total_time_worked;
    ll time_alone[N];
    total_time_worked=0;
    total_time_worked+=lifeguard_shifts[0].second-lifeguard_shifts[0].first;
    /* cout << total_time_worked << "\n"; */
    for(ll i = 1; i<N; i++)
    {
        /*if lifeguard i+1 starts working after lifeguard i finished, timeworked alone[i] = end-start & totalwork += timeworked alone[i]*/
        if(lifeguard_shifts[i].first<lifeguard_shifts[i-1].second && lifeguard_shifts[i].second<lifeguard_shifts[i-1].second)
        {
            time_alone[i]=0;
        }
        else if(lifeguard_shifts[i].first>lifeguard_shifts[i-1].second)
        {
            time_alone[i] = lifeguard_shifts[i].second-lifeguard_shifts[i].first;
            total_time_worked+=time_alone[i];
            /* cout << total_time_worked << "\n"; */
        }
        /*if lifeguard i+1 starts working whilst lifeguard i is working:
        time worked alone by lifeguard i -= lifeguard[i]_end - lifeguard[i+1]_start
        time worked alone by lifeguard i+1 = lifeguard[i+1]_end - lifeguard[i]_end
        totalwork += timeworked alone by lifeguard i+1*/
        else if(lifeguard_shifts[i].first<lifeguard_shifts[i-1].second && lifeguard_shifts[i].second>lifeguard_shifts[i-1].second)
        {
            time_alone[i-1]-=lifeguard_shifts[i-1].second-lifeguard_shifts[i].first;
            time_alone[i]=lifeguard_shifts[i].second-lifeguard_shifts[i-1].second;
            total_time_worked+=time_alone[i];
            /* cout << total_time_worked << "\n"; */
        }
    }
    /* time alone for 1st lifeguard */
    if(lifeguard_shifts[1].first>lifeguard_shifts[0].second)
        {
            time_alone[0] = lifeguard_shifts[0].second-lifeguard_shifts[0].first;
            /* cout << time_alone[0] << "\n"; */
        }
        /*if lifeguard i+1 starts working whilst lifeguard i is working:
        time worked alone by lifeguard i -= lifeguard[i]_end - lifeguard[i+1]_start
        time worked alone by lifeguard i+1 = lifeguard[i+1]_end - lifeguard[i]_end
        totalwork += timeworked alone by lifeguard i+1*/
        else if(lifeguard_shifts[1].first<lifeguard_shifts[0].second)
        {
            time_alone[0]=lifeguard_shifts[1].first-lifeguard_shifts[0].first;
            /* cout << time_alone[0] << "\n"; */
        }
        /* cout << "\n" << lifeguard_shifts[0].first << " " << lifeguard_shifts[0].second << "\n";
        cout << lifeguard_shifts[1].first << " " << lifeguard_shifts[1].second << "\n" << "\n"; */
    /* find MINIMUM TIME ANY LIFEGUARD WORKS ALONE */
    ll total_min=1000000;
    for(ll i = 0; i<N; i++)
    {
        /* cout << total_min << "\n";
        cout << time_alone[i] << "\n"; */
        if(total_min>time_alone[i]&&time_alone[i]>0)
        {
            total_min=time_alone[i];
        }
        /* total_min=min(total_min, time_alone[i]); */
        /* cout << total_min << "\n"; */
    }
    /* ans = TOTAL TIME COVERED - MINIMUM TIME ANY LIFEGUARD WORKS ALONE */
    ll ans = total_time_worked-total_min;
    cout << total_time_worked << "\n";
    cout << total_min << "\n";
    cout << ans;
    /*if lifeguard i+1 starts working after lifeguard i finished, timeworked alone[i] = end-start & totalwork += timeworked alone[i]*/
    /*if lifeguard i+1 starts working whilst lifeguard i is working:
        time worked alone by lifeguard i -= lifeguard[i]_end - lifeguard[i+1]_start
        time worked alone by lifeguard i+1 = lifeguard[i+1]_end - lifeguard[i]_end
        totalwork += timeworked alone by lifeguard i+1*/
}