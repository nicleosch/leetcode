// https://leetcode.com/problems/generate-parentheses/

/*
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dparr(n + 1);
    dparr[0] = {""};

    for (int i = 1; i < n + 1; ++i) {
      for (int j = 0; j < i; ++j) {
        for (const auto &left : dparr[j]) {
          for (const auto &right : dparr[i - j - 1]) {
            dparr[i].push_back("(" + left + ")" + right);
          }
        }
      }
    }

    return dparr[n];
  }
};