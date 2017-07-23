// Longest Consecutive Sequence
// Using disjoint set
//
// Zhenbang Chen
// Sun, Jul 23, 2017

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

class Solution{
private:
	unordered_map<int, size_t> index;
	vector<size_t> parent;
	vector<int> size;

	size_t group(size_t x){
		if (parent[x] != x)
			return parent[x] = group(parent[x]);
		return x;
	}

	void merge(size_t a, size_t b){
		if (a >= parent.size() || b >= parent.size()) return;
		int group_a = group(a), group_b = group(b);
		if (group_a == group_b) return;
		if (size[group_a] <= size[group_b]){
			parent[group_a] = group_b;
			size[group_b] += size[group_a];
		} else {
			parent[group_b] = group_a;
			size[group_a] += size[group_b];
		}
	}

	size_t indexof(int n){
		if (index.count(n)) return index[n];
		return -1;
	}

public:
    int longestConsecutive(vector<int>& nums) {
    	// initialization
        parent.resize(nums.size());
        size.resize(nums.size());
        for (size_t i = 0; i < nums.size(); ++i){
        	index[nums[i]] = i;
        	parent[i] = i;
        	size[i] = 1;
        }

        // merge disjoint sets
        for (auto iter = nums.begin(); iter != nums.end(); ++iter){
        	merge(indexof(*iter + 1), indexof(*iter));
        	merge(indexof(*iter - 1), indexof(*iter));
        }

        // find maximum size
        int max_size = 0;
        for (auto iter = size.begin(); iter != size.end(); ++iter)
        	if (max_size < *iter)
        		max_size = *iter;
        return max_size;
    }
} s;

int main(){
    int i;
    vector<int> v;
    while (cin >> i){
    	v.push_back(i);
    }
    cout << s.longestConsecutive(v);
    return 0;
}
