class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& vis, 
    int node, int parent){
        vis[node] = 1; // mark it as visited
        
        for(int x : adj[node]){
            if(vis[x] == -1){
                if(hasCycle(adj, vis, x, node))
                    return true;
            }
            else if(x != parent) return true; // cycle found
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
    // If there are 0 or only 1 edge
        if(edges.size() <= 1) return true; 

        vector<vector<int>> adj(n);
        for(vector<int> edge : edges){
        // its an undirected graph
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, -1);
        int parent = -1;

// Tree has no disjoint components we are gonna call func once 
// and it would travel every node if its valid true
        if(hasCycle(adj, vis, 0, parent))
            return false; // there is a cycle present

// If every node is not visited then its not a valid tree
        for(int i=0; i<n; i++){
            if(vis[i] == -1) return false;
        }
        return true;
    }
};
