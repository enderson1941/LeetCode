/*
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example, given a 3-ary tree:

                       1
                    /  |  \
                   3   2   4
                 /  \
                5   6

We should return its level order traversal:
[
     [1],
     [3,2,4],
     [5,6]
]

Note:
The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root)
  {
    vector<vector<int>> res; //result
    queue<Node*> q; //queue
    int level = 0;
    if (root == NULL)
        return res;
    q.push(root);
    q.push(NULL);
    res.push_back(vector<int>());
    while(!q.empty())
    {
      Node* n = q.front();
      q.pop();
      if (n != NULL)
      {
        res[level].push_back(n->val);
        for (auto c : n->children)
        {
          q.push(c);
        }
      }
      else
      {
        if (!q.empty())
        {
          level++;
          res.push_back(vector<int>());
          q.push(NULL);
        }
      }
    }
    return res;
  }
};
