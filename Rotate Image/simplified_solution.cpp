// O(n^2)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n-1; ++row)
            for (int i=0; i<n-row-1; ++i)
                swap(matrix[row][i],matrix[n-i-1][n-row-1]);
        for(int row = 0; row < n >> 1; ++row)
            swap(matrix[row],matrix[n-row-1]);
    }
};
