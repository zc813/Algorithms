// O(n^2)
// 左元素穷举，中间和右侧夹逼

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if(nums.size() < 3) return results;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-2;++i){
            if (i>0 && nums[i-1] == nums[i]) continue;
            int mid = i+1, right = nums.size()-1;
            int sum = -nums[i];
            while(mid < right){
                if(nums[mid]+nums[right]>sum)
                    --right;
                else if (nums[mid]+nums[right] < sum)
                    ++mid;
                else{
                    int tmp_mid = nums[mid], tmp_right = nums[right];
                    results.push_back({nums[i],tmp_mid,tmp_right});
                    while(nums[--right]==tmp_right);
                    while(nums[++mid]==tmp_mid);
                }
            }
        }
        return results;
    }
};
