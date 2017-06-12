// a naïve solution

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int r=m;
        while (m<n && r) r&=++m;
        return r;
    }
};
