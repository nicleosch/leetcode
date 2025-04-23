// https://leetcode.com/problems/k-closest-points-to-origin/
//---------------------------------------------------------------------------
/*
Given an array of points where points[i] = [xi, yi] represents a point on the
X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance
(i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique
(except for the order that it is in).
*/
//---------------------------------------------------------------------------
#include <functional>
#include <queue>
#include <utility>
#include <vector>
//---------------------------------------------------------------------------
using std::less;
using std::pair;
using std::priority_queue;
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> result;

    priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> queue;

    int index = 0;
    for (const auto &point : points) {
      double dist = euclideanDistanceToOrigin(point[0], point[1]);
      if (queue.size() < k) {
        queue.emplace(dist, index);
      } else if (dist < queue.top().first) {
        queue.pop();
        queue.emplace(dist, index);
      }
      ++index;
    }

    for (int i = 0; i < k; ++i) {
      result.push_back({points[queue.top().second]});
      queue.pop();
    }

    return result;
  }

private:
  double euclideanDistanceToOrigin(int x, int y) { return sqrt(x * x + y * y); }
};