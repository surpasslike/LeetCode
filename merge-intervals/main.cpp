#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 合并区间
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return {};
        }

        sort(intervals.begin(), intervals.end()); // 按照区间的起始位置进行排序

        vector<vector<int>> merged; // 用于后续存储合并后的区间

        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0], R = intervals[i][1]; // 一左一右
            if (!merged.size() || merged.back()[1] < L)   // 举例:vector<vector<int>> merged = {{1, 3}, {4, 7}, {8, 10}}; merged.back()[0]将返回8，而merged.back()[1]将返回10。
            {
                merged.push_back({L, R});
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], R); // 此时不用push_back,只需要更换merged.back()[1]即可,merged.back()[0]不用变
            }
        }
        return merged;
    }
};
/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/