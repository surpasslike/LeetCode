#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//TODO:未完成
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        if (!root)
        {
            return;
        }

        if (root->left != nullptr|| root->right != nullptr)
        {
            maxDepth(root->left);
            maxDepth(root->right);
            depth++;
        }
        return depth;
    }
};

int main()
{

}