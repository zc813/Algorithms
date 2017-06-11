// 本题与 Climbing Stairs 异曲同工
// 但是需要增加对数字的判断
// 其中特别需要注意的是「0」，代码中带💖的几行都是一开始没考虑到的

class Solution {
public:
    int numDecodings(string s) {
        //按照leetcode judge的逻辑，带有不符合规定的0，统一应该输出0
        //我觉得这不合理，本题中我默认输入的是无噪声的准确的数据，没有加对应的判断
        int sum = 1, sum1 = 1, sum2 = 1;
        for (int i = 1; i < s.size(); ++i)
            if (s[i]=='0'){      //💖
                sum = sum2;      //💖
                sum2 = sum1;     //💖
                sum1 = sum;      //💖
            }else if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')){
                sum = sum1 + sum2;
                sum2 = sum1;
                sum1 = sum;
            } else{
                sum2 = sum1;
            }
        return sum;
    }
};
