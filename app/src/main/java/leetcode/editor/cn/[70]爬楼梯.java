package leetcode.editor.cn;//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：2
//解释：有两种方法可以爬到楼顶。
//1. 1 阶 + 1 阶
//2. 2 阶 
//
// 示例 2： 
//
// 
//输入：n = 3
//输出：3
//解释：有三种方法可以爬到楼顶。
//1. 1 阶 + 1 阶 + 1 阶
//2. 1 阶 + 2 阶
//3. 2 阶 + 1 阶
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 45 
// 
//
// Related Topics 记忆化搜索 数学 动态规划 👍 3985 👎 0


import android.animation.IntArrayEvaluator;

import java.lang.reflect.Array;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionclimbStairs {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prev = 1;
        int curr = 2;

        int ans = 0;

        for (int i = 3; i <= n; i++) {
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }

        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
