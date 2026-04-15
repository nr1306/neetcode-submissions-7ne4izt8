class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& vis, int parent,
    int node){
        vis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]) {
                if(!dfs(adj, vis, node, x))
                    return false;
            }
        // we have to ignore x == parent, coz its gonna happen as it is undirected graph where 1 is connected to 3 then in the same cycle 3 will also visit 1 due to edge in both dir
            else if(x != parent) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(vector<int> edge : edges){
        // coz its an undirected graph
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis (n);
        int parent = -1;

    // Valid tree has no cycle
    // Valid tree has no unconnected components
        if(!dfs(adj, vis, parent, 0)) return false;

        for(int i=0; i<n; i++){
            if(!vis[i]) return false; // There are more than 1 component
        }
        return true;
    }
};
