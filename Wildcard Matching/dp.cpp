class Solution {
public:
	bool isMatch(string s, string ex){
		vector<vector<bool>> res(s.size()+1,vector<bool>(ex.size()+1,false));
		res[0][0] = true;
		for (int i = 0; i <= s.size(); ++i){
			for (int j = 1; j <= ex.size(); ++j){
			    if (ex[j-1] == '*')
			        res[i][j] = res[i][j-1] || (i>0?res[i-1][j]:0);
          // 这里一开始遗漏了 res[i][j] = res[i][j-1] 的情况
          // 所以 string 类的 dp 一开始一定要考虑 a 或者 b 为空的情况
					//if (i > 0 && (s[i-1]==ex[j-2] || ex[j-2] == '.'))
					//	res[i][j] = res[i][j] || res[i-1][j];
				if (i>0)
				    if (ex[j-1]=='?' || ex[j-1] == '*' ||  s[i-1]==ex[j-1])
				        res[i][j] = res[i][j] || res[i-1][j-1];
			}
		}
		return res[s.size()][ex.size()];
	}
};
