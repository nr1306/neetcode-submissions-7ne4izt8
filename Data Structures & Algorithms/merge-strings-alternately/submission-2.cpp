class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i = 1, j = 0;
        int n2 = w2.size();

        while(i<w1.size() && j<n2){
            w1.insert(w1.begin()+i , w2[j]);
            i+=2;
            j++;
        }

        if(j<n2) w1.append(w2.substr(j, n2-j+1));

        return w1;
    }
};