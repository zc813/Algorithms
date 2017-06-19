// 用了 DP 的思路，这个和传统 DP 略有区别，不能通过 F(k) 直接求得 F(k+1)
// 设 F(0, i) 为从 a0 达到 ai 的最短路径长度，则
// F(0, i) = min(F(0, j) + 1), 其中 F(i,j) = 1
// 我先用一个字典保存了从任意 ai 经 1 步可直接达到的 indices
// 然后用地推来拓展 F(0,i) ，直到获取到 F(0,end) 为止

class Solution {
private:
    vector<vector<int>> dict;
    vector<int> route;
    int len = 0;
    int size = 0;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        len = beginWord.size();
        
        wordList.push_back(beginWord);
        size = wordList.size();
        swap(wordList[0],wordList[size-1]);
        route.resize(size,0);
        dict.resize(size);
        int end = -1;

        // 建立索引
        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                if (i == j) continue;
                int diff = 0;
                for (int k = 0; k < len; ++k)
                    if (wordList[i][k] != wordList[j][k]) ++diff;
                if (diff == 1){
                    dict[i].push_back(j);
                }
            }
            if (wordList[i] == endWord) end = i;
        }

        // 字典中无 endWord
        if (end<0) return 0;
        
        // 根据 t 循环，查找能令 F(0，i) = t 的所有 i
        int t = 2;
        bool changed = true;
        set<int> changes, changes_new;
        for (int p : dict[0]){
            route[p] = t;
            changes.insert(p);
        }
        for (; route[end] == 0; ++t, changes = changes_new, changes_new.clear()){
            for (int l : changes){
                for (int p : dict[l])
                    if (route[p] == 0 || route[p] > t + 1){
                        route[p] = t+1;
                        changes_new.insert(p);
                    }
            }
            if (changes_new.empty()) break;
        }
        return route[end];
    }
};
