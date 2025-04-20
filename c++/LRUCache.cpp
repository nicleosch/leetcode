// https://leetcode.com/problems/lru-cache/
//---------------------------------------------------------------------------
/*
Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

- LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
- int get(int key): Return the value of the key if the key exists, otherwise
return -1.
- void put(int key, int value): Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds
the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/
//---------------------------------------------------------------------------
#include <unordered_map>
//---------------------------------------------------------------------------
using std::unordered_map;
//---------------------------------------------------------------------------
class Node {
public:
  Node(int key, int value) : key(key), value(value) {}
  Node(int key, int value, Node *next) : key(key), value(value), next(next) {}
  int key;
  int value;
  Node *prev = nullptr;
  Node *next = nullptr;
};
//---------------------------------------------------------------------------
class LRUCache {
public:
  /// Constructor
  LRUCache(int capacity) : capacity(capacity), head(nullptr) {}
  /// Destructor
  ~LRUCache() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }
  /// Get the value for given key
  int get(int key) {
    if (map.contains(key)) {
      moveToFront(map[key]);
      return map[key]->value;
    }
    return -1;
  }
  /// Update/Add an entry in/to the cache.
  void put(int key, int value) {
    if (map.contains(key)) { // Update Case
      map[key]->value = value;
      moveToFront(map[key]);
      return;
    }
    if (head == nullptr) { // Initialization Case
      head = new Node(key, value);
      end = head;
      size = 1;
    } else { // Regular Case
      Node *temp = new Node(key, value, head);
      head->prev = temp;
      head = temp;

      if (size == capacity) {
        map.erase(end->key);
        end = end->prev;
        delete end->next;
        end->next = nullptr;
      } else {
        ++size;
      }
    }
    map[key] = head;
  }

private:
  /// Move given node to the front of the LinkedList.
  void moveToFront(Node *temp) {
    if (temp == head)
      return;
    if (temp == end)
      end = end->prev;

    temp->prev->next = temp->next;
    if (temp->next != nullptr)
      temp->next->prev = temp->prev;
    temp->prev = nullptr;
    temp->next = head;
    head->prev = temp;
    head = temp;
  }

  Node *head;
  Node *end;
  int size;
  int capacity;
  unordered_map<int, Node *> map;
};