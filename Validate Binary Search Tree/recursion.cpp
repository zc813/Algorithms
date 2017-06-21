/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long maximum = LONG_MAX, long minimum = LONG_MIN) {
        if (!root) return true;
        if ((root -> left && 
            ((root -> left) -> val >= root -> val ||
            (root -> left) ->val <= minimum )) ||
            (root -> right &&
            ((root -> right) -> val <= root -> val || 
            (root -> right) ->val >= maximum)))
            return false;
        if (isValidBST(root -> left,
                    min((long)root -> val,maximum),
                    minimum) &&
            isValidBST(root -> right,
                    maximum,
                    max((long)root -> val,minimum)))
            return true;
        return false;
    }
};
