class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(int x : hand) mp[x]++;

        int n = hand.size();
        if(n % groupSize != 0) return false;

        for(auto itr : mp){
            int freq = itr.second; // will exhaust the freq of min element and will check if hands are straight or not if not return false
            while(freq--){
                int size = 0;
                int ele = itr.first; // checking if [ele, ele+groupSize] elements are there or not
                while(mp[ele]){
                    mp[ele]--;
                    ele++;
                    size++;
                    if(size == groupSize) break;
                }
                if(size != groupSize) return false; // if straight hand grp can't be formed
            }
        }

        return true;
    }
};
