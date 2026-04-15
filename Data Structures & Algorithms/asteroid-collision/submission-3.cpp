class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int aest : asteroids){
            if(st.empty()) st.push(aest);
            else if(st.top() < 0 && aest < 0) st.push(aest);
            else if(st.top() > 0 && aest > 0) st.push(aest);
            else if(st.top() < 0 && aest > 0) st.push(aest);
            else{
                while(!st.empty() && 
                (aest < 0 && st.top() > 0) && 
                abs(aest) > abs(st.top())){
                    st.pop();
                }
                if(st.empty() || 
                (aest > 0 && st.top()>0) || 
                (aest < 0 && st.top() < 0)) st.push(aest);
                
                else if(st.top() == abs(aest) && 
                (aest < 0 && st.top() > 0)) st.pop();
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};