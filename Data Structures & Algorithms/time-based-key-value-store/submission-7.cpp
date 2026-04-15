class TimeMap {
    map<string, vector< pair<string, int> >> timePair;
public:
    TimeMap() {
        
    }
    static bool comp(pair<string,int>&a , int timestamp){
        return a.second < timestamp;
    }

    void set(string key, string value, int timestamp) {
        if(timePair[key].size() == 0){
            timePair[key].push_back({value,timestamp});
            return;
        }
        
        auto itr = lower_bound(timePair[key].begin(), 
        timePair[key].end(), timestamp , comp);

        if(itr == timePair[key].end()) 
            timePair[key].push_back({value,timestamp});
        else{
            int ind = itr - timePair[key].begin();
            timePair[key].insert(timePair[key].begin()+ind, {value,timestamp});
        }
    }
    
    string get(string key, int timestamp) {
        if(timePair[key].size() == 0) return "";

        if(timePair[key][0].second > timestamp) return "";
        if(timePair[key].back().second <= timestamp) 
            timePair[key].back().first;
        
        int start = 0, end = timePair[key].size()-1;
        int res = -1;
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(timePair[key][mid].second <= timestamp){
                res = mid;
                start = mid+1;
            }
            else end = mid-1;
        }
        if(res == -1) return "";
        return timePair[key][res].first;
    }
};
