// segment tree

#include <iostream>
#include <vector>
#include "seg_tree.h"

using std::vector;

int main(){
	vector<double> v;
	int n;
	for (std::cin >> n; n>0; --n){
		double i;
		std::cin >> i;
		v.push_back(i);
	}
	SegTree<double> tree(v);
	std::cout << "\nInput beginning and ending indecies:\n";
	int a = 0, b = v.size();
	while (std::cin >> a, std::cin >> b){
		std::cout << tree.min(a,b) << '\n';
	}
	return 0;
}
