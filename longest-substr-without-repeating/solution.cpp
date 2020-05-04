#include <iostream>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int strLen = s.length();
    	int longest = 0;

    	for (int i=0; i<strLen; i++) {
    		//make a 90 element array to hold whether letters have been seen
    		//91 elements to accomadate all charecter ascii charecters (32-122)
    		int letters[91];
    		//fill it with 0's
    		fill(letters, letters+91, 0);
    		int currentLength;
    		for (int j=i; j<strLen; j++) {
    			char c = s.at(j);
    			//get the charecter to an int by casting, which gives the ascii code
    			//subtract 32 to align it with our array
    			int ci = int(c) - 32;
    			printf ("i: %d   j: %d   c: %c   ci: %d\r\n",i,j,c,ci);
    			
    			//case 1: last letter in string
    			if (j == (strLen - 1)) {
    				cout << "end!\r\n";
    				if (letters[ci] > 0) {
    					currentLength = j - i;
    				} else {
    					currentLength = j - i + 1;
    				}
    				if (currentLength > longest) {
    					longest = currentLength;
    				}
    			}
    			//case 2: duplicate letter found
    			else if (letters[ci] > 0) {
    				currentLength = j - i;
    				if (currentLength > longest) {
    					longest = currentLength;
    				}
    				cout << "break!\r\n";
    				break;
    			} 
    			//case 3: normal case, just add the letter to the array
    			else {
    				letters[ci] = 1;
    			}
    		}
    	}
    	return longest;
    }
};

int main() {
	Solution soln;
	int result = soln.lengthOfLongestSubstring("abcabcbb");
    cout << "lengthLongest: " << result;
    return 0;		
}