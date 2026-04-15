class Solution {
public:
    bool toposort(vector<int>& vis, vector<int>& currVis, vector<int> adj[], 
    vector<int>& res, int node){
        vis[node] = 1;
        currVis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]){
                if(!toposort(vis, currVis, adj, res, x)){
                    res.resize(0);
                    return false;
                } 
            }
            else if(currVis[x] && vis[x]){
                res.resize(0);
                return false;
            } 
        }
        res.push_back(node);
        currVis[node] = 0;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> vis(numCourses);
        vector<int> currVis(numCourses);
        vector<int> res;

        for(vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(!toposort(vis,currVis, adj, res, i)) return res;
            }
        }
        return res;
    }
};
