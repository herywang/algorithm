package solution

import "fmt"

// 跳跃游戏 - 从nums[0]点起跳，判断能否达到终点
func canJump(nums []int) bool {
	// 最远能跳的距离
	var k int = 0
	for i := 0; i < len(nums); i++ {
		if i > k {
			return false
		}
		k = max(k, nums[i]+i)
	}
	return true
}

func Solution55() {
	nums := []int{2, 3, 1, 1, 4}
	fmt.Println(canJump(nums))
}
