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
        // If value is set aftr the given timestamp will return 0
        if(timePair[key][0].second > timestamp) return "";

        // If the last latest value is set before the timestamp will return it
        if(timePair[key].back().second <= timestamp)
            return timePair[key].back().first;

        int start = 0, end = timePair[key].size()-1;
        string res;
        while(start <= end){
            int mid = (start+end)/2;
            if(timePair[key][mid].second <= timestamp){
                res = timePair[key][mid].first;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return res;
    }
};
