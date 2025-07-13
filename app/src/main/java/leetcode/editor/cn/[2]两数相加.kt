import leetcode.editor.cn.ListNode
import kotlin.math.max

//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
//
// Related Topics 递归 链表 数学 👍 11374 👎 0


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
class SolutionAddTwoNumbers {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        val l1IntArray = getArray(l1)
        val l2IntArray = getArray(l2)
        val l3IntArray = mutableListOf<Int>()
        var l4num = 0 // 十以上的余数

        while (!l1IntArray.isNullOrEmpty() || !l2IntArray.isNullOrEmpty()) {
            var l1num = 0
            var l2num = 0
            var l3num: Int  // 十以下的总和

            if (!l1IntArray.isNullOrEmpty()) {
                l1num = l1IntArray[0]
                l1IntArray.removeAt(0)
            }

            if (!l2IntArray.isNullOrEmpty()) {
                l2num = l2IntArray[0]
                l2IntArray.removeAt(0)
            }

            if (l1num + l2num + l4num > 9) {
                l3num = (l1num + l2num + l4num) - 10
                l4num = (l1num + l2num + l4num) / 10
            } else {
                l3num = l1num + l2num + l4num
                l4num = 0
            }

            l3IntArray.add(l3num)
        }
        // 如果由余数的存在,则多一个数字
        if (l4num != 0) {
            l3IntArray.add(l4num)
        }

        return getListNode(l3IntArray)
    }

    // 用数组正序显示链表
    fun getArray(listNode: ListNode?): MutableList<Int>? {
        var listNode = listNode
        val array: MutableList<Int> = mutableListOf()
        while (listNode != null) {
            array.add(listNode.`val`)
            listNode = listNode.next
        }
        return array
    }

    // 用链表正序显示数组
    fun getListNode(array: MutableList<Int>?): ListNode? {
        if (array.isNullOrEmpty()) {
            return null
        }
        // 假设array为[10,20]

        // 创建一个只有一个节点为0的链表(也就是哑节点)
        // dummy 作为链表头的锚点，它不能动；
        val dummy = ListNode(0)
        // 创建current, 表示dummy所指向的数据结构, 指向dummy本身，用作“游标指针”
        // current 是“工具人”，不断往后走，把新节点接上去
        var current = dummy

        // 每次循环将 value 包装成新节点，并接到 current.next 上
        // dummy 本身不变，但它的 next 不断增长，构建出完整链表
        for (value in array) {
            // current 是用于构建链表的指针，初始与 dummy 相同
            // 因此这里指的是dummy由dummy:0->null变成了dummy:0->10
            // 也就是和current由0->null变成了0->10
            current.next = ListNode(value)

            // 这里dummy没变,依旧是dummy:0->10->null
            // 这里current由0->10变成了10
            current = current.next
        }
        return dummy.next
    }

}
//leetcode submit region end(Prohibit modification and deletion)
