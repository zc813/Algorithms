class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (i==0 || nums[i-1] != nums[i]){
                ++length;
                nums[length-1] = nums[i]; //这里其实没有必要用 erase
            }
        nums.resize(length);
        return length;
    }
};
