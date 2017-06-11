class Solution {
private:
    string getDigit(vector<int>& a, int k){
        if (a.size()==1) return to_string(a[0]);
        int f = 1;
        for(int i=a.size()-1; i>1; --i) f*=i;
        int digit = a[k / f];
        a.erase(a.begin() + k/f);
        // return digit * 10 + getDigit(a,k % f); 实际上乘以十达不到递归的目的，最后所有数字会挤在十位上。这里以后要小心！
        return to_string(digit) + getDigit(a,k % f);
    }
    
public:
    string getPermutation(int n, int k) {
        vector<int> a(n);
        for (int i = 1; i<=n; ++i) a[i-1] = i;
        return getDigit(a, k-1);
    }
};
