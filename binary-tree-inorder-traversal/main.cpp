#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 二叉树的中序遍历
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution// 递归
// {
// public:
//     void inorder(TreeNode *root, vector<int> &res)
//     {
//         if (!root)
//             return;
//         inorder(root->left, res);
//         res.push_back(root->val);
//         inorder(root->right, res);
//     }

//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> res2;
//         inorder(root, res2);
//         return res2;
//     }
// };

class Solution
{
public:
    // 定义一个枚举类型Color，它有两个可能的值：WHITE和GRAY
    enum Color
    {
        WHITE,
        GRAY
    };

    /*
    使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
    如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
    如果遇到的节点为灰色，则将节点的值输出。
    */

    // 定义一个名为inorderTraversal的公有成员函数，它接收一个TreeNode指针作为参数并返回一个整数向量
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 定义一个整数向量res，用于存储中序遍历的结果
        vector<int> res;

        // 定义一个栈，栈中的元素是一对Color和TreeNode指针
        stack<pair<Color, TreeNode *>> stack;

        // 将一对{WHITE, root}压入栈中
        stack.push({WHITE, root});

        // 当栈不为空时，执行循环
        while (!stack.empty())
        {
            // 从栈顶取出一对元素并存入color和node中，然后从栈中移除这对元素
            Color color = stack.top().first;
            TreeNode *node = stack.top().second;
            stack.pop();

            // 如果node是NULL，跳过这次循环的剩余部分，执行下一次循环
            if (node == NULL)
                continue;

            // 如果color等于WHITE，按照中序遍历的顺序，依次将节点的右孩子、节点本身和左孩子压入栈中
            if (color == WHITE)
            {
                stack.push({WHITE, node->right});
                stack.push({GRAY, node});
                stack.push({WHITE, node->left});
            }
            else
            {
                // 如果color不等于WHITE（即color等于GRAY），将节点的值添加到res向量中
                res.push_back(node->val);
            }
        }

        // 返回存储中序遍历结果的res向量
        return res;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<TreeNode *> nodes;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;

        nodes.push_back(new TreeNode(val));
    }

    for (int i = 0; i < n; i++)
    {
        int leftIndex, rightIndex;
        cout << "Enter left and right child indices for node " << i + 1 << " (-1 for no child): ";
        cin >> leftIndex >> rightIndex;

        if (leftIndex != -1)
            nodes[i]->left = nodes[leftIndex];
        if (rightIndex != -1)
            nodes[i]->right = nodes[rightIndex];
    }

    Solution sol;
    vector<int> res = sol.inorderTraversal(nodes[0]);

    cout << "Inorder Traversal: ";
    for (const int &num : res)
        cout << num << ' ';
    cout << '\n';

    for (auto &node : nodes)
        delete node;

    return 0;
}

/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。



示例 1：


输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]


提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100

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