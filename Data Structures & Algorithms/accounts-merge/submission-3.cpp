class Solution {
public:
    class DSU{
        vector<int> parent;
        vector<int> rank;
        int components;

        public:

        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            components = n;
            for(int i=0; i<n; i++)
                parent[i] = i;  
        }

        void Union(int u, int v){
            int u_parent = findParent(u);
            int v_parent = findParent(v);

            if(u_parent == v_parent) return;
            if(rank[u_parent] < rank[v_parent])
                parent[u_parent] = v_parent;
            else if(rank[v_parent] < rank[u_parent])
                parent[v_parent] = u_parent;
            else{
                parent[v_parent] = u_parent;
                rank[u_parent]++;
            }
        }

        int findParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU dsu(n);

        map<string, int> mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){

                string str = accounts[i][j];

                if(mp.find(str) != mp.end()){
                    int node1 = mp[str];
                    int node2 = i;
                    dsu.Union(node1, node2);
// will merge if one mail we found overlaps
                }
                else{
                    mp[str] = i;
                }
            }
        }

// Our components are created now - will merge the mails of nodes in single component        

        vector<vector<string>> res(n);
    // Now will merge mails according to ultimate parent

        for(auto [key, value] : mp){
            int ultParent = dsu.findParent(value);
            res[ultParent].push_back(key); 
        }

// Will add the name to merged mail add
        for(int i=0; i<n; i++)
            res[i].insert(res[i].begin(), accounts[i][0]);

// Will remove the components which were compressed - after adding the name their size are aleast 1

        for(int i=0; i<res.size(); i++){
            if(res[i].size() == 1){
                res.erase(res.begin()+i);
                i--;
            } 
        }

        return res;
    }
};