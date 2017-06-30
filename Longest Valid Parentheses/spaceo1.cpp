// Time: O(n)
// Space: O(1)
// 一开始只从左往右扫一遍，只考虑了普通情形，后来发现需要考虑 (()
// 第二版对这种情况，在返回结果时将 max 与 len-depth 进行比较
// 后来发现，需要考虑 ()(()，于是增加了从右往左的扫描，每次扫描后将 max 与 len-depth 进行比较取最大值，并且将两者结果取最小值
// 结果错误，最后把将 max 与 len-depth 进行比较的逻辑去掉，两次扫描结果取最大值
//
// 总结：
// 1. 不应该一上来写代码，而是应该先想全所有的可能。不要想着我先写完 MVP 然后再对测试 case 增补，你整个逻辑都可能是错的。
// 2. 为了解决一种 case，应该多想几种可能的办法，第一感觉未必是最优解。

class Solution {
private:
    struct stacking{
      int start = 0;
      int len = 0;
      int depth = 0;
    } current, max_l,max_r;
public:
    int longestValidParentheses(string s) {
        for (int i = 0; i<s.size(); ++i){
            if (s[i]=='('){
                ++current.depth;
                ++current.len;
            } else if (current.depth > 0){
                --current.depth;
                ++current.len;
                if (current.depth == 0 ){
                    if (current.len > max_l.len) max_l = current;
                }
            } else{
                current.start = i+1;
                current.len = 0;
            }
        }
        //max_l.len = std::max(current.len - current.depth, max_l.len);
        current.len = 0;
        current.depth = 0;
        for (int i = s.size()-1; i>=0; --i){
            if (s[i]==')'){
                ++current.depth;
                ++current.len;
            } else if (current.depth > 0){
                --current.depth;
                ++current.len;
                if (current.depth == 0 ){
                    if (current.len > max_r.len) max_r = current;
                }
            } else{
                current.start = i-1;
                current.len = 0;
            }
        }    
        //max_r.len = std::max(current.len - current.depth, max_r.len);
        return std::max(max_l.len, max_r.len);
    }
};
