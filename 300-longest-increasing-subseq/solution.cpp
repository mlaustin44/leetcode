#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.size() < 2) {
    		return nums.size();
    	}
        int longestSeq = 0;
        int startPoint = 0;
        int currentSeq = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
        	if (nums[i] < nums[i+1]) {
        		currentSeq += 1;
        	} else {
        		if (currentSeq > longestSeq) {
        			longestSeq = currentSeq;
        		}
        		currentSeq = 1;
        	}
        }
        return longestSeq;
    }
};

int main() {
	Solution soln;
	vector<int> temp = {10,9,2,5,3,7,101,18};
	int result = soln.lengthOfLIS(temp);
	cout << result;
}