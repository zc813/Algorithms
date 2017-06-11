// 由外到内一圈一圈地旋转，时间复杂度 O(n)，空间复杂度 O(1)
// 看到一种算法是先沿着左下-右上对角线翻折一次，再沿着水平中轴线翻转一次。多循环了一次，复杂度并没减少，但可以参考。

class Solution {
private:
    int get(vector<vector<int>>& matrix, int x, int y){
        return matrix[y][x];
    }
    void passon(vector<vector<int>>& matrix,int size, int x, int y){
        matrix[x][size-y-1] = matrix[y][x];
    }
    void passon_v(vector<vector<int>>& matrix,int size, int x, int y, int value){
        matrix[x][size-y-1] = value;
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n >>1; ++row){
            for (int i=row; i<n-row-1; ++i){  // 这里原先忘了写 -1，使角落上的都多旋转了一次！
                int temp = get(matrix,n-row-1,i);
                passon(matrix,n,i,row);
                passon(matrix,n,row,n-i-1);
                passon(matrix,n,n-i-1,n-row-1);
                passon_v(matrix,n,n-row-1,i,temp);
            }
        }
    }
};
