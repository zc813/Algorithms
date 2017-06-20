class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
    void dfs(vector<int>& candidates, int target){
        if (target == 0){
            result.push_back(temp);
            return;
        }
        for (int a : candidates){
            if (a > target || (!temp.empty() && a < *(temp.end()-1))) continue;
            temp.push_back(a);
            dfs(candidates,target - a);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target);
        return result;
    }
};
