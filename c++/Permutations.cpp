// https://leetcode.com/problems/permutations/
//---------------------------------------------------------------------------
/*
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.
*/
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
using std::swap;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    backtrack(result, nums, 0);
    return result;
  }

private:
  void backtrack(vector<vector<int>> &result, vector<int> &nums, int start) {
    if (start == nums.size()) {
      result.push_back(nums);
    }
    for (int i = start; i < nums.size(); ++i) {
      swap(nums[start], nums[i]);
      backtrack(result, nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }
};