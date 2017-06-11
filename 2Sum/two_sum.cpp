// hashmap 没啥好说的

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for (int i = 0; i<nums.size(); ++i){
            auto iter = map.find(nums[i]);
            if (iter != map.end())
                return {iter->second,i};
            map[target - nums[i]]=i;
        }
        return {};
    }
};
