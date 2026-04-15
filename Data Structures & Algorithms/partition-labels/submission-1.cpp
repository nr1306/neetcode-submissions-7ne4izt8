class Solution {
public:
    vector<int> partitionLabels(string s) {
        queue<char> q;
        map<char, int> lastPos;
        for(int i=0; i<s.size(); i++) lastPos[s[i]] = i;

        int farthest = 0;
        int start = 0;
        vector<int> res;
    // I thought of storing the freq of elements and then I'll store them in queue
    // I'll move forward untill all freq of char in queue gets 0
    // It was making me iterate over elements multiple times

    // Optimal approach was I stored the last position of all elements
    // And I'll keep track of farthest element in current substring , I'll move till that index
    // When I reach there, I'll insert the length of substr into res and update the start pos
    
        for(int i=0; i<s.size(); i++){
            farthest = max(farthest, lastPos[s[i]]);
            if(i == farthest){
                res.push_back(farthest - start + 1);
                start = i+1;
            }
        }
        return res;
    }
};
