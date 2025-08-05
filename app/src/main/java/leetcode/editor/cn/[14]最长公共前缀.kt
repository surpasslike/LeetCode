//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 如果非空，则仅由小写英文字母组成 
// 
//
// Related Topics 字典树 数组 字符串 👍 3377 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        if (strs.isEmpty()) {
            return ""
        } else if (strs.size == 1) {
            return strs[0]
        }
        var solution = ""
        var isEqually = false

        // j 代表元素的第j个位置
        for (j in 0 until strs[0].length) {
            // 标记第一个元素的第j个位置
            val note = strs[0][j]

            solution.plus(strs[0][j])

            // i 代表第i个元素
            for (i in strs.indices) {
                if (strs[i].length >= j + 1 && strs[i][j] == note) {
                    isEqually = true
                } else {
                    isEqually = false
                    break
                }
            }

            if (isEqually) {
                solution = solution.plus(strs[0][j])
            } else {
                break
            }
        }
        return solution
    }

    /*
    * 官方答案
    *
    *
    * fun longestCommonPrefix(strs: Array<String>?): String {
        if (strs == null || strs.size == 0) {
            return ""
        }
        val length = strs[0].length
        val count = strs.size
        for (i in 0 until length) {
            val c = strs[0][i]
            for (j in 1 until count) {
                if (i == strs[j].length || strs[j][i] != c) {
                    return strs[0].substring(0, i)
                }
            }
        }
        return strs[0]
    }
    *
    * */
}
//leetcode submit region end(Prohibit modification and deletion)
