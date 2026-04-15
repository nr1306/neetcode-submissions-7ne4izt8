class Solution {
public:
    bool topoSort(vector<int> adj[], vector<int>& vis,
    vector<int>& currVis, int node){
        vis[node] = 1;
        currVis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]){
                if(!topoSort(adj,vis,currVis,x)) return false;
            }
            else if(vis[x] && currVis[x]) return false;
        }
        currVis[node] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        vector<int> vis(numCourses,0);
        vector<int> currVis(numCourses,0);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(!topoSort(adj,vis,currVis,i)) return false;;
            }
        }
        return true;
    }
};
