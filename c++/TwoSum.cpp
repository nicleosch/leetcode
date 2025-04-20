// https://leetcode.com/problems/two-sum
//---------------------------------------------------------------------------
/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.
*/
//---------------------------------------------------------------------------
#include <unordered_map>
#include <vector>
//---------------------------------------------------------------------------
using std::unordered_map;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> diff_to_index;

    for (int i = 0; i < nums.size(); ++i) {
      if (diff_to_index.contains(nums[i]))
        return {diff_to_index[nums[i]], i};
      else
        diff_to_index[target - nums[i]] = i;
    }

    return {};
  }
};