class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int aest : asteroids){
            if(st.empty()){
                st.push(aest);
                continue;
            }
            while(!st.empty() && aest < 0 && st.top() > 0){
                int diff = aest + st.top(); 
                if(diff < 0) st.pop();
                else if(diff > 0) aest = 0;
                else{
                    aest = 0;
                    st.pop();
                }
            }
            if(aest != 0) st.push(aest);
        }
        
        vector<int> res;
        while(!st.empty()){
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};