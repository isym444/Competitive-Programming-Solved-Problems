/* #include <bits/stdc++.h> */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/* using std::vector; */

#define fo(i, n) for (i = 0; i < n; i++)

#define ll long long
#define sz(x) (int)(x).size()
#define mp make_pair
typedef pair<ll, ll> pl;

#define pb push_back

using namespace std;

int main() {
    freopen("cpp.in", "r", stdin);
/*     freopen("diamond.out", "w", stdout);
 */
    int n, k; cin >> n >> k;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A, A+n);

    // how many diamonds we can take
    // assuming i is the leftmost diamond
    int canTakeLeft[n];
    int l = 0, r = 0;
    for (; l < n; l++) {
        while (r < n && A[r] - A[l] <= k) r++;
        canTakeLeft[l] = r - l;
    }

    // maxValAfterI[i] = max value of canTakeLeft[x] for some x >= i.
    int maxValAfterI[n+1];
    maxValAfterI[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        maxValAfterI[i] = max(maxValAfterI[i+1], canTakeLeft[i]);
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        ans = max(ans, canTakeLeft[l] + maxValAfterI[l + canTakeLeft[l]]);
    }
    /* cout << ans << endl; */
    printf("%i",ans);

    return 0;
}