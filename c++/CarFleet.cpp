// https://leetcode.com/problems/car-fleet/
//---------------------------------------------------------------------------
/*
There are n cars at given miles away from the starting mile 0, traveling to
reach the mile target.

You are given two integer array position and speed, both of length n, where
position[i] is the starting mile of the ith car and speed[i] is the speed of the
ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at
the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed of the car
fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be
considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination
*/
//---------------------------------------------------------------------------
#include <numeric>
#include <vector>
//---------------------------------------------------------------------------
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    // For each car, define the time to target
    vector<double> time_to_target(speed.size());
    for (int i = 0; i < speed.size(); ++i) {
      time_to_target[i] = static_cast<double>(target - position[i]) / speed[i];
    }

    // Sort the time to target descending by the cars position
    vector<int> indices(time_to_target.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&](int i, int j) { return position[i] > position[j]; });

    // If a slower car is in front of faster cars, they will form a fleet
    int fleets = 1;
    for (int i = 1; i < indices.size(); ++i) {
      if (time_to_target[indices[i]] > time_to_target[indices[i - 1]]) {
        ++fleets;
      } else {
        time_to_target[indices[i]] = time_to_target[indices[i - 1]];
      }
    }

    return fleets;
  }
};