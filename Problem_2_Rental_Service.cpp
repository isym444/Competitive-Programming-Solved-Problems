/* #include <bits/stdc++.h> */
#include <cstdio>
#include <functional>
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
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("cpp");
    int n,m,r,temp,a,b; cin >> n >> m >> r;
    vector<int> milk_p_day;
    vector<pair<int,int>> gal_ppg;
    vector<int> rent_p_day;
    //input
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        milk_p_day.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        auto c=make_pair(b,a);
        gal_ppg.push_back(c);
    }
    for(int i=0;i<r;i++)
    {
        cin >> temp;
        rent_p_day.push_back(temp);
    }
    //sorting
    sort(milk_p_day.begin(),milk_p_day.end(),greater<int>());
    sort(gal_ppg.begin(),gal_ppg.end(),cmp);
    sort(rent_p_day.begin(),rent_p_day.end(),greater<int>());
    //algorithm
    long long solution=0;
    int curi=0; //curi is current milk renter i
    int previ=0;
    int curmon=0;
    int cur_rent_i=0;
    int cur_rent = 0;
    int cur_buy = 0;
    int i = 0;
    //while not finished allocating all cows to sell their milk or rent
    while(i<n)
    {
        if(curi<m)
        {//get price for selling their milk
        curmon=0;
        a=milk_p_day[i];
        b=gal_ppg[curi].second;
        cur_buy=gal_ppg[curi].first; //cur_buy is current price of milk
        curi=previ;
        while(b<=a)
        {
            if(curi>=m)
            {
                curmon=0;
                break;
            }
            else
            {
            curmon+=cur_buy*b;
            a-=b;
            curi++; //?problem
            if(curi>=m)
            {
                break;
            }
            else
            {
                b=gal_ppg[curi].second;
                cur_buy=gal_ppg[curi].first;
            }
            }
        }
        if(curi<m)
        curmon+=cur_buy*a;
        b-=a;
        }
        else
        {
            curmon=0;
        }
        //milk is sold
        //price for renting cow
        if(cur_rent_i<r)
        {
            cur_rent = rent_p_day[cur_rent_i];
        }
        else
        {
            cur_rent = 0;
        }
        //if price for selling milk > renting cow, sell milk, else rent cow that produces least milk -> add profit to solution

        if(cur_rent_i>=r || curmon>cur_rent)//not sold all milk)
        {
            solution+=curmon;
            gal_ppg[curi].second=b;
            i++;
            previ=curi;
        }
        else
        {
            solution+=cur_rent;
            cur_rent_i++;
            n--;
        }
        cout << solution << "\n";
    }
    cout << solution;
}

// N cows produce ci milk gallons per day
// M stores buy UP TO qi gallons of milk at pi price per gallon
// R farmers rent cows at ri cents per day
// ans = max amount of money per day

// order cows from least milk producing to most milk producing
// order price per gallon from highest to lowest
// order rent per day from highest to lowest

// starting with least milk producing cow: compare profit from renting her for max price vs

//SOLUTION:
/* sort everything in descending order

while i<n (sell milk < rent cows)

	while all cows milk not sold, keep going through shops that will buy it
	keep track of what shop you're at for next time + how many gallons that shop still wants

	compare profit selling cows milk vs profit if were to rent cow
	- if more by renting then n--
	- if more by selling milk then i++ & confirm what shop+gallon you'll be starting from */


//DEBUG STEPTHROUGH:
       /*  int iShop = 0;
38	    int iRent = 0;
39	    int i = 0;
40	    ll sol = 0;
41	    while (i < n) {
42	        int litres = production[i]; // 7 gal
43	        int moneyT = 0, curI = iShop; // curI = 0
44	        int last = 0;
45	        while (curI < m) { // 0 < 3
46	            int rest = min(litres, shops[curI].second); //rest = min(7 gal, 10 gal) i.e. min(cur cow milk vs milk shop wants to buy)
47	            moneyT += shops[curI].first * rest; // moneyT += 25 cents * 7 gal i.e. moneyTotal += cur cow milk * cur shop price OR cur shop milk * cur shop price
48	            litres -= rest; // litres (7gal) -= 7 gal
49
50	            if (litres == 0) {
51	                last = rest; // last = 7 gal
52	                break;
53	            } else {
54	                curI++;
55	            }
56	        }
57
58	        if (iRent >= r || moneyT > rent[iRent]) {
59	            sol += moneyT;
60	            iShop = curI;
61	            if (iShop < m) shops[iShop].second -= last;
62	            i++;
63	        } else {
64	            sol += rent[iRent];
65	            n--;
66	            iRent++;
67	        }
68	    }

        cout << sol << '\n';
 */