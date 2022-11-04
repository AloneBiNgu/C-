#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 5;

int n, m, Found = 0, cnt;
int arr[1005][1005], x[maxN], Free[maxN], deg[maxN];

void attempt(int u) {
    for (int v = 2; v <= n; v++) {
        if (Free[v] && arr[x[u-1]][v]) {
            x[u] = v;
            if (u == n) {
                if (arr[v][1]) {
                        cnt++;
//                    Found = true;
                    for (int i = 1; i <= n; i++) {
                        cout << x[i] << " ";
                    }
                    cout << "\n";
//                    return;
                }
            } else {
                Free[v] = false;
                attempt(u + 1);
                Free[v] = true;
            }
        }
    }
}

bool check(int deg[]) {
    for (int u = 1; u <= n; u++) {
        if (deg[u] < 2) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("hamil.inp", "r", stdin);
    freopen("hamil.out", "w", stdout);
    cin >> n >> m;

    memset(arr, 0, sizeof(arr));
    memset(deg, 0, sizeof(deg));

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ++arr[u][v];
        ++arr[v][u];
        ++deg[u];
        ++deg[v];
    }

    memset(Free, true, sizeof(Free));
    x[1] = 1;

    if (check(deg)) {
        attempt(2);
        if (cnt == 0) {
            cout << -1;
        }
    } else {
        cout << -1;
    }
    return 0;
}
