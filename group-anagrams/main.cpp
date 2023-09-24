#include <iostream>
#include <vector>

using namespace std;

typedef int BTDataType;  // 修改数据类型为int

typedef struct TreeNode {
    BTDataType data;        // 当前节点值域
    struct TreeNode *left;  // 指向当前节点左孩子
    struct TreeNode *right; // 指向当前节点右孩子
} BTNode;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* node, vector<int>& result) {
        if (node) {
            helper(node->left, result);
            result.push_back(node->data);  // 将节点的值添加到结果向量中
            helper(node->right, result);
        }
    }
};

int main() {
    // 明天起床验证并修订
    printf("asds");
    return 0;
}
