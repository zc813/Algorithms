// Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

class Solution {
private:
	unordered_map<int, int> max;

public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        for (int n: nums){
            //max[n-max[n-1]] = max[n+max[n+1]] = max[n-1] + max[n+1] + 1;
            //if (max_len < max[n-max[n-1]])
            //    max_len = max[n-max[n-1]];
            // note that max[n-1] has changed


            //int tmp = max[n-max[n-1]] = max[n+max[n+1]] = max[n-1] + max[n+1] + 1;
            //if (max_len < tmp) max_len = tmp;
            // consider the case 1, 2, 0, 1 in which 1 appears twice

            //if (max[n] > 0 )continue;
            //int tmp = max[n-max[n-1]] = max[n+max[n+1]] = max[n-1] + max[n+1] + 1;
            //if (max_len < tmp) max_len = tmp; 
            // consider the case 2, 0, 1, 1 in which max[1] is always 0

            //max[n] = max[n-max[n-1]] = max[n+max[n+1]] = max[n-1] + max[n+1] + 1;
            // consider the case 1, 2, 0, 1 in which 1 is calculated twice

            if (max[n]>0) continue;
            max[n] = max[n-max[n-1]] = max[n+max[n+1]] = max[n-1] + max[n+1] + 1;
            if (max_len < max[n])
            	max_len = max[n];
        }
        return max_len;
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
