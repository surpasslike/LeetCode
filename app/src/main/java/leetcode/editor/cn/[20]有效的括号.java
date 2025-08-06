package leetcode.editor.cn;//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
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


import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionIsValidJava {
    public boolean isValid(String s) {

        if (s.length() % 2 == 1) {
            return false;
        }

        Map<Character, Character> map = new HashMap<Character, Character>() {{
            put(')', '('); // 第一个是key, 第二个是value
            put(']', '[');
            put('}', '{');
        }};

        Deque<Character> deque = new LinkedList<Character>();

        for (char ch : s.toCharArray()) { // 用于遍历字符串s的每一个字符
            if (map.containsKey(ch)) {
                if (deque.isEmpty() || map.get(ch) != deque.peek()) {
                    // peek() 查看栈顶元素（不移除），而 pop() 会移除。
                    return false;
                } else {
                    deque.pop();
                }
            } else {
                deque.push(ch);
            }
        }
        return deque.isEmpty();
    }
}
//leetcode submit region end(Prohibit modification and deletion)
