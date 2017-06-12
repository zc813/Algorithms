// DP. O(mn) time. O(n) space
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
        vector<int> f(t.size()+1,0);
        f[0]=1;
        for (int i = 0; i<s.size(); ++i)
            for (int j= t.size() -1; j>=0; --j)  // 注意这里是反着去加的，避免元素相同时产生的干扰
                if (t[j] == s[i])
                    f[j+1] += f[j];
        return f[t.size()];
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
