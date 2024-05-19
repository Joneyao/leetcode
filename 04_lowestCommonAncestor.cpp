/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
思路：
1. 遍历所有节点，记录满足p和q公共祖先的节点的深度和node。
2. 遍历结束后，直接返回记录的公共node即可。

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    int max_deepth = 0;
    TreeNode* ancestor_node = NULL;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        preorder(root, p, q);

        return ancestor_node;
    }

    void preorder(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node == NULL)
            return;

        TreeNode* ret = preorderFind(node, p, q);
        if (ret) {
            int deepth = getDeepth(ret);
            if (deepth > max_deepth) {
                ancestor_node = ret;
            }
        }

        preorder(node->left, p, q);
        preorder(node->right, p, q);
    }

    TreeNode* preorderFind(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node == NULL)
            return NULL;

        if (findNode(node, p) && findNode(node, q)) {
            return node;
        }

        TreeNode* l_ret = preorderFind(node->left, p, q);
        TreeNode* r_ret = preorderFind(node->right, p, q);

        if (l_ret)
            return l_ret;
        if (r_ret)
            return r_ret;
        return NULL;
    }

    bool findNode(TreeNode* node, TreeNode* target_node)
    {
        if (!node) {
            return false;
        }

        if (node->val == target_node->val)
            return true;

        int left_ret = findNode(node->left, target_node);
        int right_ret = findNode(node->right, target_node);

        return ((left_ret || right_ret) ? true : false);
    }

    // return deepth
    int getDeepth(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        else {
            int m = 0;
            int n = 0;
            m = getDeepth(node->left);
            n = getDeepth(node->right);
            if (m > n)
                return (m + 1);
            else
                return (n + 1);
        }
    }
};