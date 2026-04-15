// Here I will keep storing elements in the set until I found a repeated element
// If I find one I won't delete that char for the first time I saw and delete elements before that as well
// Instead I'll just move my first pointer ahead and delete the element first is pointing then moving forward
// Then I'll stay at exact place and I'll try to insert that element again
// If I can't then still there is a duplicate element so I'll again move my first pointer ahead after deleting the element first is pointing to
// This way I am only considering a substring 

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
