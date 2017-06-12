class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> v(s.size()+1,false);
        v[0] = true;
        for (int i = 0; i<s.size(); ++i)
            if (v[i])
                for (string word : wordDict)
                    if (s.substr(i,word.size())==word)
                        v[i+word.size()] = true;
            /* A reverse version with the same time complexity O(mn):
            for (string word : wordDict){
                int len = word.size();
                int pos = i - len +1 ;
                if(pos >= 0 && v[pos] && s.substr(pos,len) == word){
                    v[i+1] = true;
                    break;
                }
            }*/
            /* O(m*n^2):
            for (int j = 0; j <= i; ++j)
                if (v[j] && find(wordDict.begin(), wordDict.end(), s.substr(j,i-j+1)) != wordDict.end()){
                    v[i+1] = true;
                    break;
                }*/
        return v[s.size()];
    }
};
