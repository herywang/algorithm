package solution

import (
	"fmt"
	"sort"
)

// 搜索旋转排序数组 II
func search2(nums []int, target int) bool {
	if len(nums) == 0 {
		return false
	} else if len(nums) == 1 {
		return nums[0] == target
	}
	split := len(nums)
	for i := 1; i < len(nums); i++ {
		if nums[i-1] > nums[i] {
			split = i
			break
		}
	}
	var ans int = sort.SearchInts(nums[:split], target)
	if ans != split && nums[ans] == target {
		return true
	}

	ans = sort.SearchInts(nums[split:], target)

	return ans != len(nums)-split && nums[ans+split] == target
}

func Solution81() {
	fmt.Println(search2([]int{2, 5, 6, 0, 0, 1, 2}, 0))
	fmt.Println(search2([]int{2, 5, 6, 0, 0, 1, 2}, 3))
}
