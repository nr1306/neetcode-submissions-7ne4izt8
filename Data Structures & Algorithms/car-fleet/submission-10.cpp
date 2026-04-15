class Solution {
public:
    static bool comparator(pair<int,int>& a, pair<int,int>& b){
        return a.first < b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pos_sp;
        int n = position.size();
        for(int i=0; i<n; i++){
            pos_sp.push_back({position[i] , speed[i]});
        }

    // sorted cars according to their position
        sort(pos_sp.begin(), pos_sp.end(), comparator);
        cout << pos_sp[0].first << " " << pos_sp[0].second;
        stack<pair<int,int>> st;
        st.push(pos_sp.back()); // We'll start from Furthest car 

        for(int i=n-2; i>=0; i--){
            pair<int,int> before = pos_sp[i];
            pair<int,int> ahead = st.top();

            double ahead_car_time = (target-ahead.first)/(double)ahead.second;
            double before_car_time = (target-before.first)/(double)before.second;
            
            if(before_car_time <= ahead_car_time){
                // before.second = ahead.second;
                continue; // It meanss when behind car will reach ahead car, then they will move at ahead car values
                // so no need to update just the speed of before car
            }
            st.push(before);
        }

        return st.size();
    }
};
