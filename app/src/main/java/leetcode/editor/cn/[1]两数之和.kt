//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
// 
//
// 示例 3： 
//
// 
//输入：nums = [3,3], target = 6
//输出：[0,1]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 只会存在一个有效答案 
// 
//
// 
//
// 进阶：你可以想出一个时间复杂度小于 O(n²) 的算法吗？ 
//
// Related Topics 数组 哈希表 👍 19859 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class SolutionTwoSum {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val numsMap = HashMap<Int, Int>() //HashMap 里面两个参数: Key具体的值, Value索引位置
        /*
        * for (i in nums.indices)
            nums.indices: 这是一个扩展属性 (extension property)，适用于数组 (IntArray, Array<T>) 和集合 (List, Set 等)。
            它返回一个 IntRange 对象，这个范围代表了该数组或集合的所有有效索引 [2]。
            例如，如果 nums 是 intArrayOf(10, 20, 30)：
            nums.size 是 3。
            nums.indices 会返回 0..2 (一个包含 0, 1, 2 的整数范围)
        * */
        for (i in nums.indices){
            val complement = target - nums[i]
            if (numsMap.containsKey(complement))
            {
                // intArrayOf 里面数组成了IntArray格式数组
                return intArrayOf(numsMap[complement]!!, i)
            }
            // 对于HashMap而言: numMap[key] = value	通过 Key 获取 Value;
            // 和我理解的数组刚好相反, 数组是nums[i]=具体的值
            numsMap[nums[i]] = i
        }
        return intArrayOf()
    }


    // 第二种解法,时间复杂度高
    fun twoSum2(nums: IntArray, target: Int): IntArray {
        var output = intArrayOf()
        // 普通 forEach（只有元素值）
        // forEachIndexed的用法: 索引:index, 值:value
        nums.forEachIndexed { index1, value1 ->
            nums.forEachIndexed { index2, value2 ->
                if (index2 != index1 && value1 == target - value2) {
                    output = intArrayOf(index2, index1)
                }
            }
        }
        return output
    }

}
//leetcode submit region end(Prohibit modification and deletion)
