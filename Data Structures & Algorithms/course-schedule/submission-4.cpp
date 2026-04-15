class Solution {
public:
    void toposort(vector<int> adj[], vector<int>& indegree, 
    int numCourses, vector<int>& res, queue<int>& courses){
        while(!courses.empty()){
            int node = courses.front();
            courses.pop();
            res.push_back(node);
            for(int x : adj[node]){
                indegree[x]--;
                if(!indegree[x]) courses.push(x);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list and indegree list
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        vector<int> res;
        queue<int> courses;

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]); // Here in ques its mentioned that to take course b you need to take course a 
            indegree[it[0]]++;
        }

    // we'll start from the node with indegree 0
        for(int i=0; i<numCourses; i++){
            if(!indegree[i]) courses.push(i);
        }

        toposort(adj,indegree,numCourses,res,courses);
        return res.size() == numCourses;
    }

};
 