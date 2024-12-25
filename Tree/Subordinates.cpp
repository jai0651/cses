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

int findSubOrd(vector<vi>&adj,int &n,vi &ans,int node){
     int sum=0;
     for(auto it:adj[node]){
        sum +=findSubOrd(adj,n,ans,it)+1;
     }

     return ans[node-1]=sum;
}


void solve()
{
    int n;cin>>n;
    vector<vi> adj(n+1);
    int x;
    rep(i,2,n+1){
        cin>>x;
        adj[x].push_back(i);  
    }

    vi ans(n);
    findSubOrd(adj,n,ans,1);

    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<nl;

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
