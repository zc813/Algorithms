//最开始的思路：如果一个height大于等于它左右的，则成为一个峰，只要对峰和峰之间的水进行计算就好了。
//这种思路忽略了30103的情况。
//之后也要小心这种只和左右比较的算法。
//
//思路二：从左往右，每一个元素找到它右边第一个高于或等于它高度的，将这段的水深累加。如果没有，则找到它右边低于它的最大值，将这段的水深累加。然后从这个点开始继续向右找。
//这种思路可行，但是需要重复计算，最坏情况下复杂度为O(n2)
//（这时其实应该已经要想到通过夹逼来计算了）
//
//思路三：先从左往右，每一个元素找到它右边第一个高于或者等于它高度的，将水深累加，然后从这里出发再继续往右找，直到找不到为止。这时指针位于最高点，记录下来。再从右往左找，同理，将水深累加，一直找到这个最高点为止。
//O(n)，但却重复计算了约半段
//
//思路四：如下

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int i = 0, j = height.size()-1;
        int sum = 0, minh = 0;
        while(i<j){
            minh = min(height[i],height[j]);
            if (minh == height[i])
                while (height[++i] < minh) sum += minh - height[i];
            else
                while (height[--j] < minh) sum += minh - height[j];
        }
        return sum;
    }
};
