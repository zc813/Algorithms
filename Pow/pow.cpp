class Solution {
private:
    double runPow(double x, long n){
        if (n==1) return x;
        double tmp = myPow(x, n >> 1);
        return tmp * tmp * (n & 0x1 ? x : 1);
    }
    
public:
    double myPow(double x, long n) {
        if (n==0) return 1;
        if (n<0) return runPow(1.0/x, -n);
        return runPow(x,n);
    }
};
