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
    string longestPalindrome(string s_og) {
    	if (s_og=="") return "";
    	string s;
    	s.resize(s_og.size()*2);
    	for (int p = s.size()-1; p >=0; p -= 2){
    		s[p] = '\127';
    		s[p-1] = s_og[p>>1];
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
        return s_og.substr(max_i/2-rl[max_i]/2,rl[max_i]+1);
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
