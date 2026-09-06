class Solution {
public:
    bool solve(map<char,int>& mp, string& word1, string& word2, 
    int i, int j){
// then second word is smaller clearly - in dictory it is sorted in ascending order
        if(j == word2.size()){ 
            return false;
        }
// If the first word gets finished thats ok
        if(i == word1.size()){ 
            return true;
        }

// If found a mismatch will return from func
// If the first word's char comes after second word's char, return false
// If it is right return true
// If char are same will go ahead and see until we found the mismatch
        if(mp[word1[i]] > mp[word2[j]]) return false;
        else if(mp[word1[i]] < mp[word2[j]]) return true;
        return solve(mp,word1, word2, i+1,j+1);
        
    }

    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for(int i=0; i<order.size(); i++)
            mp[order[i]] = i+1;

        if(words.size() == 1) return true;

        for(int i=0; i<words.size()-1; i++){
            bool res = solve(mp,words[i],words[i+1], 0, 0);
            if(!res) return false;
        }
        return true;
    }
};