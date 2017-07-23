// exceeds time limit when input consists very long strings.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using std::vector;
using std::unordered_multimap;
using std::unordered_set;
using std::string;

class WordDictionary {
private:
    // [a~z]: each pair <i, j> means in word j, char 'x' appears at position i.
    vector<unordered_multimap<int, int> > words;
    vector<int> lengths;
    
    bool filter(string& word, int pos, unordered_set<int>& set, bool matching = false){
        // no matching result
        if (set.empty() && matching) return false;
        
        // already at the end of the word
        if (pos >= word.size()) return !set.empty() || !matching;
        
        // if '.', move on to the next char
        if (word[pos] == '.') return filter(word, pos + 1, set, matching);
        
        // check result sets
        auto & map = words[word[pos]-97];
        auto range = map.equal_range(pos);
        unordered_set<int> new_set;
        for(auto it = range.first; it != range.second; ++it)
            // if set exists already, then compare and filter current set
            // otherwise build a new set with matching indices of words which are of the same length
            if (set.count(it->second) || (!matching && lengths[it->second] == word.size()))
                new_set.emplace(it->second);        
        return filter(word, pos + 1, new_set, true);     
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        words.resize(26);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        for (int i = 0; i< word.size(); ++i)
            words[word[i]-97].emplace(i, lengths.size());
        lengths.push_back(word.size());
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        string any_string(word.size(), '.');
        if (word == any_string){
            for (int i: lengths)
                if (i == word.size())
                    return true;
            return false;
        }

        unordered_set<int> set;
        return filter(word, 0, set);
    }
};


int main(){
    WordDictionary wd;
    wd.addWord("b");
    wd.addWord("abc");
    std::cout
        << wd.search(".")
        << wd.search("..")
        << wd.search("b.")
        << wd.search("b")
        << wd.search("a..")
        << wd.search("a")
        << wd.search("aa")
        << wd.search("a")
        << wd.search(".a")
        << wd.search("a.")
        << wd.search("ab");
    return 0;
}
