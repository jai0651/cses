#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define vi vector<int>

void dfs(int v, int p, vector<vi>& up, vector<vi>& adj) {
    up[v][0] = p; // Direct parent of the node
    for (int i = 1; i <= 31; ++i) {
        if (up[v][i - 1] != -1) {
            up[v][i] = up[up[v][i - 1]][i - 1]; // Precomputing 2^i-th ancestor
        } else {
            up[v][i] = -1; // No ancestor at this level
        }
    }

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, up, adj);
        }
    }
}

int findKthAncestor(int a, int k, vector<vi>& up) {
    for (int i = 0; i < 32 && a != -1; ++i) {
        if (k & (1 << i)) { // Check if the i-th bit in k is set
            a = up[a][i]; // Move to the 2^i-th ancestor
        }
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vi> adj(n + 1);
    vector<vi> up(n + 1, vi(32, -1)); // Initialize ancestor table with -1

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1, -1, up, adj); // Start DFS from root (node 1)

    while (q--) {
        int a, k;
        cin >> a >> k;

        int ancestor = findKthAncestor(a, k, up);
        cout << ancestor << nl;
    }

    return 0;
}
