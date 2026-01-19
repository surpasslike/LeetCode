package leetcode.editor.cn;//给你一个字符串 s，找到 s 中最长的 回文 子串。
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 双指针 字符串 动态规划 👍 7961 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String longestPalindrome(String s) {
        int sLength = s.length();
        String answer = null;
        int max = 0;

        for (int i = 0; i < sLength; i++) {
            String ou = expandAroundCenter(s, i, i + 1);
            String ji = expandAroundCenter(s, i, i);
            String res = ou.length() > ji.length() ? ou : ji;
            if (res.length() > max) {
                max = res.length();
                answer = res;
            }
        }

        return answer;
    }

    private String expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right <= s.length() - 1 && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
//        return right - left - 1;// 不包含两端
//        substring: [)       // 包含左侧不包含右侧,左闭右开
        return s.substring(left + 1, right);
    }



    /*
    * 左右指针（对撞指针）
        这是最常见的一种方式。就像两个人在一座独木桥的两头，相对而行，直到相遇。
        应用场景： 通常用于已排序的数组。

        形象理解： 假设你要在一个升序数组里找两个数，让它们的和等于 10。
        左手指指向最小的（最左边），右手指指向最大的（最右边）。

        如果两数之和大于 10，说明右边那个数太大了，右手指往左移一步。
        如果两数之和小于 10，说明左边那个数太小了，左手指往右移一步。
    * */
    public int[] twoSum(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return new int[]{left, right};
            } else if (sum < target) {
                left++; // 嫌小了，左指针右移
            } else {
                right--; // 嫌大了，右指针左移
            }
        }
        return new int[]{-1, -1};
    }

    /*
    * 快慢指针
        这两根手指在同一个起点出发，但“跑步”的速度不一样。

        应用场景： 处理链表（比如判断有没有环）或者数组去重。
        形象理解： 想象在操场跑步。
        快指针（兔子）： 每次跑两步。
        慢指针（乌龟）： 每次跑一步。

        如果操场是圆形的（链表有环），兔子总有一天会从背后追上乌龟；如果操场是直的，兔子会先到达终点。
    * */
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        ListNode slow = head; // 乌龟
        ListNode fast = head; // 兔子

        while (fast != null && fast.next != null) {
            slow = slow.next;          // 慢指针走一步
            fast = fast.next.next;     // 快指针走两步

            if (slow == fast) {        // 遇见了，说明有环
                return true;
            }
        }
        return false;
    }


}
//leetcode submit region end(Prohibit modification and deletion)
