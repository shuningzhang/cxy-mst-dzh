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
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> s;
        int count = 0;
        TreeNode* cur = NULL;
        
        if (!root) {
            return 0;
        }
        
        s.push(root);
        cur = root;
        while (!s.empty() && cur) {
            while (cur->left) {
                cur = cur->left;
                s.push(cur);
            }
            
            while(!cur->right) {
                count ++;
                if (count == k) {
                    return cur->val;
                }
                cur = s.top();
                s.pop();
            }
            
            if (cur->right) {
		count++;
		if (count == k) {
		    return cur->val;
		}
                cur = cur->right;               
            }
        }
        return count;
    }
};

int main () 
{
	Solution s;
	TreeNode root(3, new TreeNode(1, NULL, new TreeNode(2, NULL, NULL)), new TreeNode(4, NULL, NULL) );
	int n;

	n = s.kthSmallest(&root, 1);
}

