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
private:
    vector<int> result;
    int level = 1, max_level = 0;
    void addChild(TreeNode* root){
        if (!root) return;       
        if (level > max_level){
            result.push_back(root -> val);
            max_level = level;
        }
        ++level;
        addChild(root->right);
        addChild(root->left);
        --level;        
        /*
        if (addChild(root->right) || addChild(root->left)){
            --level;
            return true;
        }else{
            --level;
            return false;
        }*/
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        addChild(root);
        return result;
    }
};
