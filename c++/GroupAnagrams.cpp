// https://leetcode.com/problems/group-anagrams/
//---------------------------------------------------------------------------
/*
Given an array of strings strs, group the anagrams together. You can return the
answer in any order.
*/
//---------------------------------------------------------------------------
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
//---------------------------------------------------------------------------
using std::string;
using std::unordered_map;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;
    unordered_map<string, int> anagram_to_index;

    int index = 0;
    for (const auto &str : strs) {
      // sort
      string sorted(str);
      partial_sort_copy(str.begin(), str.end(), sorted.begin(), sorted.end());
      // insert
      if (!anagram_to_index.contains(sorted)) {
        anagram_to_index[sorted] = index++;
        result.push_back({str});
      } else {
        result[anagram_to_index[sorted]].push_back(str);
      }
    }

    return result;
  }
};