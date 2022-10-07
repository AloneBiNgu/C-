#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000005;

int n, m, flag = 1;
int order[maxN], detected[maxN];
bool isVisit[maxN];
vector<pair<int, int>> ans;
vector<int> args[maxN], args2[maxN];

int dfs(int u, int l) {
	isVisit[u] = true;
	order[u] = order[l] + 1;
	detected[u] = order[u];

	for (int v : args[u]) {
		if (v == l) continue;

		if (order[u] < order[v]) continue;
		if (isVisit[v]) {
			detected[u] = min(detected[u], order[v]);
		} else {
			dfs(v, u);
		}
		detected[u] = min(detected[u], detected[v]);
		ans.push_back(make_pair(u, v));
	}
	if (detected[u] == order[u] && l != 0) {
		flag = 0;
	}
	return flag;
}

int main() {

	freopen("oneway.inp", "r", stdin);
	freopen("oneway.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		args[u].push_back(v);
		args[v].push_back(u);
	}

	memset(isVisit, false, sizeof(isVisit));
	
	flag = dfs(1, 0);

	if (flag != 1) {
		cout << 0;
	} else {
		cout << 1 << "\n";
		for (auto it : ans) {
			cout << it.first << " " << it.second << "\n";
		}
	}

	return 0;
}
