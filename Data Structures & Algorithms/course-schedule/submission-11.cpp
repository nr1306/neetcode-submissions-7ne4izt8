class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, 
    int node, int parent){

        for(int x : adj[node]){
            if(vis[x] == -1){
                vis[x] = 1;
                if(dfs(adj, vis, x, node)) return true;
            }
            else if(vis[x] == 1) return true;
        }
        vis[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(!prerequisites.size()) return true;
        if(prerequisites.size() == 1) 
            return prerequisites[0][0] != prerequisites[0][1];
        
        vector<vector<int>> adj(numCourses);
        for(vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> vis(numCourses, -1);
        for(int i=0; i<numCourses; i++){
            int parent = -1;

            if(vis[i] == -1){
                vis[i] = 1;
                if(dfs(adj, vis, i, parent)) return false;
            }
        }
        return true;
    }
};
