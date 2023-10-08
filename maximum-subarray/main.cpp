#include <iostream>
#include <vector>
using namespace std;
// 最大子数组和

/*
记录一个错误的答案
代码逻辑基本上是对的，但有两个问题导致它不能正确运行：

初始化问题：
当你使用for循环从i = 0开始时，dp[i - 1]实际上是访问dp[-1]，这在std::vector中是不合法的。为了处理这种情况，你应该单独为i = 0的情况初始化dp[0]。
dp[0] = nums[0];
然后，你可以从i = 1开始循环，这样dp[i - 1]总是有效的。

初始化maxans的值：
你初始化maxans为-104，但题目指出nums[i]的范围是[-104, 104]，所以数组中的任意值都可能比-104大。最安全的方法是将maxans初始化为INT_MIN，这是C++中表示整数的最小值。
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
     if (nums.size() == 0)
        {
            return 0;
        }
        int maxans = -104;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxans = max(dp[i], maxans);
        }
        return maxans;
    }
};*/

// 正确答案如下
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int maxans = INT_MIN; // 使用INT_MIN
        vector<int> dp(nums.size());

        dp[0] = nums[0]; // 初始化dp[0]
        maxans = dp[0];  // 同样地，更新maxans

        for (int i = 1; i < nums.size(); i++) // 从i = 1开始
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxans = max(dp[i], maxans);
        }
        return maxans;
    }
};
/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。



示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23


提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104


进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
*/