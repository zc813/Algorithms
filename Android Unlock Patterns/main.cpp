#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class Solution{
private:
	int edge;

	int dfs(vector<bool> available, int m, int n, int path_len, int prev){
		if (path_len > n) return 0;
		if (path_len == n) return 1;
		int sum = 0;
		if (path_len >= m) sum = 1;
		for (int i = 0; i < edge * edge; ++i){
			if (!available[i]) continue;
			//if (!path.empty()){
				//int prev = *(path.end()-1);
				int p = passing(prev, i);
				if (p >= 0 && available[p]) continue;
			//}
			//path.push_back(i);
			available[i] = false;
			//sum += dfs(path, available, m, n);
			sum += dfs(available, m, n, path_len + 1, i);
			//path.pop_back();
			available[i] = true;
		}
		return sum;
	}

	int passing(int a, int b){
		int x1 = a % edge, x2 = b % edge, y1 = a / edge, y2 = b / edge;
		/*if (x1 == x2 && (y1-y2>1 || y2-y1>1) 
			|| y1 == y2 && (x1-x2>1 || x2-x1>1)
			|| (x1-x2>1 || x2-x1>1) && (y1-y2>1 || y2-y1>1))
			return index((x1+x2)/2, (y1+y2)/2);*/
    if ( x1 - x2 % 2 == 0 && y1 - y2 % 2 == 0)
			return index((x1+x2)/2, (y1+y2)/2);
		return -1;
	}

	int index(int x, int y){
		return y * edge + x;
	}

public:
	Solution (int _edge = 3) { edge = _edge; }
	int count(int m, int n){
		if (m < 1) m = 1;
		if (n >= edge * edge) n = edge * edge - 1;
		if (m > n) return 0;
		vector<bool> available(edge*edge, true);
		return dfs(available, m, n, 1, 0) * 4 + dfs(available, m, n, 1, 1) * 4 + dfs(available, m, n, 1, 4);
	}
};

int main(){
    int m, n;
    Solution s(3);
    cin >> m >> n;
    cout << s.count(m, n);
    return 0;
}
