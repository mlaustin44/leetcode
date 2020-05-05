#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
        int numNums = nums.size();

        map<int,int> numMap;

        for (int i=0; i<numNums; i++) {
        	numMap[nums[i]]=i;
        }

        for (int i=0; i<numNums; i++) {
        	int match;
        	int needed = target - nums[i];
        	cout << "i: " << i << " needed: " << needed << " cur num: " << nums[i] << "\r\n";
        	map<int,int>::iterator it = numMap.find(needed);
        	//if iterator is not at the end, we found a match
        	if (it != numMap.end()) {
        		match = it->second;
        	
	        	if (match != i) {
	        		result.push_back(i);
	        		result.push_back(match);
	        		cout << result[0] << "  " << result[1] << "\r\n";
	        		return result;
	        	}
	        }
        }

        result.push_back(0);
        return result;
    }
};

int main() {
	vector <int> input = {2,5,5,11};

	Solution soln;
	soln.twoSum(input, 10);
	return 0;
}