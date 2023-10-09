#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 移动零
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
详细解析
1. std::remove 函数的目标是从给定的范围内“移除”指定的元素。但这里的“移除”不是实际的删除操作，而是将其他不被“移除”的元素向前移动，覆盖那些要“移除”的元素。

工作原理：std::remove 会遍历给定的范围，将不是指定“移除”值的所有元素移动到范围的前面。它返回一个迭代器，该迭代器指向“移除”后的新的逻辑结尾。

例如，对于数组 nums = [0, 1, 0, 3, 12]：

执行 std::remove(nums.begin(), nums.end(), 0) 之后，数组的内容可能变成：[1, 3, 12, x, x]，其中 x 代表未定义的值（可能是 0，也可能是其他值，因为 std::remove 不保证覆盖它们）。

返回的迭代器 end 将指向数组中第一个 x 的位置。

auto 是 C++11 引入的一个关键字，它允许编译器自动为变量推导其类型。在这里，auto 被用来声明一个名为 end 的迭代器变量，它的类型是由 std::remove 返回的迭代器的类型推导出来的。这使得代码更加简洁，因为我们不需要明确地写出迭代器的完整类型。

这是怎么工作的呢？考虑以下过程：
使用两个指针，一个快指针（遍历整个数组）和一个慢指针（指向下一个可能被替换的位置）。
当快指针发现一个不是要“移除”的元素时，它将该元素复制到慢指针的位置，然后两个指针都前进。
如果快指针发现一个要“移除”的元素，它就前进，而慢指针保持不变。
这样，慢指针左边的所有元素都是不需要“移除”的，而右边可能包含一些要“移除”的和不需要“移除”的元素。

2. 后续操作
当 std::remove 完成后，返回的迭代器 end 指向数组中第一个要“移除”的元素（在我们的例子中，是0）。因为 std::remove 只是重新排列了数组，我们现在知道 end 之后的所有元素都是0。

现在我们只需要将从 end 到数组真正的结束位置之间的所有元素设置为0。实际上，由于这些位置已经是0，这个步骤可能是冗余的，但为了确保正确性并使算法更具通用性，我们仍然执行这个步骤。

综上所述，这种方法利用了 std::remove 的特性，先将所有非零元素移到数组的前面，然后确保数组的剩余部分都是0。这是一种高效且简洁的方法来解决“移动零”这个问题。
*/

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

/*
官方题解:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
*/