package solution

import (
	"fmt"
)

// 最大连续子序列之和 经典动态规划问题
func maxSubArray(nums []int) int {
	length := len(nums)
	if length == 1 {
		return nums[0]
	}
	var dp []int = make([]int, length)
	dp[0] = nums[0]
	var maxVal int = nums[0]
	for i := 1; i < length; i++ {
		if nums[i]+dp[i-1] >= nums[i] {
			dp[i] = nums[i] + dp[i-1]
		} else {
			dp[i] = nums[i]
		}
		if maxVal < dp[i] {
			maxVal = dp[i]
		}
	}
	return maxVal
}

func Solution53() {
	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
}
