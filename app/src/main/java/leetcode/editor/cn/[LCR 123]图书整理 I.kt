import leetcode.editor.cn.ListNode

//书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放
//回到书架上。请倒序返回这个书单链表。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [3,6,4,1]
//
//输出：[1,4,6,3]
// 
//
// 
//
// 提示： 
//
// 0 <= 链表长度 <= 10000 
//
// Related Topics 栈 递归 链表 双指针 👍 488 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun reverseBookList(head: ListNode?): IntArray {
        var intArray = mutableListOf<Int>()
        var head = head
        while (head != null) {
            // intArray的add是从前往后,不是从后往前
            intArray.add(head.`val`)
            head = head.next
        }
        // intArray.reversed()返回当前数组的倒序,返回了一个新数组,没有修改intArray
        // intArray.reverse()返回当前数组的倒序,并同时修改了intArray
        return intArray.reversed().toIntArray()
    }
}
//leetcode submit region end(Prohibit modification and deletion)
