#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs;
        //first stair - only one way to get there, from 0
        stairs.push_back(1);
        //second stair - two ways to get there, 2 steps from 0 or 1 step from 1
        stairs.push_back(2);

        //for each step after that: there are two immediate ways to get to there: from 1 step back or 2 steps back
        //so therefore the total number of ways to get to step is the sum of the ways to get to one step back and to two steps back
        for (int i = 2; i < n; i++) {
        	int numWays = stairs[i-1] + stairs[i-2];
        	stairs.push_back(numWays);
        }

        return stairs[n-1];
    }
};

int main() {
	Solution soln;
	int result = soln.climbStairs(3);
	cout << "result is " << result;
}