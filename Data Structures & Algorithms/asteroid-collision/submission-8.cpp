class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        bool destroyed = false;
        for(int x : asteroids){
            if(st.empty() || x > 0 || (st.top() < 0 && x < 0)){
                st.push(x);
            }
            else{
                int abs_val = abs(x);
                while(!st.empty()){
                    if(st.top() < 0) break;

                    if(abs_val > st.top()){
                        st.pop();
                    }
                    else if(abs_val == st.top()){
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else{
                        destroyed = true;  
                        break;
                    }
                }
                if(!destroyed) st.push(x);
                destroyed = false;
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.insert(res.begin() , st.top());
            st.pop();
        }

        return res;
    }
};