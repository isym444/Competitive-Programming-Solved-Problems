#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;


void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if ((int)(name).size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("");
    int N; cin >> N;
    int test=100;
    int infinity[N];
    int grasseaten[N];
    vector<pair<int, int>> nograsspoints;
    /* nograsspoint.push_back({x,y}) */
    for(int i = 0; i<N; i++)
    {
        infinity[i]=0;
        grasseaten[i]=1;
    }
    /* int location[N][2]; */
    vector<pair<int,int>> location;
    string direction[N];
    for(int i = 0; i<N; i++)
    {
        int c, d;
        cin >> direction[i] >> c >> d;
        location.push_back(make_pair(c,d));
    }
    for(int i = 0; i<1000; i++)
    {
        for(int k = 0; k<N; k++)
        {
            int a = location[k].first;
            int b = location[k].second;
            auto c = make_pair(a,b);
            if(count(nograsspoints.begin(), nograsspoints.end(), c)==0)/* if point not already in nograsspoints */
            {
                nograsspoints.push_back(make_pair(a,b));/* add current cow locations to nograsspoints */
            }
        }
        for(int k = 0; k<N; k++)
        {
            if(direction[k]=="E")
            {
                location[k].first+=1;/* move every cow according to their direction */
                grasseaten[k]+=1;
                int a = location[k].first;
                int b = location[k].second;
                auto c = make_pair(a,b);
                if(count(nograsspoints.begin(), nograsspoints.end(), c)==1/* new location in nograsspoints */)
                {
                    direction[k]="Q";/* stop moving by changing direction to Q */
                    grasseaten[k]-=1;
                }
            }
            if(direction[k]=="N")
            {
                location[k].second+=1;
                grasseaten[k]+=1;
                int a = location[k].first;
                int b = location[k].second;
                auto c = make_pair(a,b);
                if(count(nograsspoints.begin(), nograsspoints.end(), c)==1/* new location in nograsspoints */)
                {
                    direction[k]="Q";/* stop moving by changing direction to Q*/
                    grasseaten[k]-=1;
                }
            }
        }
    }
    for(int i = 0; i<N-1; i++)
    {
        if(grasseaten[i]==1001)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            cout << grasseaten[i] << endl;
        }
    }
    if(grasseaten[N-1]==1001)
    {
        cout << "Infinity";
    }
    else
    {
        cout << grasseaten[N-1];
    }
}