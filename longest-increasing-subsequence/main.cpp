#include <iostream>
#include <vector>
using namespace std;
//最长递增子序列
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        vector<int> dp(nums.size(), 1);       // 创建辅助数组dp，初始化为1，表示以每个位置为结尾的最长递增子序列长度至少为1
        int maxans = 1;                       // 记录最长递增子序列的长度，初始化为1
        for (int i = 1; i < nums.size(); i++) // 遍历数组，从第二个元素开始
        {
            for (int j = 0; j < i; j++) // 在位置i之前的元素进行遍历
            {
                if (nums[j] < nums[i]) // 如果存在比nums[i]小的元素nums[j]
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxans = max(maxans, dp[i]); // 更新最大值
        }
        return maxans;
    }
};

int main()
{

    return 0;
}


/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
 
*/