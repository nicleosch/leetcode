// https://leetcode.com/problems/implement-trie-prefix-tree/
//---------------------------------------------------------------------------
/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to
efficiently store and retrieve keys in a dataset of strings. There are various
applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- Trie(): Initializes the trie object.
- void insert(String word): Inserts the string word into the trie.
- boolean search(String word): Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix): Returns true if there is a previously
inserted string word that has the prefix prefix, and false otherwise.
*/
//---------------------------------------------------------------------------
#include <array>
#include <memory>
#include <string>
//---------------------------------------------------------------------------
using std::array;
using std::string;
using std::unique_ptr;
//---------------------------------------------------------------------------
class Node {
public:
  /// Constructor.
  Node() = default;

  /// The 26 next possible characters.
  std::array<std::unique_ptr<Node>, 26> children;
  /// Whether this node represents the end of a word.
  bool end_of_word;
};
//---------------------------------------------------------------------------
class Trie {
public:
  Trie() { root = std::make_unique<Node>(); }
  /// Insert a word into the Trie.
  void insert(string word) {
    Node *cur = root.get();
    for (char c : word) {
      int index = c - 'a';
      if (cur->children[index].get() == nullptr) {
        cur->children[index] = std::make_unique<Node>();
      }
      cur = cur->children[index].get();
    }
    cur->end_of_word = true;
  }
  /// Search a full word in the Trie.
  bool search(string word) { return search(word, false); }
  /// Search a prefix in the Trie.
  bool startsWith(string prefix) { return search(prefix, true); }

private:
  /// Shared search implementation.
  bool search(string word, bool prefix) {
    Node *cur = root.get();
    for (char c : word) {
      int index = c - 'a';
      cur = cur->children[index].get();
      if (cur == nullptr)
        return false;
    }
    return prefix ? true : cur->end_of_word;
  }
  /// The root of the Trie.
  unique_ptr<Node> root;
};