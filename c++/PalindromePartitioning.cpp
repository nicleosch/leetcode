// https://leetcode.com/problems/palindrome-partitioning/
//---------------------------------------------------------------------------
/*
Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.
*/
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
using std::string;
using std::string_view;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> cur;
    backtrack(result, cur, s, 0);
    return result;
  }

private:
  bool isPalindrome(string &s) {
    for (int l = 0, r = s.size() - 1; l <= r; ++l, --r) {
      if (s.at(l) != s.at(r))
        return false;
    }
    return true;
  }
  //---------------------------------------------------------------------------
  void backtrack(vector<vector<string>> &result, vector<string> &cur, string &s,
                 int idx) {
    if (idx >= s.size()) {
      result.push_back(cur);
      return;
    }

    for (int i = idx; i < s.size(); ++i) {
      string ssub(s.substr(idx, i - idx + 1));
      if (isPalindrome(ssub)) {
        cur.push_back(ssub);
        backtrack(result, cur, s, i + 1);
        cur.pop_back();
      }
    }
  }
};