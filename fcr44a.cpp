#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, m = INT_MAX;
int c[maxN], f[maxN];

int main() {

    // freopen("fcr44a.inp", "r", stdin);
    // freopen("fcr44a.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    f[n] = INT_MAX;
    for (int i = n-1; i >= 1 ; i--) {
        f[i] = min(f[i+1],c[i+1]);
    }

    int ans = 0;
    for (int i = 1; i <= n-1 ; i++)
        ans = max((c[i]-f[i]),ans);

    if (ans > 0) {
        cout << ans;
    } else {
        cout << "Lo nang roi!";
    }

    return 0;
}