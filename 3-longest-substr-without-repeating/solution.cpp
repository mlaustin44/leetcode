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
    		//make a 95 element array to hold whether letters have been seen
    		//95 elements to accomadate all ascii charecters (32-127)
    		int letters[95];
    		//fill it with 0's
    		fill(letters, letters+95, 0);
    		int currentLength;
    		for (int j=i; j<strLen; j++) {
    			char c = s.at(j);
    			//get the charecter to an int by casting, which gives the ascii code
    			//subtract 32 to align it with our array (all the ascii's <32 are control)
    			int ci = int(c) - 32;
    			printf ("i: %d   j: %d   c: %c   ci: %d\r\n",i,j,c,ci);
    			
    			//case 1: last letter in string
    			if (j == (strLen - 1)) {
    				cout << "end!\r\n";
    				//check if the last charecter is a duplicate or not
    				currentLength = j - i;
    				if (letters[ci] == 0) {
    					currentLength += 1
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