class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size();
        int leftMin = 0, leftMax = 0;
// leftMax and leftMin signifies range of possibilities
// leftMax -> Max left parenthesis we can have
// leftMin -> Min left parenthesis, now both could never be negative
// If leftMax becomes negative then there is no way to recover from that.... it would be always invalid parenthesis
// If leftMin is negative will reset back to 0, coz it will only mean that wild char which we are assuming is right parenthesis that hypothesis is wrong
// In valid parenthesis problems also we saw left parenthesis should always be greater than equal to right parenthesis to be a valid str
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
