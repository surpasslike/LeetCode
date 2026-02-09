package leetcode.editor.cn;//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。 
//
// 问总共有多少条不同的路径？ 
//
// 
//
// 示例 1： 
// 
// 
//输入：m = 3, n = 7
//输出：28 
//
// 示例 2： 
//
// 
//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向下
// 
//
// 示例 3： 
//
// 
//输入：m = 7, n = 3
//输出：28
// 
//
// 示例 4： 
//
// 
//输入：m = 3, n = 3
//输出：6 
//
// 
//
// 提示： 
//
// 
// 1 <= m, n <= 100 
// 题目数据保证答案小于等于 2 * 10⁹ 
// 
//
// Related Topics 数学 动态规划 组合数学 👍 2307 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 两个思路, 一个是动态规划(当前等于上两个孩子的和), 一个是组合数字(总步数固定,右下有多少组合?)
class SolutionuniquePaths {
    // 方案1组合数字
    public int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        long ans = 1;

        // 向右一定走m-1步, 向下一定走n-1步, 一共要走m+n-2步
        // 那就看m+n-2里面可以塞几个n-1 或者塞几个m-1就行
        // 用数学公式C m+n-2(C下侧)  n-1(C上侧)  也就是$C(n, k)$
        int k = Math.min(m - 1, n - 1); // =2
        int all = m + n - 2; // =4

        for (int i = 1; i <= k; i++) {
            ans = ans * (all - i + 1) / i;
        }

        return (int)ans;
    }

    // 方案2动态规划-迭代
    public int uniquePaths2(int m, int n) {
        // 考虑在迭代的时候赋值
        int[][] arr = new int[m][n];

        for (int i = 0; i < n; i++) {
            arr[0][i] = 1;
        }

        for (int i = 0; i < m; i++) {
            arr[i][0] = 1;
        }

        // 比如3*2, 那就是2+1=3个路
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }

        return arr[m - 1][n - 1];
    }


}
//leetcode submit region end(Prohibit modification and deletion)
