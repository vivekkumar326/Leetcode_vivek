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
    vector<vector<int>> levelOrder(TreeNode* root) {

        
        vector<vector<int>> ans;

        // Tree empty hai
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;

        // Root ko queue me daalo
        q.push(root);

        while (!q.empty()) {

            // Current level me kitne nodes hain
            int size = q.size();

            // Ek level ka answer store karne ke liye
            vector<int> level;

            // Sirf current level ke nodes process karo
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Current node ki value level me add karo
                level.push_back(node->val);

                // Children ko queue me daalo
                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // Current level complete hone ke baad ans me daalo
            ans.push_back(level);
        }

        return ans;
    }
};