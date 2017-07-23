// 根据主定理，时间复杂度为 Ω(log(mn)) O((mn)^(3/4))

class Solution {
private:
    bool inArea(vector<vector<int> >& matrix, int target, int x1, int y1, int x2, int y2){
        if (x1 > x2 || y1 > y2) return false;
        if (matrix[y1][x1] == target || matrix[y2][x2] == target) return true;
        if (x1==x2 && y1==y2) return false;
        if (matrix[y1][x1] > target || matrix[y2][x2] < target) return false;
        int x_mid = (x1 + x2)/2;
        int y_mid = (y1 + y2)/2;
        return inArea(matrix, target, x1, y1, x_mid, y_mid)
            || inArea(matrix, target, x1, y_mid + 1, x_mid, y2)
            || inArea(matrix, target, x_mid + 1, y1, x2, y_mid)
            || inArea(matrix, target, x_mid + 1, y_mid + 1, x2, y2); 
    }
    
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;
        return inArea(matrix, target, 0, 0, matrix[0].size()-1, matrix.size() -1);
    }
};
