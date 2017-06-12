class Solution {
private:
    vector<vector<string>> v;
    
    vector<string> outPut(string subs, int pos){
        vector<string> res;
        if (pos == 0) return {subs};
        for (string word : v[pos])
            for (string child: outPut(word + " " + subs, pos - word.size()))
                res.push_back(child);
        return res;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        v.resize(s.size()+1);
        vector<string> res;
        v[0].push_back("");
        for (int i=0; i<s.size(); ++i)
            if (!v[i].empty())
                for(string word : wordDict)
                    if (s.substr(i, word.size())==word)
                        v[i+word.size()].push_back(word);
                        // 之前是把每个字都加进去，这样不用最后再拼。这个的问题是时间复杂度太高了。请仔细想想，尤其是对于
                        // "aaaaaaaaaaaaaaaaabaaaaaaaaaaaaabaaaaaaaa" ["a","aa","aaa","aaaa","aaaaa"]
                        // 这种 case。时间复杂度是指数级的。
                        // v[i+word.size()].push_back(sub + word + " ");

        res = outPut("", s.size());   // 一直报 runtime error，找不到哪一行，害我以为是 vector<string> 不能递归，后来发现原来参数是 s.size()+1 了
        
        for (auto it_str = res.begin(); it_str != res.end(); ++it_str)
            it_str -> pop_back();
        return res;
    }
};
