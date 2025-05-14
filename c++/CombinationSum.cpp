// https://leetcode.com/problems/combination-sum/
//---------------------------------------------------------------------------
/*
Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two
combinations are unique if the frequency of at least one of the chosen numbers
is different.

The test cases are generated such that the number of unique combinations that
sum up to target is less than 150 combinations for the given input.
*/
//---------------------------------------------------------------------------
#include <functional>
#include <vector>
//---------------------------------------------------------------------------
using std::function;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;

    std::function<void(int, vector<int>, int)> dfs =
        [&](int index, vector<int> cur, int total) {
          if (total == 0) {
            result.push_back(cur);
            return;
          }
          if (index >= candidates.size() || total < 0)
            return;

          for (int i = index; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            dfs(i, cur, total - candidates[i]);
            cur.pop_back();
          }
        };
    dfs(0, {}, target);

    return result;
  }
};