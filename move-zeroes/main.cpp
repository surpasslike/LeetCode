#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 使用 remove 将所有非零元素移到数组前面，并返回新的结束位置
        auto end = remove(nums.begin(), nums.end(), 0);

        // 将从新的结束位置到数组真实结束位置之间的所有元素设为0
        for (auto it = end; it != nums.end(); ++it)
        {
            *it = 0;
        }
    }
};

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]

提示:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

进阶：你能尽量减少完成的操作次数吗？

我的思路:
1 0 3 6 0 8 9

1036089
9103608
8910360


*/