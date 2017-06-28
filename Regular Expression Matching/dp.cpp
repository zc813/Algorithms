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
  // 一开始尝试着只用 O(ex)，理论上是可行的，后来实在懒得 debug 了。
	bool isMatch(string& s, string& ex){
		vector<vector<bool>> res(s.size()+1,vector<bool>(ex.size()+1,false));
		res[0][0] = true;
		for (int i = 0; i <= s.size(); ++i){
			for (int j = 1; j <= ex.size(); ++j){
				if (j>1 && ex[j-1] == '*'){
					res[i][j] = res[i][j-2];
					if (i > 0 && (s[i-1]==ex[j-2] || ex[j-2] == '.'))
						res[i][j] = res[i][j] || res[i-1][j];
				}
				if (i>0 && (ex[j-1]=='.' || s[i-1]==ex[j-1])) res[i][j] = res[i][j] || res[i-1][j-1];
			}
		}
		return res[s.size()][ex.size()];
	}
};

int main(){
	Solution sol;

	string s, ex;
	cin >> s >> ex;
	
	cout << sol.isMatch(s,ex) << '\n';
	return 0;
}
