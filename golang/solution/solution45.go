package solution

import "fmt"

// 跳跃游戏2 从nums[0]跳到最后位置最少步数
func jump(nums []int) int {
	border := 0
	steps := 0
	maxPosition := 0

	for i := 0; i < len(nums)-1; i++ {
		maxPosition = max(maxPosition, nums[i]+i)
		if i == border {
			border = maxPosition
			steps = steps + 1
		}
	}

	return 0
}

func Solution45() {
	nums := []int{2, 3, 4, 1, 1}
	fmt.Println(jump(nums))
}
