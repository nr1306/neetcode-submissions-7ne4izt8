class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        if(t.size() > s.size()) return "";

        map<char,int> freq; // will store the freq of char in t string
        for(char ch : t) freq[ch]++;
        int tsz = t.size(); 
// we'll use both freq and tsz to determine whether we have all elements of t in our window or not

        int count = 0; // to keep track of how many elements of t we found
        int minlen = INT_MAX;
        int start = -1; // will keep track of starting index of minimum valid window containing all elements from t

        for(int i=0,j=0; j<s.size(); j++){
            char ch = s[j]; 
            if(freq[ch] > 0){
                count++;
            }
            freq[ch]--; // we are reducing the freq of every element
// Non t string elements will have negative freq and will become 0 when they are removed from the window
            
            while(i<=j && count == tsz){ // if we have found all the elements of t
                // will update the size of this valid wind
                if(j-i+1 < minlen){
                    start = i;
                    minlen = min(minlen, j-i+1);
                }

                // will shrink the window till we can
                freq[s[i]]++;
                if(freq[s[i]] > 0){ 
                    count--; // It means we have removed a element of t string from window (due to shrinking)
                }
                i++;
            }
        }
        if(start == -1) return "";
        return s.substr(start, minlen);
    }
};
