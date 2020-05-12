#include <vector>
#include <iostream>

using namespace std;

/*
Since the array was sorted before it was rotated, all we need
to do is find the point where where the array values stop
ascending - that's the pivot point - then return that value.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i=1; i<nums.size(); i++) {
        	int last = nums[i-1];
        	int current = nums[i];
        	if (current < last) {
        		return current;
        	}
        }
        return nums[0];
    }
};

int main() {
	Solution soln;
	vector<int> test = {4,5,6,7,0,1,2};
	int result = soln.findMin(test);
	cout << result;
}