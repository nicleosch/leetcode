// https://leetcode.com/problems/word-search/
//---------------------------------------------------------------------------
/*
Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.
*/
//---------------------------------------------------------------------------
#include <functional>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
using std::function;
using std::string;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    function<bool(int, int, int)> dfs = [&](int r, int c, int index) -> bool {
      if (index == word.size()) // found the word
        return true;

      if (r < 0 || r >= board.size() || c < 0 ||
          c >= board[0].size()) // behind edges
        return false;
      if (board[r][c] == '1') // already visited
        return false;
      if (board[r][c] != word[index]) // wrong character
        return false;

      char temp = board[r][c];
      board[r][c] = '1'; // visit

      bool found = dfs(r - 1, c, index + 1) || dfs(r + 1, c, index + 1) ||
                   dfs(r, c - 1, index + 1) || dfs(r, c + 1, index + 1);

      board[r][c] = temp; // unvisit

      return found;
    };

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (dfs(i, j, 0))
          return true;
      }
    }

    return false;
  }
};