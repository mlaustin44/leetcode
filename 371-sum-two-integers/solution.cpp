#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry, shiftCarry;
        //first get the main sum using XOR (all of the places with a 0 and a 1)
        int sum = a ^ b;
        //now get the carry (all of the places with a 1 and a 1)
        carry = a & b;
        while (carry != 0) {
        	//shift the carry left by one bit (so that if there was a 1/1 in the 2's places it's moved to the 4's place)
        	//need to cast to unsigned int because leetcode's compiler throws an error left shifting a negative number (even if gcc doesnt)
        	shiftCarry = (unsigned int)carry << 1;
        	//get the new carry (what you'd get from adding the old carry to the sum)
        	carry = sum & shiftCarry;
        	//sum all the 0/1 and 1/0 places with xor again
        	sum = sum ^ shiftCarry;
        }
        return sum;
    }
};

int main() {
	Solution soln;
    int result = soln.getSum(-12,-8);
    cout << "result " << result;
    return 0;		
}