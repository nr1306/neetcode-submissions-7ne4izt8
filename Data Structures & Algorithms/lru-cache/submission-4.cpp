class LRUCache {
public:
    vector<pair <pair<int,int>, int> > ele;
    int size = -1;
    int ttl = 0;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        ttl++;
        for(int i=0; i<ele.size(); i++){
            pair<int,int> key_value = ele[i].first;
            if(key_value.first == key){
                ele[i].second = ttl;
                ele.push_back(ele[i]);
                ele.erase(ele.begin()+i);
                return key_value.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        ttl++;
        for(int i=0; i<ele.size(); i++){
            pair<int,int> key_value = ele[i].first;
            if(key_value.first == key){
                ele[i].first.second = value;
                ele[i].second = ttl;
                ele.push_back(ele[i]);
                ele.erase(ele.begin()+i);
                return;
            }
        }
        
        if(ele.size() == size){
            ele.erase(ele.begin());
            pair<int,int> key_value = {key,value};
            ele.push_back({key_value,ttl});
        }
        else{
            pair<int,int> key_value = {key,value};
            ele.push_back({key_value,ttl});
        }
    }
};
