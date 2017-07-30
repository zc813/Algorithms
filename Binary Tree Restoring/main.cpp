// Rebuild tree with pre_order and in_order traversals

#include <vector>

using std::vector;

vector<int> pre_order {1,2,4,7,3,5,6,8};
vector<int> in_order  {4,7,2,1,5,3,8,6};

struct Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(): val(0), left(nullptr), right(nullptr){}
};

Node* fill(size_t left, size_t right){
	static size_t pos = 0;
	for (size_t i = left; i <= right; ++i){
		if (in_order[i] == pre_order[pos]){
			Node* child = new Node;
			child -> val = pre_order[pos];
			++pos;
			child -> left = fill(left, i);
			child -> right = fill(i+1, right);
			return child;
		}
	}
	return nullptr;
}

int main(){
	if (in_order.size()>0)
    	Node* root = fill(0, in_order.size()-1);
    return 0;
}
