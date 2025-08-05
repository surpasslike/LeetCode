//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 每个右括号都有一个对应的相同类型的左括号。 
// 
//
// 
//
// 示例 1： 
//
// 
// 输入：s = "()" 
// 
//
// 输出：true 
//
// 示例 2： 
//
// 
// 输入：s = "()[]{}" 
// 
//
// 输出：true 
//
// 示例 3： 
//
// 
// 输入：s = "(]" 
// 
//
// 输出：false 
//
// 示例 4： 
//
// 
// 输入：s = "([])" 
// 
//
// 输出：true 
//
// 示例 5： 
//
// 
// 输入：s = "([)]" 
// 
//
// 输出：false 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 仅由括号 '()[]{}' 组成 
// 
//
// Related Topics 栈 字符串 👍 4770 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    fun isValid(s: String): Boolean {
        val sLength = s.length
        val solution = ArrayDeque<String>()
        for (i in 0 until sLength) {
            solution.add(s[i].toString())

            for (j in 0 until solution.size) {
                if (solution.size >= 2) {
                    if (compare(solution[solution.size - 2], solution[solution.size - 1])) {
                        solution.removeLast()
                        solution.removeLast()
                    }
                }
            }
        }
        return solution.isEmpty()
    }

    private fun compare(num1: String?, num2: String?): Boolean {
        return (num1 == "(" && num2 == ")") || (num1 == "[" && num2 == "]") || (num1 == "{" && num2 == "}")
    }

    /*
    * 官方答案如下:
    *
    * fun isValid(s: String): Boolean {
        val n = s.length
        if (n % 2 == 1) {
            return false
        }

        val pairs: HashMap<Char?, Char?> = object : HashMap<Char?, Char?>() {
            init {
                put(')', '(')
                put(']', '[')
                put('}', '{')
            }
        }
        val stack: Deque<Char> = LinkedList()
        for (i in 0 until n) {
            val ch = s[i]
            if (pairs.containsKey(ch)) {
                if (stack.isEmpty() || stack.peek() !== pairs[ch]) {
                    return false
                }
                stack.pop()
            } else {
                stack.push(ch)
            }
        }
        return stack.isEmpty()
    }
    *
    * */

}
//leetcode submit region end(Prohibit modification and deletion)
