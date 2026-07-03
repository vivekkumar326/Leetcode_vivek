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
int maxDiameter = 0;

int diameter(TreeNode* root) {
    if (!root)
        return 0;

    //  height of left and right subtree
    int lHeight = diameter(root->left);
    int rHeight = diameter(root->right);

    // Update the global max diameter 
    if (lHeight + rHeight > maxDiameter)
        maxDiameter = lHeight + rHeight;

    // Return height of current subtree
    return 1 + max(lHeight, rHeight);
}

// Function to get diameter of a binary tree
int diameterOfBinaryTree(TreeNode* root) {
    maxDiameter = 0; 
    diameter(root);
    return maxDiameter;
}

};