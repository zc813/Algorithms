// 巧妙地利用了此矩阵的性质，只需要 O(m+n)

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;
        int y = 0, x = matrix[0].size()-1;
        bool horizontal = false;
        while (x>=0 && y < matrix.size()){
            if (matrix[y][x] == target)
                return true;
            else if (matrix[y][x] > target)
                --x;
            else{
                ++y;
            }
        }
        return false;
    }
};
