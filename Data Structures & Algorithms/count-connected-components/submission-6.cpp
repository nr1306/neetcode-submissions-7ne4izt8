class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis){
        vis[node] = 1;
        for(int child : adj[node]){
            if(!vis[child])
                dfs(adj,child,vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;

        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, i, vis);
// number of times we are gonna do dfs = number of components we have
                count++; 
            }
        }
        return count;
    }
};
