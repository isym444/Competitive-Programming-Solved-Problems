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

/* #include <iostream>
#include <fstream> */
const int MAX_N = 100;
/* using namespace std; */
 
// changes[c][d] is the change in milk rate for cow c on day d
// rates[c][d] is the milk rate for cow c on day d
int changes[3][MAX_N+1];
int rates[3][MAX_N+1];
 
// Is cow c the highest on day d?
bool is_highest(int c, int d)
{
  int highest = max(max(rates[0][d], rates[1][d]), rates[2][d]);
  return rates[c][d] == highest;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("cpp");

  int N, d, c, x;
  string name;
  
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> d >> name >> x;
    if (name == "Bessie") c = 0;
    if (name == "Elsie") c = 1;
    if (name == "Mildred") c = 2;
    changes[c][d] = x;
  }
  
  for (int c=0; c<3; c++)  
    rates[c][0] = 7;
 
  for (int c=0; c<3; c++)
    for (int d=1; d<=100; d++) 
      rates[c][d] = rates[c][d-1] + changes[c][d];
  
  int num_changes = 0;
 
  for (int d=1; d<=100; d++) {
    if (is_highest(0,d-1) != is_highest(0,d) ||
		      is_highest(1,d-1) != is_highest(1,d) ||
		      is_highest(2,d-1) != is_highest(2,d))
      num_changes++;
  }
  
  cout << num_changes << "\n";
}



