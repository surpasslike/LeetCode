package leetcode.editor.cn;//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 11267 👎 0


import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionlengthOfLongestSubstring {
    public int lengthOfLongestSubstring(String s) {
        char[] ss = s.toCharArray(); // 字符串转为数组
        Set<Character> set = new HashSet<>(); // Set的特点是不允许重复元素,可以通过contains方法快速判断是否已经有某个字符
        int res = 0; // 结果

        for (int left = 0, right = 0; right < s.length(); right++) {
            char ch = ss[right]; // 当前要加入窗口的字符
            while (set.contains(ch)) { // 如果当前窗口已经有这个字符了
                set.remove(ss[left]); // 那么聪set中一冲最左边界的字符
                left++;
            }

            set.add(ch);
            res = Math.max(right - left + 1, res);
        }
        return res;
    }

    public int lengthOfLongestSubstring2(String s) {
        int sLength = s.length();
        if (sLength < 2) {
            return sLength;
        }
        int thisLength = 1;

        HashMap<Character, Integer> matchString = new HashMap<>();
        for (int i = 0; i < sLength; i++) {
            matchString.put(s.charAt(i), matchString.getOrDefault(s.charAt(i), 0) + 1);

            if (matchString.get(s.charAt(i)) > 1) {
                thisLength = Math.max(thisLength, s.substring(0, i + 1).length());
            }
        }

        return thisLength;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
