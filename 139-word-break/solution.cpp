#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
    }
};

int main() {
	Solution soln;
	string s = "leetcode";
    vector<string> wd {"leet", "code"};
	int result = soln.wordBreak(s, wd);
	cout << result;
}