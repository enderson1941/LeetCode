/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

                3
              /   \
            5      1
          /  \   /  \
        ⑥    2 ⑨   ⑧
           /  \
          ⑦   ④


Note:
Both of the given trees will have between 1 and 100 nodes.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> value1;
        vector<int> value2;
        record(root1,value1);
        record(root2,value2);
        return value1 == value2;
    }
    void record(TreeNode* root1, vector<int>& value)
    {
        if(root1 == NULL)
            return;
        if(root1->left == NULL && root1->right == NULL)
            value.push_back(root1->val);
        record(root1->left, value);
        record(root1->right, value);
    }
    // runtime: 4ms
};
