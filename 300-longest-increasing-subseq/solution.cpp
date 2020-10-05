#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int lenNums = nums.size();
		if (lenNums == 0) {return 0;}
		vector<int> lisArray (lenNums, 0);
		lisArray[0] = 1;
		int longest = 1;
		for (int i = 1; i < lenNums; ++i) {
			int subLongest = 1;
			for (int j = 0; j < i; ++j) {
				if ((nums[j] < nums[i]) && ((lisArray[j] + 1) > subLongest)) {
					subLongest = lisArray[j] + 1;
				}
				lisArray[i] = subLongest;
			}
			if (subLongest > longest) {
				longest = subLongest;
			}
		}
		return longest;
    }
};

int main() {
	Solution soln;
	//vector<int> temp = {10,9,2,5,3,7,101,18};
	vector<int> temp = {3,1};
	int result = soln.lengthOfLIS(temp);
	cout << result;
}