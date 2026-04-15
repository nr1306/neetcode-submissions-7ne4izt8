class Solution {
public:
    class DSU{
        vector<int> parent;
        vector<int> rank;
        public:
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0; i<=n; i++) parent[i] = i;
        }

        int Find(int node){
            if(node == parent[node]) return node;
            return parent[node] = Find(parent[node]);
        }

        void Union(int u, int v){
            int u_parent = Find(u);
            int v_parent = Find(v);
            if(u_parent == v_parent) return; // Both nodes are  part of same component
            if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else if(rank[v_parent] < rank[u_parent]){
                parent[v_parent] = u_parent;
            }
            else parent[v_parent] = u_parent;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        vector<int> cyclic_edge(2);
        for(auto edge : edges){
            int parent1 = dsu.Find(edge[0]);
            int parent2 = dsu.Find(edge[1]);
            if(parent1 == parent2){
                cyclic_edge[0] = edge[0];
                cyclic_edge[1] = edge[1];
            }
            else{
                dsu.Union(edge[0],edge[1]);
            }
        }
        return cyclic_edge;
    }
};
