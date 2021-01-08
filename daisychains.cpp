#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

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
    int N, extra; cin >> N;
    double average;
    /* average = (float)4/3; */
    int answer = 0;
    int sum = 0;
    int a[N];
    for(int i = 0; i<N; i++)
    {
        cin >> a[i];
        answer+=1;
    }
    for(int i = 0; i<N; i++)
    {
        for(int k = i+1; k<N; k++)
        {
            sum = 0;
            for(int t = i; t<=k; t++)
            {
                sum+=a[t];
            }
            average = (float)sum/((k-i)+1);
            for(int t = i; t<=k; t++)
            {
                if(a[t]==average)
                {
                    answer+=1;
                    break;
                }
            }
        }
    }
    cout << answer;
}


/* answer = N + extra (i.e. photos containing more than 1 flower) average flower photos */
