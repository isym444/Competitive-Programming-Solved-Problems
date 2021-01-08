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
    int i;
    int finalcounter = 0;
    int lchecker = 0;
    int counter = 0;
    string a;
    cin >> a;
    /* cycle through each character
    if h go to next dif letter
    if e go to next dif letter
    if l go to next letter
    if l go to next dif letter
    if o print YES */
    for (i = 0; i < a.length(); i++)
    {
        while (a[i] != 'h' && i < a.length() + 1)
        {
            i++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        counter++;
        while (a[i] == 'h' && i < a.length() + 1)
        {
            i++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        while (a[i] != 'e' && i < a.length() + 1)
        {
            i++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        counter++;
        while (a[i] == 'e' && i < a.length() + 1)
        {
            i++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        while (a[i] != 'l' && i < a.length() + 1)
        {
            i++;
        }
        counter++;
        while (a[i] == 'l' && i < a.length() + 1)
        {
            i++;
            lchecker++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        if (lchecker == 1)
        {
            while (a[i] != 'l' && i < a.length() + 1)
            {
                i++;
                if (i == a.length() + 1)
                {
                    counter = finalcounter;
                    break;
                }
            }
            counter++;
            while (a[i] == 'l' && i < a.length() + 1)
            {
                i++;
                if (i == a.length() + 1)
                {
                    counter = finalcounter;
                }
            }
        }
        else if (lchecker > 1)
        {
            counter += 1;
        }
        while (a[i] != 'o' && i < a.length() + 1)
        {
            i++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        counter++;
        while (a[i] == 'o' && i < a.length() + 1)
        {
            i++;
            if (i == a.length() + 1)
            {
                counter = finalcounter;
            }
        }
        if (finalcounter == 0)
        {
            finalcounter = counter;
        }
    }
    if (finalcounter == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}