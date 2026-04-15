class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& vis, int parent, int node){
        vis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]){
                if(!dfs(adj,vis,node,x)) continue;
            }
        }
        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n);
        int parent = -1;

// How many times we are calling dfs() it will determine the number of components in the graph
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj,vis,parent,i);
                count++;
            }
        }
        return count;
    }
};
