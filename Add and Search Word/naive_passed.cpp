class WordDictionary {
private:
    unordered_multimap<int, string> words;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words.emplace(word.size(), word);
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        auto range = words.equal_range(word.size());
        for (auto it = range.first; it != range.second; ++it){
            bool same = true;
            for (size_t pos = 0; pos < word.size(); ++ pos)
                if (word[pos] != '.' && (it->second)[pos] != word[pos]) {
                    same = false;
                    break;
                }
            if (same) return true;
        }
        return false;
    }
};
