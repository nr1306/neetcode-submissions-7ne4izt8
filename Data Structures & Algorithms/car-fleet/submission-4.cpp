class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> st;
        int n = position.size(),count = 0;
        vector<pair<int,int>> pos_speed;
        
        for(int i=0; i<n; i++){
            pair<int,int> curr = {position[i],speed[i]};
            pos_speed.push_back(curr);
        }
        // sorted the position,speed pair by position in descending order
        sort(pos_speed.begin(),pos_speed.end(),greater<pair<int,int>>());
        
        for(int i=0; i<n; i++){
            pair<int,int> currCar = pos_speed[i];
            
            if(!st.empty()){
                pair<int,int> temp = st.top();
                double time1 = double(target-temp.first)/double(temp.second);
                double time2 = double(target-currCar.first)/double(currCar.second);

                if(!st.empty() && time2 > time1){ // when they won't collide
                        count++;
                        st.pop();
                }
                else
                    continue; // then the latest car will be collided and that car is already inserted so we won't insert it again
            }
            st.push(currCar);
        }
        if(!st.empty()) count++;
        return count;
    }
};
