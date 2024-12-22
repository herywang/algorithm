package solution

import "fmt"

// 搜索旋转数组最小值
func findMin(nums []int) int {
	if len(nums) == 0 {
		panic("nums can not be empty")
	} else if len(nums) == 1 {
		return nums[0]
	} else if len(nums) == 2 {
		return func(i, j int) int {
			if i < j {
				return i
			}
			return j
		}(nums[0], nums[1])
	} else {
		left, right := 0, len(nums)-1
		for left < right {
			mid := (left + right) / 2
			if nums[mid] < nums[right] {
				// 从[mid, right]是递增序列，最小值在 mid左边，收缩右边界
				right = mid
			} else {
				// 收缩左边界
				left = mid + 1
			}
		}
		return nums[left]
	}
}

func Solution153() {
	var nums []int = []int{4, 5, 6, 0, 1, 2, 3}
	res := findMin(nums)
	fmt.Println(res)
}
