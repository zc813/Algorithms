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
        // 由于已经是降序排序，所以只要 reverse 就好，不需要 sort
        reverse(nums.begin()+i,nums.end());
        //for(int k =i; k<= (size+i-2)/2; ++k)
        //    swap(nums[k],nums[size-1-(k-i)]);
    }
};
