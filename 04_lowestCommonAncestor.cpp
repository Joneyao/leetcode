/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
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
};

/**
思路：
情况1： AB两个节点在一边树上。
先找到A节点，再找到B节点，AB之间的深度就是公共深度。

情况2：AB不在一边树上。
1. 先要找到AB的祖先。
2. 计算A和B到祖先的距离。
3. 返回最大的值即可。

怎么找祖先？
情况1：遍历所有节点，直到找到AB两个节点。
情况2：记录便利A和B节点过程中的每个节点，有相同的节点，即为祖先。

怎样遍历二叉树？

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<int> p_node_list;
        vector<int> q_node_list;

    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
