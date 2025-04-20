// https://leetcode.com/problems/3sum/
//---------------------------------------------------------------------------
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          result.push_back({nums[i], nums[left++], nums[right]});
          while (nums[left] == nums[left - 1] && left < right)
            ++left;
        } else if (sum < 0) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return result;
  }
};