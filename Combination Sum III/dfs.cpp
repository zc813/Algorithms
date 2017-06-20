class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
    int previous = 0;
    void dfs(int numbers, int target){
        if (target == 0 && numbers == 0){
            result.push_back(temp);
            return;
        }
        if (numbers <= 0 || target <= 0) return;
        
        for (int a = previous + 1; a <= 9 && a <= target; ++a){
            previous = a;
            temp.push_back(a);
            dfs(numbers - 1, target - a);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n);
        return result;
    }
};
