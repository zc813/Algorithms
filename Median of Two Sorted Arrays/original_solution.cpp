// 先从 nums1 中用二分法查找，每次同样用二分法找出其在 nums2 的位置，两者相加后与中位 k-th 作比较。
// 当细到 nums1 中已经确定某个元素前/后时，再对 nums2 应用二分法查找到 k-th。
// 啊好蠢！nums1 已经确定元素后，nums2 只要用对应位置减一下就好了啊！！懒得改了233

class Solution {
private:
    int binarySearchValue(vector<int>& nums, int value){
        int i = 0, j = nums.size()-1;
        while (j>=i){
            int p = (i+j)/2;
            if (nums[p] == value) return p;
            else if (nums[p] < value) i = p+1;
            else j = p -1;
        }
        return j;
    }
    
    vector<int>::iterator binarySearchRank(vector<int>& nums1, vector<int>& nums2, int rank){
        int i = 0, j = nums1.size() - 1;
        int p=0, r=0;
        while (j>=i){
            p = (j+i)/2; 
            r = binarySearchValue(nums2, nums1[p]);
            if (p+r+2 == rank) return (nums1.begin() + p);
            else if (p+r+2 < rank) i = p+1;
            else j = p-1;
        }
        if (p+r+2 < rank){
            i = binarySearchValue(nums2, nums1[j]);
            j = (j+1<nums1.size()?binarySearchValue(nums2,nums1[j+1]):nums2.size()-1);
            r = p;
        }else if(p+r+2>rank){
            j = binarySearchValue(nums2, nums1[i]);
            i = (i-1>=0?binarySearchValue(nums2,nums1[i-1]):0);
            r = p-1;
        }
        while (j>=i){
            p = (i+j)/2;
            if (p+r+2 == rank) return (nums2.begin()+p);
            else if (p+r+2<rank) i = p+1;
            else j = p-1;
        }
        return nums1.end();
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0){
            nums1.push_back(nums2[0]);
            nums1.push_back(nums2[nums2.size()-1]);
        }
        if (nums2.size() == 0){
            nums2.push_back(nums1[0]);
            nums2.push_back(nums1[nums1.size()-1]);
        }
        
        if ((nums1.size() + nums2.size()) & 1)
            // odd
            return *(binarySearchRank(nums1,nums2,(nums1.size()+nums2.size())/2 + 1));
        else {
            // even
            int m1 = *(binarySearchRank(nums1,nums2,(nums1.size()+nums2.size())/2));
            int m2 = *(binarySearchRank(nums1,nums2,(nums1.size()+nums2.size())/2+1));
            return (m1+m2)/2.0;
        }
    }
};
