class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size();
        int leftMin = 0, leftMax = 0;

        for(int i=0; i<size; i++){
            if(s[i] == '('){
                leftMax++;
                leftMin++;
            } 
            else if(s[i] == ')'){
                leftMax--;
                leftMin--;
            }
            else{
                leftMax++;
                leftMin--;
            }
            if(leftMax < 0) return false;
            if(leftMin < 0) leftMin = 0;
        }
        if(0 >= leftMin && 0<= leftMax) return true;
        return false;
    }
};
