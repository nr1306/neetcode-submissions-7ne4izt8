class Solution {
public:
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

        int Find(int node){
        // we reach till ultimate parent
            if(node == parent[node]) return node; 
            return parent[node] = Find(parent[node]);
        }

        void Union(int u, int v){
    // Finding ultimate parent of nodes
            int u_parent = Find(u);
            int v_parent = Find(v);

// If they have same ultimate parent - they are part of same component
            if(u_parent == v_parent) return; 

// Lower rank node will connect higher rank node
            if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else if(rank[v_parent] < rank[u_parent]){
                parent[v_parent] = u_parent;
            }
            else{
    // If they are of same rank will connect either of them to other
                parent[v_parent] = u_parent;
                rank[u_parent]++;
            }
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        vector<int> res(2);

        for(vector<int> edge : edges){
            int parent1 = dsu.Find(edge[0]);
            int parent2 = dsu.Find(edge[1]);

        // If before connecting this edge checking parents of both
            if(parent1 == parent2){
                res[0] = edge[0];
                res[1] = edge[1];
                break;
            }
            else
                dsu.Union(edge[0], edge[1]);
        }
        return res;
    }
};
