// https://leetcode.com/problems/time-based-key-value-store/
//---------------------------------------------------------------------------
/*
Design a time-based key-value data structure that can store multiple values for
the same key at different time stamps and retrieve the key's value at a certain
timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the
value value at the given time timestamp. String get(String key, int timestamp)
Returns a value such that set was called previously, with timestamp_prev <=
timestamp. If there are multiple such values, it returns the value associated
with the largest timestamp_prev. If there are no values, it returns "".
*/
//---------------------------------------------------------------------------
#include <string>
#include <unordered_map>
#include <vector>
//---------------------------------------------------------------------------
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
//---------------------------------------------------------------------------
class TimeMap {
public:
  TimeMap() = default;

  void set(string key, string value, int timestamp) {
    index[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp) {
    if (!index.contains(key))
      return "";

    auto &vec = index[key];
    int l = 0;
    int r = vec.size() - 1;
    while (l < r) {
      int mid = r - (r - l) / 2;
      if (vec[mid].second == timestamp) {
        return vec[mid].first;
      } else if (vec[mid].second > timestamp) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    if (vec[l].second <= timestamp)
      return vec[l].first;
    else
      return "";
  }

private:
  unordered_map<string, vector<pair<string, int>>> index;
};