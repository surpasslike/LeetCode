#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 和为 K 的子数组

class Solution // 这个是官方题解
{
public:
    int
    subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto &x : nums)
        {
            pre += x;
            if (mp.find(pre - k) != mp.end())
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

/*
class Solution // 这个答案正确是正确,但是时间复杂度太高了,为O(n²),需要想办法降低到O(n),推测用哈希来降低时间复杂度
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        vector<int> theSumOfPrefixes(nums.size());
        theSumOfPrefixes[0] = nums[0];
        int answer = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            theSumOfPrefixes[i] = theSumOfPrefixes[i - 1] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int sum = 0;

                if (i == 0)
                {
                    sum = theSumOfPrefixes[j];
                }
                else
                {
                    sum = theSumOfPrefixes[j] - theSumOfPrefixes[i - 1];
                }
                if (sum == k)
                {
                    answer++;
                }
            }
        }
        return answer;
    }
};
*/

/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。

子数组是数组中元素的连续非空序列。



示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2


提示：

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

/*
思路:
先求取每个位置的前缀和
再分别相减判断是否等于k
*/