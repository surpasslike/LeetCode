#include <iostream>
#include <vector>

using namespace std;
/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for(i = 0; i < nums.size() - 1; i++) {
            for(j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // 返回一个空的vector
    }
};

int main() {
    Solution sol;

    // 输入数组大小
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // 输入数组元素
    vector<int> nums(n);
    cout << "Enter " << n << " integers:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 输入目标值
    int target;
    cout << "Enter target value: ";
    cin >> target;

    // 调用函数并获取结果
    vector<int> result = sol.twoSum(nums, target);

    // 打印结果
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
