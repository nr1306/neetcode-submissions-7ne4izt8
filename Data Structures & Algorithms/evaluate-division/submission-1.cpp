class Solution {
public:
    double bfs(string& src, string& dest, 
    unordered_map<string, vector<pair<string, double>>>& adj){

        if(!adj.count(src) || !adj.count(dest)) return -1.0;

        queue<pair<string,double>> q;
        set<string> vis;

        q.push({src, 1});
        vis.insert(src);

        while(!q.empty()){
            auto [node, weight] = q.front();
            q.pop();

            if(node == dest) return weight;

            for(auto [nei, neiWeight] : adj[node]){
                if(vis.find(nei) == vis.end()){
                    vis.insert(nei);
                    q.push({nei, weight * neiWeight});
                }
            }
        }

        return -1.0;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        int n = equations.size();
        for(int i=0; i<n; i++){
            vector<string> eq = equations[i];
            adj[eq[0]].push_back({eq[1],values[i]});
            adj[eq[1]].push_back({eq[0], 1.0/values[i]});
        }

        vector<double> res;

        for(vector<string> q : queries){
            res.push_back(bfs(q[0], q[1], adj));
        }

        return res;
    }
};