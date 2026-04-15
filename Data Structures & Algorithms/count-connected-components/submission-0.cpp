class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis, int node, int parent){
        vis[node] = 1;
        for(int x : adj[node]){
            cout << x << " " << vis[x] << endl;
            if(!vis[x]){
                dfs(adj,vis,x,node);
            }
            // else if(parent != x) return; // we encounter a cycle
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // for(int i=0; i<n; i++){
        //     cout << i << " - - > ";
        //     for(int x : adj[i])
        //         cout << x << " ";
        //     cout << endl;
        // }

        vector<int> vis(n, 0);
        int count = 0; // number of components

        for(int i=0; i<n; i++){
            // cout << vis[i] << " " << i << endl;
            if(!vis[i]){
                count++;
                dfs(adj,vis,i,-1);
            }
        }

        return count;
    }
};
