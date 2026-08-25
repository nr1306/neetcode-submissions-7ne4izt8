class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> state;
        int n = asteroids.size();

        for(int i=0; i<n; i++){
            if(state.empty()){
                state.push(asteroids[i]);
                continue;
            }
            int top = state.top();
            int curr = asteroids[i];
            bool destroyed = false;

            while(!state.empty() && curr < 0 && top > 0){
                if(abs(curr) > top){
                    state.pop();
                }
                else if(abs(curr) == top){
                    destroyed = true;
                    state.pop();
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
                if(!state.empty())
                    top = state.top();
            }
            if(!destroyed) state.push(curr);
        }
        vector<int> res;
        while(!state.empty()){
            res.insert(res.begin(), state.top());
            state.pop();
        }
        return res;
    }
};