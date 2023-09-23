#include <iostream>
#include <vector>

using namespace std;
/*给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。*/

typedef char BTDataType;

typedef struct TreeNode
{
    BTDataType data;        // 当前节点值域
    struct TreeNode *left;  // 指向当前节点左孩子
    struct TreeNode *right; // 指向当前节点右孩子
} BTNode;

class Solution
{
public:
    vector<int> my_print;

    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root != NULL)
        {
            InOrder(root->left);
            InOrder(root);
            InOrder(root->right);
        }
    }
};

void InOrder(TreeNode *note)
{
    cout<<&note<<endl;
}


int main()
{
    //明天起床验证并修订

    return 0;
}