// string input

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

class Solution {
private:

public:
    string longestPalindrome(string s) {
    	if (s=="") return s;
    	s.resize(s.size()*2);
    	for (int p = s.size()-1; p >=0; p -= 2){
    		s[p] = '\127';
    		s[p-1] = s[p>>1];
    	}
    	int i = 0;
    	int mr = 0;
    	int pos = 0;
    	int max_i = 0;
    	vector<int> rl(s.size());
        for (; i<s.size(); ++i){
        	if (i >= mr || i + rl[2*pos-i] >= mr){
        		int j = (i >= mr ? i + 1: mr + 1);
        		for (; j < s.size() && 2*i-j >= 0 && s[j] == s[2*i-j]; ++j);
        		rl[i] = j-i-1;
        		if (rl[i] > rl[max_i])
        			max_i = i;
        		pos = i;
        		mr = j-1;
        	} else
        		rl[i] = rl[2*pos-i];
        }
        if (s[max_i+rl[max_i]] == '\127') --rl[max_i];
        string res(s.substr(max_i-rl[max_i],rl[max_i] * 2 + 1));
        string res_f;
        res_f.resize((res.size()+1)/2);
        for (int i = 0; i<res.size(); i+=2)
        	res_f[i/2] = res[i];
        return res_f;
    }

	string solve(string& s){
		return longestPalindrome(s);
	}
};

int main(){
	Solution sol;

	string s;
	cin >> s;

	cout << sol.solve(s) << '\n';
	return 0;
}
