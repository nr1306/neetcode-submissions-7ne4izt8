class Solution {
public:
    bool topoSort(vector<int> adj[], vector<int>& vis,
    vector<int>& currVis, int node, vector<int>& res){
        vis[node] = 1;
        currVis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]){
                if(!topoSort(adj,vis,currVis,x,res)) return false;
            }
            else if(vis[x] && currVis[x]) return false;
        }
        res.push_back(node);
        currVis[node] = 0;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        vector<int> vis(numCourses,0);
        vector<int> currVis(numCourses,0);
        vector<int> res;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(!topoSort(adj,vis,currVis,i,res)){
                    res.resize(0);
                    return res;
                }
            }
        }
        return res;
    }
};
