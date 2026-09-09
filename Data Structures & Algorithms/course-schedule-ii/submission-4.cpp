class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, 
    vector<int>& res, int node){
        for(int x : adj[node]){
            if(vis[x] == 0){
                vis[x] = 1;
                if(dfs(adj,vis,res,x)) return true;
            }
            else if(vis[x] == 1) return true;
        }
        vis[node] = 2;
        res.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
// Here we are storing like these are prerequisites of this element
// We have to finish all prereq first inorder to take this course
// If we store it reverse way then it makes oppo sense
        }

        vector<int> vis(numCourses,0);
        vector<int> res;

        for(int i=0; i<numCourses; i++){
            if(vis[i] == 0){
                vis[i] = 1;
                if(dfs(adj, vis, res, i)){
                    res.resize(0);
                    return res;
                }
                    
            }
        }
        return res;
    }
};
