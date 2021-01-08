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
    int N,a,d, ans=0, test;
    string b,c;
    cin >> N;
    /* vector<pair<int, string>> cows; */
    vector<tuple<int, string, int>> cows;
    /* cows.push_back(tuple<int, string, int>(2,"bessie",2)); */
    /* pair<int, string> a; */
    //Getting input + ordering it by day
    for(int i = 0; i<N; i++)
    {
        cin >> a >> b >> c;
        if(c[0]=='+')
        {
            c.erase(0,1);
            d = stoi(c);
            cows.push_back(tuple<int, string, int>(a,b,d));
        }
        if(c[0]=='-')
        {
            c.erase(0,1);
            d = -stoi(c);
            cows.push_back(tuple<int, string, int>(a,b,d));
        }
        if(c[0]=='0')
        {
            d = stoi(c);
            cows.push_back(tuple<int, string, int>(a,b,d));
        }
    }
    sort(cows.begin(),cows.end());

    //Make vector that tracks cow milk output
    vector<pair<string, int>> milk;
    milk.push_back(make_pair("Mildred",7));
    milk.push_back(make_pair("Elsie",7));
    milk.push_back(make_pair("Bessie",7));
    //Adjust cow milk output vector according to input vector + Check with each adjustment if max cow name changes in which case add 1 to ans
    string maxcow1 = "xyz";
    int maxcowval = 7;
    string maxcow2 = "abc";
    vector<string> prevmaxcow;
    vector<string> curmaxcow;
    curmaxcow.push_back("empty");
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(milk[j].first==get<1>(cows[i]))
            {
                milk[j].second+=get<2>(cows[i]);
                int tempor[]={milk[0].second,milk[1].second,milk[2].second};
                maxcowval=*max_element(tempor, tempor+2);
/*                 maxcowval=max(maxcowval, milk[2].second); */
                for(int k=0; k<3; k++)
                {
                    if(milk[k].second==maxcowval && count(prevmaxcow.begin(), prevmaxcow.end(), milk[k].first)==0)
                    {
                        ans+=1;
                        break;
                    }
                }
                for(int k=0; k<3; k++)
                {
                    if(milk[k].second==maxcowval && count(prevmaxcow.begin(), prevmaxcow.end(), milk[k].first)==0)
                    {
                        curmaxcow.clear();
                    }
                }
                for(int k=0; k<3; k++)
                {
                    if(milk[k].second==maxcowval && count(prevmaxcow.begin(), prevmaxcow.end(), milk[k].first)==0)
                    {
                        curmaxcow.push_back(milk[k].first);
                    }
                }
                if(count(curmaxcow.begin(), curmaxcow.end(), "empty")==0)
                {
                    prevmaxcow.clear();
                    prevmaxcow = curmaxcow;
                    curmaxcow.clear();
                    curmaxcow.push_back("empty");
                }
            }
        }

    }
    cout << ans;
}


