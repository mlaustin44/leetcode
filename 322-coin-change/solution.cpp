#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	int intmax = numeric_limits<int>::max() - 1;
    	vector<int> values(amount + 1);
    	//fill vector with max int values (which will represent no solution)
    	values.assign((amount + 1), intmax);
    	values[0] = 0;

    	for (int i = 0; i < coins.size(); i++) {
    		int coin = coins[i];
    		cout << "coin " << coin << "\n";
    		for (int j = coin; j <= amount; j++) {
    			//for each possible value - check if removing the current coin and taking current value + remaining value is fewer coins
    			values[j] = min(values[j], values[j-coin] + 1);
    		}
    	}
    	if (values[amount] == intmax) {
    		return -1;
    	} else {
    		return values[amount];
    	}
    }
};

int main() {
	Solution soln;

	vector<int> testval = {186,419,83,408};

	int result = soln.coinChange(testval, 6249);
	cout << result;
	return 0;
}