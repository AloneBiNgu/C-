// #include <bits/stdc++.h>

// using namespace std;

// int c[10005][10005], f[10005][10005], cf[10005][10005], trace[10005];
// int n, m;

// void buildCF() {
//     for (int u = 1; u <= n; ++u){
//         for (int v = 1; v <= n; ++v){
//             cf[u][v] = 0;
//             if (f[u][v] < c[u][v]) cf[u][v] = c[u][v] - f[u][v];
//             if (f[v][u] > 0) cf[u][v] = f[v][u];
//         }
//     }
// }

// int findPath() {
//     buildCF();
    
//     int s = 1, t = n;
    
//     for (int u = 1; u <= n; ++u) trace[u] = 0;
    
//     queue<int> q;
//     q.push(s);
//     trace[s] = s;
    
//     while (!q.empty()){
//         int u = q.front(); q.pop();
//         for (int v = 1; v <= n; ++v){
//             if (trace[v] == 0 && cf[u][v] > 0){
//                 trace[v] = u;
//                 q.push(v);
//                 if (v == t) return 1;
//             }
//         }
//     }
//     return 0;
// }

// void Flow(){
//     int incVal = INT_MAX;
//     int s = 1, t = n;
//     int v = t;
    
//     while (v != s){
//         int u = trace[v];
//         incVal = min(incVal, cf[u][v]);
//         v = u;
//     }
    
//     v = t;
    
//     while (v != s){
//         int u = trace[v];
//         if (c[u][v] > f[u][v]) f[u][v] += incVal;
//         if (f[v][u] > 0) f[v][u] -= incVal;
//         v = u;
//     }
// }
// int main(){
//     freopen("amaxflow.inp", "r", stdin);
//     freopen("amaxflow.out", "w", stdout);

//     cin >> n >> m;
//     for (int i = 1; i <= m; ++i){
//         int u, v;
//         cin >> u >> v;
//         cin >> c[u][v];
//     }


//     while (findPath()) Flow();
//     int ans = 0;
//     for (int u = 1; u <= n; ++u){
//         ans += f[1][u];
//     }
//     cout << ans << "\n";
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxN = 1e4 + 5;
const long long maxC = 1e9;

int n, m;
int c[maxN][maxN], f[maxN][maxN], cf[maxN][maxN], trace[maxN];

void BuildGraphF() {
    int u, v;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            cf[u][v] = maxC;
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (c[u][v] > 0) {
                if (f[u][v] < c[u][v]) cf[u][v] = c[u][v] - f[u][v];
                if (f[u][v] > 0) cf[v][u] = -f[u][v];
            }
        }
    }
}

bool FindPath(int s, int t) {
    queue<int> q;
    vector<bool> visited(n + 1, false);

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; v++) {
            if (visited[v] == false && cf[u][v] != maxC) {
                trace[v] = u;
                if (v == t) {
                    return true;
                }
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

void IncValue(int s, int t) {
    int u, v, IncValue = maxC;
    v = t;

    while (v != s) {
        u = trace[v];
        if (abs(cf[u][v]) < IncValue) {
            IncValue = abs(cf[u][v]);
        }
        v = u;
    }

    v = t;

    while (v != s) {
        u = trace[v];
        if (cf[u][v] > 0) {
            f[u][v] += IncValue;
        } else {
            f[v][u] -= IncValue;
        }
        v = u;
    }
}

int Solv(int s) {
    int res = 0;

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (c[u][v] > 0) {
                if (u == s) {
                    res += f[s][v];
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("amaxflow.inp", "r", stdin);
    freopen("amaxflow.out", "w", stdout);

    cin >> n >> m;
    
    for (int u = 1; u <= n; u++) {
        trace[u] = 0;
        for (int v = 1; v <= n; v++) {
            f[u][v] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        cin >> c[u][v];
    }

    while (true) {
        BuildGraphF();
        if (FindPath(1, n) == false) break;
        IncValue(1, n);
    }

    cout << Solv(1);
    return 0;
}