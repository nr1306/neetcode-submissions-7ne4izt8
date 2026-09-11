class Solution {
public:
    vector<vector<int>> adj;
    map<int, set<int>> prereqMap;

    set<int> dfs(int crs){
    // If this node is already visited no need to traverse
        if(prereqMap.count(crs)) return prereqMap[crs];
        
        prereqMap[crs] = set<int>(); // initializing the set
        for(int pre : adj[crs]){ // exploring prereq of crs
            auto cur = dfs(pre);
            prereqMap[crs].insert(cur.begin(), cur.end());
    // we are gonna keep combining the set 
        }
        prereqMap[crs].insert(crs); // inserting the character itself
        return prereqMap[crs];
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, vector<int>());
        
        for(vector<int> pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        
        for(int crs=0; crs<numCourses; crs++){
            dfs(crs); // prereqMap is global ds so no need to update it
        }

        vector<bool> res;

        for(vector<int> q : queries){
            set<int> s = prereqMap[q[1]];
            res.push_back(s.count(q[0]));
        }

        return res;

    }
};