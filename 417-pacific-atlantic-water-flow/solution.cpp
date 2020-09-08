#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rows, cols, rmax, cmax;

    vector< vector<int> > pacificAtlantic(vector< vector<int> >& matrix) {
        //figure out size of input vector
        rows = matrix.size();
        if (rows < 1) {
            return vector< vector<int> > {};
        }
        cols = matrix[0].size();
        if (rows < 1) {
            return vector< vector<int> > {};
        }

        //create a result vector (0=no path, 1=path)
        
        vector< vector<int> > result(rows, vector<int>(cols, 0));

        /* 
        Result matrix
        0 if no paths
        1 if a path to just the pacific was found
        2 if a path to just the atlantic was found
        3 if a path to both pacific and atlantic was found
        -1 if a search is in progress
        */    
        //Top Right and Bottom Left corners touch both by definition
        result[0][cols - 1] = 3;
        result[rows - 1][0] = 3;
        
        //remain

        //convienence constants to easily check our values (since they're 0 indexed)
        rmax = rows - 1;
        cmax = cols - 1;
        
        vector< vector<int> > response;
        
        for (int r=0; r < rows; ++r) {
            for (int c=0; c < cols; ++c) {
                int res = search(matrix, result, r, c);
                if (res == 3) {
                    response.push_back(vector<int> {r,c});
                }
            }
        }

        return response;
    }

    /* 
        Recursive search function
        Return 0 if no paths
        Return 1 if a path to just the pacific was found
        Return 2 if a path to just the atlantic was found
        Return 3 if a path to both pacific and atlantic was found
    */
    int search(vector< vector<int> >& matrix, vector< vector<int> >& result, int r, int c) {
        result[r][c] = -1;
        
        //check if we're in a pre-checked cell (can only assume this for ones that touch both)
        if (result[r][c] > 0) {return result[r][c];}
        
        //hold status if we're touching pacific or atlantic
        int pTouch = 0;
        int aTouch = 0;

        //check if we're on an edge.  because we return for both min and max on both r and c we can increment and decrement them freely now
        //check if we're on a pacific edge
        if (r == 0 || c == 0) { 
            pTouch = 1;
            }
        //check if we're on an atlantic edge
        if (r == rmax || c == cmax) { 
            aTouch = 1;
            }
        

        int check;
        //check all 4 directions water can flow
        //up
        if ((r > 0) && (result[r-1][c] != -1) && (matrix[r-1][c] <= matrix[r][c])) {
            check = search(matrix, result, (r-1), c);
            if (check == 3) {
                result[r][c] = 3;
                return 3;
            } else if (check == 1) {
                pTouch = 1;
            } else if (check == 2) {
                aTouch = 1;
            }
        }
        
        //down
        if ((r < rmax) && (result[r+1][c] != -1) && (matrix[r+1][c] <= matrix[r][c])) {
            check = search(matrix, result, (r+1), c);
            if (check == 3) {
                result[r][c] = 3;
                return 3;
            } else if (check == 1) {
                pTouch = 1;
            } else if (check == 2) {
                aTouch = 1;
            }
        }
        //left
        if ((c > 0) && (result[r][c-1] != -1) && (matrix[r][c-1] <= matrix[r][c])) {
            check = search(matrix, result, r, (c-1));
            if (check == 3) {
                result[r][c] = 3;
                return 3;
            } else if (check == 1) {
                pTouch = 1;
            } else if (check == 2) {
                aTouch = 1;
            }
        }
        //right
        if ((c < cmax) && (result[r][c+1] != -1) && (matrix[r][c+1] <= matrix[r][c])) {
            check = search(matrix, result, r, (c+1));
            if (check == 3) {
                result[r][c] = 3;
                return 3;
            } else if (check == 1) {
                pTouch = 1;
            } else if (check == 2) {
                aTouch = 1;
            }
        }

        //return the appropriate values
        if (pTouch == 1 && aTouch == 1) {
            result[r][c] = 3;
            return 3;
        } else if (pTouch == 1 && aTouch == 0) {
            result[r][c] = 1;
            return 1;
        } else if (pTouch == 0 && aTouch == 1) {
            result[r][c] = 2;
            return 2;
        } else {
            result[r][c] = 0;
            return 0;
        }
    }
};

int main(void)
{
    Solution soln;
    vector< vector<int> > test = { {1,1},
                                   {1,1},
                                   {1,1} };

    vector< vector<int> > r = soln.pacificAtlantic(test);
    for (int i=0; i<r.size(); ++i) {
        cout << "["<<r[i][0]<<", "<<r[i][1]<<"]\n";
    }
}