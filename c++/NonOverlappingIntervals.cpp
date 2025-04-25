// https://leetcode.com/problems/non-overlapping-intervals/
//---------------------------------------------------------------------------
/*
Given an array of intervals intervals where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of
the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For
example, [1, 2] and [2, 3] are non-overlapping.
*/
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int result = 0;

    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[0] != b[0])
             return a[0] < b[0];
           return a[1] > b[1];
         });

    int min_max = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      auto &cur = intervals[i];
      if (cur[0] < min_max) {
        ++result;
        min_max = cur[1] > min_max ? min_max : cur[1];
      } else {
        min_max = cur[1];
      }
    }

    return result;
  }
};