package solution

import (
	"fmt"
	"math"
	"sort"
)

func nextPermutation(nums []int) {
	var i int = len(nums) - 1
	for ; i > 0; i-- {
		// 从后往前找第一个降序序列
		if nums[i] > nums[i-1] {
			break
		}
	}

	if i == 0 {
		// 未找到降序序列，说明是升序排列，则将真个切片逆序排列即可
		sort.Ints(nums)
		return
	}

	// i != 0, 找到了一个从后往前的降序数字 nums[i-1], 此时开始从 第 i个位置处往后找一个尽可能小的、大于 nums[i-1]的数字
	var tmpMin int = math.MaxInt32
	var tmpMinIndex int = -1

	for k := i; k < len(nums); k++ {
		if nums[k] < tmpMin && nums[k] > nums[i-1] {
			tmpMin = nums[k]
			tmpMinIndex = k
		}
	}

	var _t int = nums[i-1]
	nums[i-1] = nums[tmpMinIndex]
	nums[tmpMinIndex] = _t

	sort.Ints(nums[i:])
}

func Solution31() {
	nums := []int{100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	nextPermutation(nums)
	fmt.Println(nums)
}
