// DP. O(mn) time and space
//
// f(i,j) = f(i-1,j) , T[j] =/= S[i]
//          f(i-1,j-1) + f(i-1,j) , T[j] == S[i]

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        int f[t_len+1][s_len+1];
        for (int i = 0; i<=s_len; ++i)
            f[0][i] = 1;
        for (int j = 1; j<=t_len; ++j)
            f[j][0] = 0;
        for (int j = 1; j<=t_len; ++j)
            for (int i=1; i<=s_len; ++i){
                if (s[i-1]==t[j-1])
                    f[j][i] = f[j][i-1] + f[j-1][i-1];
                else
                    f[j][i] = f[j][i-1];
            }
        return f[t_len][s_len];
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
