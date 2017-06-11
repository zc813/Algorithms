class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            if (i>0 && nums[i-1] == nums[i])
                nums.erase(nums.begin() + i);
            else
                ++i;
        }
        return nums.size();
    }
};
