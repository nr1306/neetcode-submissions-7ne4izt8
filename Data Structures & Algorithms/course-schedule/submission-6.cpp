class Solution {
public:
    bool solve(vector<int> adj[], vector<int>& vis, 
    vector<int>& currVis, int node){
        vis[node] = 1;
        currVis[node] = 1;

    // we'll go though the prerequisites
        for(int x : adj[node]){
            if(!vis[x]){
                if(!solve(adj, vis, currVis, x)) return false;
            }
            else if(currVis[x] && vis[x]) return false;
        }
        currVis[node] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // creating adjacency list
        vector<int> adj[numCourses];
        for(vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> vis(numCourses);
        vector<int> currVis(numCourses);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                bool cycle = solve(adj, currVis, vis, i);
                if(!cycle) return false;
            }
        }
        return true;
    }
};
