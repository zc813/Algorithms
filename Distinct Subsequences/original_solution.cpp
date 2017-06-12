#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::cin;
using std::cout;
using std::vector;
using std::string;

class Solution {
private:
    string s, t;
    int s_len = 0, t_len = 0;
    std::unordered_map<char,vector<int>> hashmap;

    void buildMap(){
        for (int i=0; i<s_len; ++i)
            hashmap[s[i]].push_back(i);
    }
    
    int binaryFind(vector<int>& sorted, int val){
        int i=0, j = sorted.size()-1;
        while (i<=j){   // 忘记了等号！花了至少二十分钟debug
            int mid = (i+j)/2;
            if (sorted[mid] > val)
                j = mid-1;
            else if (sorted[mid] < val)
                i = mid+1;
            else return mid;
        }
        return i;
    }

    int combination(int n, int k){
        if (n < k) return 0;
        if (k > n/2) k = n - k;
        int res=1;
        for (int i = 1; i <=k; ++i) res *= (n-i+1);
        for (int i = 1; i <=k; ++i) res /= i;
        //cout << "C(" << n << ',' << k << ") is " << res <<'\n';
        return res;
    }
    
    int findChar(int start, int i){
        if (start >= s_len) return 0;
        int sum = 0;
        vector<int> char_pos = hashmap[t[i]];
        int j = binaryFind(char_pos, start);
        if (i < t_len - 1){ 
            vector<int> char_pos_next = hashmap[t[i+1]];
            int multi = 0;
            while (j < char_pos.size()){
                int next_char = binaryFind(char_pos_next, char_pos[j]+1);
                if (next_char >= char_pos_next.size()) break;
                int next_j = binaryFind(char_pos,char_pos_next[next_char]);
                sum += (next_j - j) * findChar(char_pos_next[next_char], i+1);
                j = next_j;
            }
            /* 方向错误。如 aabbaabbaa 找 abba，两个 b 可以不在一起。从原始的方案加了这个，花费1小时以上，十分沮丧。
            // 优化 aaaa aaa，寻找下一个不同的字符
            int next_i= i;
            while(next_i < t_len - 1 && t[next_i] == t[next_i+1]) ++next_i;  // 且写成了或，还浑然不觉，debug 20分钟！
            ++next_i;
            if (next_i >= t_len){
                sum += combination(char_pos.size()-j,next_i-i);
                //cout << next_i << ' ' << i << '\n';
            }else {
                vector<int> char_pos_next = hashmap[t[next_i]];
                while (j < char_pos.size()){ // 注意这个循环不能删掉，aabbaa，前面两个a和后面两个a带来的数量是不一样的！
                    // 优化 t 中所寻找下一个要找的字符出现之前的所有相同的 t[i]，如 aaaaaab ab
                    int next_char = binaryFind(char_pos_next, char_pos[j]+1);
                    if (next_char >= char_pos_next.size()) break;
                    int next_j = binaryFind(char_pos,char_pos_next[next_char]);
                    if (next_j-j >= next_i-i)
                        sum += combination(next_j-j,next_i-i) * findChar(char_pos_next[next_char], next_i);
                    j = next_j;
                }
            }
            i = next_i;*/
        } else {
            sum = char_pos.size()-j; // 最开始忘了写这个递归的末端的值，最后无论如何都是 0，花了 5 分钟debug
        }
        return sum;
    }
    
public:
    int numDistinct(string s_, string t_) {
        s = s_;
        t = t_;
        s_len = s.size();
        t_len = t.size();
        buildMap();
        return findChar(0,0);
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
