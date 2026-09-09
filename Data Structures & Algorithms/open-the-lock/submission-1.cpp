class Solution {
public:
    void children(string state, vector<string>& child, 
    map<string,bool>& ends){
        for(int i=0; i<4; i++){
            string up = state;
            string down = state;

            up[i] = ( ( (up[i]-'0') + 1) % 10) + '0';
            down[i] = ( ( (down[i]-'0') + 9) % 10) + '0';  
            
            child.push_back(up);
            child.push_back(down);
        }
    }   

    int openLock(vector<string>& deadends, string target) {
        // BFS + create map for deadends and go through every combo
        map<string,bool> ends;
        for(string dead : deadends){
            ends[dead] = true;
        }

        if(ends["0000"] || ends[target]) return -1;
        if(target == "0000") return 0;

        unordered_set<string> vis;
        queue<string> q;
        
        vis.insert("0000");
        q.push("0000"); // initial pos of lock
        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string state = q.front();
                q.pop();

                if(state == target) return steps;

                vector<string> child;
                children(state, child, ends);

                for(string childState : child){
    //checking if childstate is a deadend or it is visited before
                    if(!ends[childState] && !vis.count(childState)){ 
                        vis.insert(childState); // mark it visited
                        q.push(childState);
                    }
                }
                // cout << endl;
            }
            if(!q.empty())
                steps++;
        }

        return -1;
    }
};