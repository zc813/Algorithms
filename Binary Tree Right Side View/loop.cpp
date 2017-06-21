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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        vector<TreeNode*> lines (1,root);
        /* 这个debug了好久一直指针报错，猜猜看为什么？
        auto it = lines.begin();
        auto end = lines.end();
        while (it < lines.end()){
            result.push_back((*it) -> val);
            for (end = lines.end(); it < end; ++it){
                if ((*it) -> right)
                    lines.push_back((*it)->right);
                if ((*it) -> left)
                    lines.push_back((*it)->left);
            } 
        }*/
        int i = 0;
        int size = lines.size();
        while (i < lines.size()){
            result.push_back(lines[i] -> val);
            for (size = lines.size(); i < size; ++i){
                if (lines[i] -> right)
                    lines.push_back(lines[i]->right);
                if (lines[i] -> left)
                    lines.push_back(lines[i]->left);
            }
        }        
        return result;
    }
};
