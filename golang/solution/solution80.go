package solution

import "fmt"

// 删除有序数组中的重复项II

func removeDuplicates2(nums []int) int {
	if len(nums) <= 2 {
		return len(nums)
	}
	var slow, fast int = 2, 2
	for ; fast < len(nums); fast++ {
		if nums[slow-2] != nums[fast] {
			nums[slow] = nums[fast]
			slow++
		}
	}
	return slow
}

func Solution80() {
	var nums []int = []int{1, 1, 1, 2, 2, 3}
	n := removeDuplicates2(nums)
	for i := 0; i < n; i++ {
		fmt.Println(nums[i])
	}
}
