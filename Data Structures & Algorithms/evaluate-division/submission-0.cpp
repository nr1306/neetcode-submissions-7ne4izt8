class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string , vector<pair<string,double>> > adj;

        for(int i=0; i<equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b,(double)values[i]});
            adj[b].push_back({a, 1.0/values[i]});
        }

        vector<double> res;
        for(vector<string> q : queries){
            res.push_back(bfs(q[0], q[1], adj));
        }

        return res;
    }

    double bfs(string src, string dest, 
    unordered_map<string , vector<pair<string,double>> >& adj){
        
        if(!adj.count(src) || !adj.count(dest)) return -1.0;
        set<string> vis;

        queue<pair<string, double>> q;
        q.push({src, 1.0});
        vis.insert(src);

        while(!q.empty()){
            auto [node, weight] = q.front();
            q.pop();
            if(node == dest) return weight;

            for(const auto [neighb , neiweight] : adj[node]){
                if(vis.find(neighb) == vis.end()){
                    vis.insert(neighb);
                    q.push({neighb, weight * neiweight});
                }
            }
            
        }
        return -1.0;
    }
};