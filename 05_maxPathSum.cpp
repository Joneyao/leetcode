#include <iostream>
#include <math>
#include <set>
#include <vector>

using namespace std;

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
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    int max_path_sum = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        maxGain(root);
        return max_path_sum;
    }

    int maxGain(TreeNode* node)
    {
        if (node == 0)
            return 0;

        int l_gain = maxGain(node->left);
        int r_gain = maxGain(node->right);
        l_gain = (l_gain > 0) ? l_gain : 0;
        r_gain = (r_gain > 0) ? r_gain : 0;

        int path_sum = l_gain + r_gain + node->val;

        max_path_sum = (max_path_sum > path_sum) ? max_path_sum : path_sum;

        return (node->val + ((l_gain > r_gain) ? l_gain : r_gain));
    }
};