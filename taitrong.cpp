#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3 + 5;

int n, m, s, t;

struct Data {
    int v;
    long long w;
};
vector<Data> args[maxN];

struct cmp{
    bool operator()(Data x, Data y){
        return x.w > y.w;
    }
};


bool dijkstra(int s, int t, int k) {
    priority_queue<Data, vector<Data>, cmp> q;
    vector<int> d(n + 1, INT_MAX);
    vector<bool> p(n + 1, false);

    d[s] = 0;
    q.push({s, 0});

    while (!q.empty()) {
        auto top = q.top(); q.pop();

        if (p[top.v] == true) continue;
        p[top.v] = true;

        for (auto u : args[top.v]) {
            if(d[u.v] > d[top.v] + u.w && u.w >= k){
                d[u.v] = d[top.v] + u.w;
                q.push({u.v, d[u.v]});
            }
        }
    }
    if (d[t] == INT_MAX) return false;
    return true;
}

long solv() {
    long l = 0,r = 1e8;
    long ans = 0;

    while(l<=r) {
        long mid = (l + r) / 2;
        if(dijkstra(s, t, mid)){
            l = mid+1;
            ans = mid;
        }
        else r = mid-1;
    }
    return ans;
}


int main() {
    freopen("taitrong.inp", "r", stdin);
    freopen("taitrong.out", "w", stdout);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        args[u].push_back({v, w});
        args[v].push_back({u, w});
    }

    cout << solv() << "\n";
    return 0;
}