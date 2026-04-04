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
    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int left = getHeight(root->left);
        if (left == -1) return -1;  // left not balanced

        int right = getHeight(root->right);
        if (right == -1) return -1; // right not balanced

        if (abs(left - right) > 1) return -1; // current node not balanced

        return max(left, right) + 1; // return height
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};

// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         int height = getheight
//     }
// };