class Solution {
public:
    long long minEnd(int n, int x) {
         long long ans = x;
        long long add = n - 1;
        for (int i = 0; add > 0; i++) {
            if (((ans >> i) & 1) == 0) {   // if bit i in x is 0
                if (add & 1) ans |= (1LL << i); // fill with bit from add
                add >>= 1;
            }
        }
        return ans;
    }
};