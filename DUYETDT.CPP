#include <bits/stdc++.h>

#define maxN 105

#define fto(i, a, b) for (int i = a; i <= b; ++i)

#define sz(a) (int) a.size()
#define pb push_back
#define pf push_front

using namespace std;

int n, m, k;
vector<int> nxt[maxN];
int avail[maxN];
deque<int> d;

void dfs(int u) {
    cout << u << " ";
    avail[u] = 0;
    fto(i, 0, sz(nxt[u])-1) {
        int v = nxt[u][i];
        if (avail[v]) dfs(v);
    }
}

void bfs(int s) {
    d.pb(s);
    avail[s] = 0;
    while (!d.empty()) {
        int u = d.front(); d.pop_front();
        cout << u << " ";
        fto(i, 0, sz(nxt[u])-1) {
            int v = nxt[u][i];
            if (avail[v]) {
                d.pb(v);
                avail[v] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("DUYETDT.INP", "r", stdin);
    freopen("DUYETDT.OUT", "w", stdout);

    cin >> n >> m >> k;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        nxt[u].pb(v);
        nxt[v].pb(u);
    }

    fto(u, 1, n) sort(nxt[u].begin(), nxt[u].end());

    fto(i, 1, k) {
        int t, u; cin >> t >> u;
        fto(v, 1, n) avail[v] = 1;
        if (t == 1) dfs(u);
        else {
            d.clear();
            bfs(u);
        }
        cout << "\n";
    }

    return 0;
}
