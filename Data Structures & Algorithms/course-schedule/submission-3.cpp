class Solution {
public:
    bool dfs(vector<int>& vis, vector<int>& currVis, 
    vector<vector<int>> &adj, int node){
        vis[node] = 1;
        currVis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]){
                if(dfs(vis,currVis,adj,x)) return true; // found cycle
            }
            else if(vis[x] && currVis[x]) return true;
            // We found 2 nodes which are having an edge between each other
            // It means we found a cycle;
        }

        currVis[node] = 0;
        return false; // cycle not found
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list 
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();

        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> currVis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(vis, currVis, adj, i)) // found cycle
                    return false; // we can't take all courses
            }
        }
        return true;
    }
};
 