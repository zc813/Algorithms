class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size < 1) return;
        int i = size -1;
        while (i>0 && nums[i]<=nums[i-1]) i--;
        if (i>0){
            int j = i-1;
            while (nums[++j]>nums[i-1] && j < size);
            swap(nums[i-1],nums[j-1]);
        }
        for(int k =i; k<= (size+i-2)/2; ++k)
            swap(nums[k],nums[size-1-(k-i)]);
    }
};
