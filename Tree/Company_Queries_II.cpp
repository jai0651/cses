#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define vi vector<int>

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) {
        if (up[v][i - 1] != -1) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        } else {
            up[v][i] = -1;
        }
    }

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (up[u][i] != -1 && !is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1, -1));
    dfs(root, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;

    adj.resize(n);

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        --x; // Convert to 0-based indexing
        adj[x].push_back(i - 1);
    }

    preprocess(0); // Assuming node 0 is the root

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-based indexing

        int ancestor = lca(a, b);
        cout << (ancestor + 1) << nl; // Convert back to 1-based indexing
    }

    return 0;
}
