class Solution {
public:
    int getSum(int a, int b) {
        unsigned x = a, y = b;        
        while (y != 0) {
            unsigned carry = (x & y) << 1;
            x = x ^ y;
            y = carry;
        }
        return (int)x;
    }
};
