class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size() , len2 = word2.size();

        if(len1 >= len2){ // when word1 is longer than word1
            for(int i=0,j=1;  i<len2; i++){
                word1.insert(word1.begin()+j, word2[i]);
                j+=2;
            }

            return word1;
        }
        else{ // word2 len is bigger
            for(int i=0,j=0; i<len1 ; i++){
                word2.insert(word2.begin()+j, word1[i]);
                j+=2;
            }

            return word2;
        }
        return "";
    }
};