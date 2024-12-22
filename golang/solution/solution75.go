package solution

import "fmt"

// 颜色分类
func sortColors(nums []int) {
	var headPtr int = 0
	var n int = len(nums)
	for i := headPtr; i < n; i++ {
		if nums[i] == 0 {
			nums[headPtr], nums[i] = nums[i], nums[headPtr]
			headPtr++
		}
	}

	for i := headPtr; i < n; i++ {
		if nums[i] == 1 {
			nums[headPtr], nums[i] = nums[i], nums[headPtr]
			headPtr++
		}
	}
}

func Solution75() {
	nums := []int{2, 0, 2, 1, 1, 0}
	sortColors(nums)
	fmt.Println(nums)
}
