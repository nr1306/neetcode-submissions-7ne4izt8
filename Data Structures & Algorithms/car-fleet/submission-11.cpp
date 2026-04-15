class Solution {
public:
// sorting in decreasing order of their positions
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        return b.second < a.second;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> speed_pos;
        int n = position.size();

        for(int i=0; i<n; i++){
            speed_pos.push_back({speed[i], position[i]});
        }

        sort(speed_pos.begin(), speed_pos.end(), comp);
        
        stack<pair<int,int>> st;
        for(pair<int,int> sp : speed_pos){
            if(st.empty()){
                st.push(sp);
                continue;
            }

            pair<int,int> ahead = st.top();
            double time1 = (double)(target-ahead.second)/ahead.first;
            double time2 = (double)(target-sp.second)/sp.first;

            if(time2 > time1){
                st.push(sp);
            }
        }

        return st.size();
    }
};
