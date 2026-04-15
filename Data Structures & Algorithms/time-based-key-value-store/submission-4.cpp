class TimeMap {
public:
    map<string, vector<pair<string,int>> > timePair;
    TimeMap() {
        
    }

    static bool comp(const pair<string,int>& a, const int timestamp){
        return a.second < timestamp;
    }

    void set(string key, string value, int timestamp) {
        if(timePair[key].size() == 0){
            timePair[key].push_back({value,timestamp});
        }
        else{
            auto itr = lower_bound(timePair[key].begin(), 
                        timePair[key].end(), timestamp, comp);
            
            if(itr == timePair[key].end()) 
                timePair[key].push_back({value,timestamp});
            else{
                int ind = itr - timePair[key].begin();
                timePair[key].insert(timePair[key].begin() + ind, 
                                    {value,timestamp});
            }
        }
    }
    
    string get(string key, int timestamp) {
        if(timePair[key].size() == 0) return "";

        int n = timePair[key].size();
        for(int i=n-1; i>= 0; i--){
            if(timePair[key][i].second <= timestamp)
                return timePair[key][i].first;
        }
        return "";
    }
};
