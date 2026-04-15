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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerecoursesuisites) {
        // adjacency list and indegree list
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        vector<int> res;
        queue<int> courses;

        for(auto it : prerecoursesuisites){
            adj[it[1]].push_back(it[0]); // Here in ques its mentioned that to take course b you need to take course a 
            indegree[it[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(!indegree[i]) courses.push(i);
        }

        toposort(adj,indegree,numCourses,res,courses);
        if(res.size() != numCourses)
            res.resize(0);
    
        return res;
    }
};
