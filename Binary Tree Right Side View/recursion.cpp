/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 既可以用 DFS 来理解，又可以用 DAC 来理解。
class Solution {
private:
    vector<int> result;
    //int level = 1;
    void addChild(TreeNode* root, int level = 1){
        if (!root) return;       
        if (level > result.size()) result.push_back(root -> val);
        //++level;
        addChild(root->right, level+1);
        addChild(root->left, level+1);
        //--level;        
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
