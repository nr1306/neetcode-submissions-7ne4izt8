class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> lastPos;
        for(int i=0; i<s.size(); i++){
            lastPos[s[i]] = i;
        }
        
        int farthest = 0;
        int start = 0;
        vector<int> res;
        for(int i=0; i<s.size(); i++){
            farthest = max(farthest , lastPos[s[i]]);
            if(i == farthest){
                res.push_back(farthest-start+1);
                start = i+1;
            }
        }
        return res;
    }
};
