class Solution{
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int sum = 0, sum_j = 0;
        int j = 0, h_j = height[j], peak = 0;
        for (int i = 1 ; i<height.size() ; ++i)
            if (height[i] >= h_j){
                sum += h_j * (i-j-1) - sum_j;
                sum_j = 0;
                j = i;
                h_j = height[j];
            } else sum_j += height[i];
        peak = j;
        j = height.size() - 1;
        h_j = height[j];
        sum_j = 0;
        for (int i = j-1; i >= peak; --i)
            if (height[i] >= h_j){
                sum += h_j * (j-i-1) - sum_j;
                sum_j = 0;
                j = i;
                h_j = height[j];
            } else sum_j += height[i];
        return sum;
    }
};
