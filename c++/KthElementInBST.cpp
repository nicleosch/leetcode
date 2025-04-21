// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//---------------------------------------------------------------------------
/*
Given the root of a binary search tree, and an integer k, return the kth
smallest value (1-indexed) of all the values of the nodes in the tree.
*/
//---------------------------------------------------------------------------
#include <unordered_set>
#include <vector>
//---------------------------------------------------------------------------
using std::unordered_set;
using std::vector;
//---------------------------------------------------------------------------
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
//---------------------------------------------------------------------------
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    vector<int> values;

    vector<TreeNode *> stack;
    unordered_set<TreeNode *> visited;
    stack.push_back(root);
    while (!stack.empty()) {
      TreeNode *cur = stack.back();

      if (cur->left != nullptr && !visited.contains(cur->left))
        stack.push_back(cur->left);
      else {
        visited.insert(cur);
        stack.pop_back();
        values.push_back(cur->val);
        if (cur->right != nullptr)
          stack.push_back(cur->right);
      }

      // stop early
      if (values.size() == k)
        return values[k - 1];
    }

    // impossible to reach if 1 <= k <= n
    return -1;
  }
};