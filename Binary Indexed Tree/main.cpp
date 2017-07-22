//
// Binary Index Tree
// prefix sum
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class BIT{
private:
	vector<int>& nums;
	vector<int> tree;
	int lowbit(int x){
		return x & (-x);
	}

	void build()
	{ 
		tree.resize(nums.size());
	    for (int i=1; i<=nums.size(); i++)
	    {
	        tree[i-1]=nums[i-1];
	        for (int j=i-2; j>=i-lowbit(i); j--)
	            tree[i-1]+=nums[j];
	    }
	}

public:
	BIT(vector<int>& nums_): nums(nums_) {build();}
	int sum (int k)
	{
	    int ans = 0;
	    for (int i = k; i > 0; i -= lowbit(i))
	        ans += tree[i-1];
	    return ans;
	}

	void update (int index, int val){
		int delta = val - nums[index-1];
		for (int i = index; i <= nums.size(); i += lowbit(i))
			tree[i-1] += delta;
		nums[index-1] = val;
	}
};

int main(){
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; n > 0; --n){
		cin >> i;
		nums.push_back(i);
	}
	cout << "Processing\n";
	BIT s(nums);

	char c; int m;
	while (cin >> c){
		if (c == 's'){
			cin >> m;
			cout << "sum: " << s.sum(m) << '\n';
		} else if (c == 'u'){
			cin >> m >> n;
			s.update(m, n);
		}
		cin.ignore(INT_MAX, '\n');
	}
	return 0;
}
