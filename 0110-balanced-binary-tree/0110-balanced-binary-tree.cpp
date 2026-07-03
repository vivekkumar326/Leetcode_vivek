/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int Balanced(TreeNode* root) {
if (root == nullptr) {
return 0;
}

    int lHeight = Balanced(root->left);
    int rHeight = Balanced(root->right);
    if (lHeight == -1 || rHeight == -1 ||
        abs(lHeight - rHeight) > 1) {
        return -1;
    }
    return max(lHeight, rHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return Balanced(root) >= 0;
}

};
