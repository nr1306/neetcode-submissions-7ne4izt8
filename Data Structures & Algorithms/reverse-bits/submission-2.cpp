class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        // What I wanted to do is take 1 from left most place 
        // When I encounter 1 at ith pos from left or 32-i-1 th place
        // I'll add 1th bit to the ith pos from right to ans
        for(int i=0; i<32; i++){
            if(n & 1<<(32-i-1)) ans += 1<<i;
        }
        return ans;
    }
};
