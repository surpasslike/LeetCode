#include <iostream>
#include <algorithm> 
#include <queue> 

using namespace std;

// 定义TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 辅助函数，用于将数组形式的树转化为实际的树结构
TreeNode* createTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < nums.size() && !q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (i < nums.size() && nums[i] != -1) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    // 示例1
    vector<int> nums1 = {3, 9, 20, -1, -1, 15, 7}; // -1表示null
    TreeNode* root1 = createTree(nums1);
    Solution s;
    cout << "Example 1: " << s.maxDepth(root1) << " (Expected: 3)" << endl;

    // 示例2
    vector<int> nums2 = {1, -1, 2}; // -1表示null
    TreeNode* root2 = createTree(nums2);
    cout << "Example 2: " << s.maxDepth(root2) << " (Expected: 2)" << endl;

    return 0;
}
