/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
For example, given a 3-ary tree:

                  1
              /  |  \
            3   2   4
          /  \
        5     6

Return its postorder traversal as: [5,6,3,2,4,1].

Note:
Recursive solution is trivial, could you do it iteratively?
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution// iterative
{
public:
  vector<int> postorder(Node* root)
  {
    vector<int> ret;
    if (!root)
      return ret;
    stack<Node*> st;
    st.push(root);
    while (!st.empty())
    {
      auto cur = st.top();
      st.pop();
      ret.push_back(cur->val);
      for (auto &node : cur->children)
      {
        if (node)
          st.push(node);
      }
    }
    reverse(ret.begin(), ret.end());
    return ret;
    //runtime 40ms
  }
};

class Solution// recursive
{
public:
  vector<int> postorder(Node* root)
  {
    vector<int> result;
    if (root == nullptr)
      return result;
    for (int i = 0; i < root->children.size(); i++)
    {
      vector<int> temp = postorder(root->children[i]);
      result.insert(result.end(), temp.begin(), temp.end());
    }
    result.push_back(root->val);
    return result;
    //runtime: 48ms
  }
};
