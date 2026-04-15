class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // will create speed,pos pair
        // sort according to pos
        // then will check is this car will crash (create a fleet or not)

        vector<pair<int,int>> ps;
        for(int i=0; i<speed.size(); i++){
            ps.push_back({position[i],speed[i]});
        }

        sort(ps.begin(), ps.end(), greater<pair<int,int>>());

        stack<pair<int,int>> st;
        st.push(ps[0]);
        int n = ps.size();

        int res = ps.size();
        for(int i=1; i<n; i++){
            pair<int,int> speedpos = st.top();
            double behindCarTime = ((double)target-ps[i].first)/ps[i].second;
            double aheadCarTime = ((double)target-speedpos.first)/speedpos.second;
            
            if(aheadCarTime >= behindCarTime) // It means behind car will form a fleet with car ahead of it
            {
        // Since behind car will reach the ahead car then ahead car is already in the stack, no need to pop or add any car
        // If ahead car is faster than behind car then we would have pushed that car into stack
                continue;
            }
            st.push(ps[i]);
        }
        return st.size();
    }
};
