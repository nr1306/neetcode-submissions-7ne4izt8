class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> unique;
        int n = s.size(), maxi=0;
        for(int first=0,second=0; first<n && second<n; second++){
            int size = unique.size();
            unique.insert(s[second]);

            if(unique.size() == size){
                auto itr = unique.find(s[first]);
                unique.erase(itr);
                first++;
                second--; // we'll stay on that element and recheck again whether we are able to insert or not
            } 
            
            int updated_size = unique.size();
            maxi = max(maxi, updated_size);
        }
        return maxi;
    }
};
