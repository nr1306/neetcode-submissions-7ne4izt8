class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& vis,
    int node, int parent){
        vis[node] = 1;
        for(int x : adj[node]){
            if(!vis[x]){
                if(!dfs(adj,vis,x,node)) return false; // cycle found
            // for x node , 'node' will be its parent node
            }
            else if(parent != x) // if x node is already visited and if that node is not the parent node we found a cycle
                return false;
        }
        return true; // no cycle found
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        // we are sending root as -1 as a parent node
        if(!dfs(adj,vis,0,-1)) return false; // we found a cycle
// since its a tree we won't be visiting each node, coz all nodes will be connected to each other
// so we'll just start from 0 node and visit adjacent nodes

        // If any node is unvisited it means there are multiple components, we can say its a graph but not a tree
        // In other words its a forest
        for(int x : vis)
            if(!x) return false;
        
        return true;
        
        
    }
};
