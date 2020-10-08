#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) { return root; }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        if(root->left) { invertTree(root->left); }
        if(root->right) { invertTree(root->right); }
        return root;
    }
};

//helper functions to recursively build a tree from an array
//because that's how leetcode's website displays test cases
void makeTreeR(TreeNode* t, vector<int>& v, int i) {
    int n = v.size();
    int lIdx = (2*i) + 1;
    int rIdx = lIdx + 1;

    if (lIdx < n) {
        TreeNode *lTemp = new TreeNode(v[lIdx]);
        t->left = lTemp;
        makeTreeR(t->left, v, lIdx);
    } 
    if (rIdx < n) {
        TreeNode *rTemp = new TreeNode{v[rIdx]};
        t->right = rTemp;
        makeTreeR(t->right, v, rIdx);
    }
}

TreeNode makeTree(vector<int> in) {
    TreeNode t{in[0]};
    makeTreeR(&t, in, 0);
    return t;
}

//helper functions to print out a tree in array format
//because of course that's how leetcode's website shows it
void printTreeR(TreeNode* t, vector<int>& out) {
    if (t->left) { out.push_back(t->left->val); }
    if (t->right) { out.push_back(t->right->val); }
    if (t->left) { printTreeR(t->left, out); }
    if (t->right) { printTreeR(t->right, out); }
}

void printTree(TreeNode* t) {
    vector<int> out;
    out.push_back(t->val);
    printTreeR(t, out);
    for (auto p=out.begin(); p<out.end(); p++) {
        cout << *p << ", ";
    }
}

int main(void) {
    TreeNode test = makeTree(vector<int> {4,2,7,1,3,6,9});
    
    Solution s;
    TreeNode *result = s.invertTree(&test);

    printTree(result);
}