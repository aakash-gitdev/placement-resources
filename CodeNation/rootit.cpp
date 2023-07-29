#include<bits/stdc++.h>
using namespace std;



void dfs(int i, int &mx , int &loc, vector<int> adj[], vector<int> &vis , vector<int> &v){
    vis[i] = 1;
    loc += v[i-1];
    mx = max(mx ,  loc);

    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(it , mx, loc, adj, vis, v);
        }
    }

    loc -= v[i-1];
    return;
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n+1 , 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }


    vector<int> adj[n+1];
    

    // for(int i=1;i<=n;i++){
    //     adj[i].first = v[i-1];
    // }
    for(int i=0;i<(n-1);i++){
        int x , y;
        cin >> x >> y;
        // adj[x].first = v[x-1];
        adj[x].push_back(y);
        // adj[y].first = v[y-1];
        adj[y].push_back(x);
    }

    //graph

    vector<int> use(n+1 , 0);

    for(int i=1;i<=n;i++){
        vector<int> vis(n+1 , 0);

        int mx = 0;
        int loc = 0;
        dfs(i , mx, loc, adj, vis, v);
        use[i] = mx;
    }

    
    // for(auto it: use) cout << it << " ";
    for(int i=1;i<=n;i++){
        use[i] -= v[i-1];
    }

    int mxx = 0;

    for(int i=0;i<=n;i++){
        mxx = max(mxx, use[i]);
    }
    cout << mxx <<   endl;


    return 0;
}
