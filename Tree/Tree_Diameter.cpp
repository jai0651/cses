#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(auto i=a; i<b;++i)
#define rrep(i,a,b) for(auto i=a;i>=b;--i)
#define len(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pi pair<int, int>
#define pip pair<int,pi>
#define pl pair<ll,ll>
#define plp pair<ll,pl>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define nl "\n"
#define mod 1000000007

int findDiameterAndMaxPath(vector<vector<int>>& adj, int node, int parent, int& diameter) {
    int max1 = 0, max2 = 0; // Top two longest paths to leaves
    
    for (int child : adj[node]) {
        if (child != parent) {
            int childPath = findDiameterAndMaxPath(adj, child, node, diameter) + 1; // Path to leaf through this child
            
            if (childPath > max1) {
                max2 = max1;
                max1 = childPath;
            } else if (childPath > max2) {
                max2 = childPath;
            }
        }
    }
    
    // Update the diameter (maximum path length passing through the current node)
    diameter = max(diameter, max1 + max2);
    
    return max1; // Return the longest path to a leaf from this node
}

void solve()
{
    int n;cin>>n;
    vector<vi> adj(n+1);
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int diameter=0;
    findDiameterAndMaxPath(adj,1,-1,diameter);
    cout<<diameter<<nl;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

   solve();

    return 0;
}
