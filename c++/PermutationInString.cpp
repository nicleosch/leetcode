// https://leetcode.com/problems/permutation-in-string/

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or
false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> original;
    for (char c : s1)
      ++original[c];

    unordered_map<char, int> window;
    for (int i = 0; i < s2.size(); ++i) {
      ++window[s2[i]];

      if (i >= s1.size()) {
        if (--window[s2[i - s1.size()]] == 0)
          window.erase(s2[i - s1.size()]);
      }

      if (window == original)
        return true;
    }

    return false;
  }
};