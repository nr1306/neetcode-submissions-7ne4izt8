class Solution {
public:
    class DSU{
        vector<int> rank;
        vector<int> parent;
        int components;

    public:

        DSU(int n){
            rank.resize(n);
            parent.resize(n,0);
            components = n;

// initializing - every node's parent is node itself in beginning
            for(int i=0; i<n; i++)
                parent[i] = i;
        }
    

        int findParent(int node){
        //path compression
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void Union(int u, int v){

            int u_parent = findParent(u);
            int v_parent = findParent(v);
            
            if(u_parent == v_parent) return;

            if(rank[u_parent] == rank[v_parent]){
// If rank of 2 trees are equal we are attaching entire tree to other
// For that we are changing the ultimate parent of v = ult parent of u
                parent[v_parent] = u_parent;
                rank[u_parent]++;
            }
            else if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else{
                parent[v_parent] = u_parent;
            }

            components--;
        }

        int getComponents(){
            return components;
        }
    };

    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(vector<int> edge : edges){
            dsu.Union(edge[0],edge[1]);
        }
       
        return dsu.getComponents();
    }
};
