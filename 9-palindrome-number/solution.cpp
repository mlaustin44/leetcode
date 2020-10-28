#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		//no negative numbers are palindromes
		if (x < 0) { return false; }

		//split the number into a vector of its digits
		vector<int> digits;
		while (x > 0) {
			digits.push_back(x % 10);
			x = x / 10;
		}

		//iterate through half the digits and make sure they match the digit at the other end
		// since integer division rounds down, this will simply ignore the 'center' digit
		// for cases where x has an odd # of digits
		int nDigits = digits.size();
		for (int i=0; i<(nDigits / 2); ++i) {
			//as soon as we find a mismatch, return false
			if (digits[i] != digits[nDigits - i - 1]) { return false; }
		}
		//if everything matched, we're good
		return true;
	}
};

int main() {
	Solution soln;
	cout << soln.isPalindrome(1);
}