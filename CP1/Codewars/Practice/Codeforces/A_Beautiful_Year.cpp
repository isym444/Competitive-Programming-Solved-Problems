/* #include <bits/stdc++.h> */
#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <string>
using namespace std;
/* using std::vector; */

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
typedef pair<ll, ll> pl;

typedef vector<int> vi;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
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
    int a;
    int b = 1;
    si(a);
    int c = to_string(a).length();
    string d;
    set<int> s1;
    while (b == 1)
    {
        a++;
        d = to_string(a);
        s1.clear();
        for (int i = 0; i < c; i++)
        {
            s1.insert(d[i]);
        }
        if (s1.size() == 4)
        {
            pi(a);
            b = 0;
        }
    }
}