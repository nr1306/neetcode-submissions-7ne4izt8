class Solution {
    class DSU{
        vector<int> rank, parent;
        public:
            DSU(int n){
                rank.resize(n+1,0);
                parent.resize(n+1);
                for(int i=0; i<=n; i++){
                    parent[i] = i;
                }
            }

            int Find(int x){ // this function will return ultimate parent of x node
                if(parent[x] == x) return x; // If node is equal to its parent node it means its the root node
                return parent[x] = Find(parent[x]); // This initialization will ensure path compression
            }

            void Union(int u, int v){
                int u_parent = Find(u); // ultimate parent of u
                int v_parent = Find(v);
                if(u_parent == v_parent) // if they belong to same component means if they have same parent
                    return;

                if(rank[u_parent] < rank[v_parent])
                    parent[u_parent] = v_parent;
                else if(rank[v_parent] < rank[u_parent])
                    parent[v_parent] = u_parent;
                else{
                    parent[v_parent] = u_parent;
                    rank[u_parent]++;
                }
            }
    };

public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> cyclic_edge(2);
        DSU dsu(n);
        for(int i=0; i<n; i++){
            if(dsu.Find(edges[i][0]) == dsu.Find(edges[i][1])){
                cyclic_edge[0] = edges[i][0];
                cyclic_edge[1] = edges[i][1];
            }
            else{
                dsu.Union(edges[i][0], edges[i][1]);
            }
        }
        return cyclic_edge;
    }
};
