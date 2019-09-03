#include <stack>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack <TreeNode*> s;
        queue <TreeNode*> q;
        TreeNode* cur = NULL;
        TreeNode* new_root = NULL;
        
        if (!root) {
            return NULL;
        }
        
        s.push(root);
        cur = root;
        while (!s.empty() && cur) {
           
	    //
            while(cur->left) {
                s.push(cur);
                cur = cur->left;
            }
            
            while (!s.empty() && !cur->right) {
                q.push(cur);
                cur = s.top();
                s.pop();
            }
            
            if (cur->right) {
                q.push(cur);
                s.push(cur->right);
                cur = s.top();
            }
        }
        
        while (!q.empty()) {
            cur = q.front();
	    cur->left = NULL;
	    cur->right = NULL;
	    q.pop();
            if (!new_root) {
                new_root = cur;
            } 
	    
	    if (!q.empty()) {
    	        cur->right = q.front();
	    } else {
		cur->right = NULL;
	    }
        }
        
        return new_root;
    }
};

int main () 
{
	Solution s;
	TreeNode root(5, new TreeNode(3, new TreeNode(2, new TreeNode(1, NULL, NULL), NULL), new TreeNode(4, NULL, NULL)), new TreeNode(6, NULL, new TreeNode(8, new TreeNode(7, NULL, NULL), new TreeNode(9, NULL, NULL))));
	TreeNode* n;

	n = s.increasingBST(&root);
}

