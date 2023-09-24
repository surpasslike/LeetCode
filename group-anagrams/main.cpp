#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    vector<TreeNode*> nodes;
    for(int i = 0; i < n; i++) {
        int val;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        
        nodes.push_back(new TreeNode(val));
    }
    
    for(int i = 0; i < n; i++) {
        int leftIndex, rightIndex;
        cout << "Enter left and right child indices for node " << i + 1 << " (-1 for no child): ";
        cin >> leftIndex >> rightIndex;
        
        if(leftIndex != -1) nodes[i]->left = nodes[leftIndex];
        if(rightIndex != -1) nodes[i]->right = nodes[rightIndex];
    }
    
    Solution sol;
    vector<int> res = sol.inorderTraversal(nodes[0]);
    
    cout << "Inorder Traversal: ";
    for(const int& num : res) cout << num << ' ';
    cout << '\n';
    
    for(auto& node : nodes) delete node;
    
    return 0;
}

/*
输入说明
首先输入一个整数n，表示二叉树的节点数目。
然后，对于每个节点，输入一个整数值，表示节点的值。
接下来，对于每个节点，输入两个整数，表示该节点的左右子节点的索引（从0开始）。如果没有子节点，输入-1。
输入例子
3
1
2
3
-1 1
2 -1
-1 -1
这将创建与前一个例子相同的二叉树。输出应该是：
Inorder Traversal: 1 3 2
*/