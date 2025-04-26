// https://leetcode.com/problems/gas-station/
//---------------------------------------------------------------------------
/*
There are n gas stations along a circular route, where the amount of gas at the
ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
from the ith station to its next (i + 1)th station. You begin the journey with
an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index
if you can travel around the circuit once in the clockwise direction, otherwise
return -1. If there exists a solution, it is guaranteed to be unique.
*/
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
using std::vector;
//---------------------------------------------------------------------------
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    for (int i = 0; i < gas.size(); ++i) {
      if (gas[i] >= cost[i]) {
        // Start travel
        int tank = 0;
        int pos = i;
        for (int step = 0; step < gas.size(); ++step, ++pos) {
          // Update tank
          tank += gas[pos % gas.size()];
          tank -= cost[pos % gas.size()];
          if (tank < 0) {
            // Jump to next possible starting position
            i += step;
            break;
          }
        }
        if (tank >= 0)
          return i;
      }
    }
    return -1;
  }
};