// Segment min-tree
// supports vector<class T>
//
// Zhenbang Chen
// Updated Fri, Jun 30, 2017

#include <vector>

template <class T>
class SegTree{
private:
	struct TreeNode{
		TreeNode * left = nullptr;
		TreeNode * right = nullptr;
		T value = 0;
		size_t upper_bound = 0;
		size_t lower_bound = 0;
	} ;
	TreeNode root;
	T buildRecursion (std::vector<T> & v, size_t start, size_t end, TreeNode * node){
		node -> upper_bound = end;
		node -> lower_bound = start;

		if (start == end){
			node -> value = v[start];
			return node -> value;
		}

		TreeNode * left = new TreeNode;
		TreeNode * right = new TreeNode;
		node -> left = left;
		node -> right = right;
		size_t mid = start + ((end - start) >> 1);
		T l_min = buildRecursion(v, start, mid, left);
		T r_min = buildRecursion(v, mid +1, end, right);
		node -> value = l_min < r_min ? l_min : r_min;
		return node -> value;
	}
	void freeRecursion (TreeNode * node){
		if (!node) return;
		freeRecursion(node -> left);
		freeRecursion(node -> right);
		delete node;
	}
	T minRecursion(size_t start, size_t end, TreeNode * node){
		if (start == node -> lower_bound && end == node -> upper_bound) return node -> value;

		size_t mid = node -> left -> upper_bound;
		if (start > mid) return minRecursion(start,end,node->right);
		if (end <= mid) return minRecursion(start,end,node->left);
		T l_min = minRecursion(start,mid,node->left);
		T r_min = minRecursion(mid+1,end,node->right);
		return l_min < r_min ? l_min : r_min;
	}
public:
	size_t size = 0;
	SegTree (std::vector<T> & v) {
		size = v.size();
		buildRecursion(v, 0, size-1, &root);
	}
	~SegTree(void){
		freeRecursion(root.left);
		freeRecursion(root.right);
	}
	T min(size_t start, size_t end){
		if (size == 0) return -1;
		//if (start < 0) start = 0;
		if (end >= size) end = size-1;
		if (start > end) start = end;
		return minRecursion(start, end, &root);
	}
} ;
