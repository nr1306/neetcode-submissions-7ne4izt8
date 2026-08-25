class Solution {
public:
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed){
        vector<pair<int,int>> speed_pos;
        int n = position.size();
        if(n == 1) return 1;

        for(int i=0; i<n; i++){
            speed_pos.push_back({speed[i],position[i]});
        }

        sort(speed_pos.begin(),speed_pos.end(),comp);

        for(pair<int,int> x : speed_pos)
        cout << x.first << " " << x.second << endl;
        
        stack<pair<int,int>> st;
        st.push(speed_pos[0]);

        for(int i=1; i<n; i++){
            if(st.empty()){
                st.push(speed_pos[i]);
                continue;
            }

            double timeCurr = (double)(target-speed_pos[i].second)  / (double)speed_pos[i].first;

            double timeAhead = (double)(target - st.top().second) / st.top().first;

            // cout << timeCurr << " " << timeAhead << endl;

            if(timeCurr <= timeAhead){
                continue; 
// It means this car will catch up to the car ahead and move with same speed as per ahead car
            }
            st.push(speed_pos[i]);

            cout << endl;
            cout << st.top().first << " " << st.top().second << endl;
        }

        return st.size();
    }
};
