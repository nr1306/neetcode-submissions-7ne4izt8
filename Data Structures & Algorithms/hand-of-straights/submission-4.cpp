class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        if(groupSize == 1) return true;

        map<int,int> mp;
        for(int x : hand) mp[x]++;

        for(auto [key, freq] : mp){
            if(freq == 0) continue;
            while(freq--){ // why we are doing this coz minimum element will be the first element in group until its freq is non-zero, we are exhausting freq of small element 
                for(int i=key; i<key+groupSize; i++){
                    if(mp[i] == 0) return false; 
// If we are starting from 1 then we must need 2 and 3, if any of these key's freq is 0 it means grouping is not possible

                    //else decrease the freq
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
