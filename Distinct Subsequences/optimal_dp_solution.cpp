// DP. O(mn) time. O(m) space
//
// f(i,j) = f(i-1,j) , T[j] =/= S[i]
//          f(i-1,j-1) + f(i-1,j) , T[j] == S[i]

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::string;

class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        vector<int> f(s_len,1);
        int tmp1 = 1, tmp2;
        for (int j = 0; j<t_len; ++j){
            for (int i=0; i<s_len; ++i){
                tmp2 = f[i];
                f[i] = (i==0 ? 0 : f[i-1]) + (s[i]==t[j] ? tmp1 : 0);
                tmp1 = tmp2;
            }
            tmp1 = 0;  // 之前忘了加这一句
        }
        return f[s_len-1];
    }
};

int main(){
    string s, t;
    cin >> s >> t;
    Solution solution1;
    int res = solution1.numDistinct(s,t);
    cout << "RESULT: " << res << '\n';
    return 0;
}
