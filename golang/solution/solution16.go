package solution

import (
	"fmt"
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	var closestVal float64 = float64(math.MaxInt32)
	var sumRes float64 = 0
	sort.Ints(nums)
	for i := 0; i <= len(nums)-3; i++ {
		nums1 := nums[i]
		left, right := i+1, len(nums)-1
		for left < right {
			sumVal := nums1 + nums[left] + nums[right]
			if math.Abs(float64(sumVal-target)) < closestVal {
				closestVal = math.Abs(float64(sumVal - target))
				sumRes = float64(sumVal)
			}
			if sumVal == target {
				// closestVal == 0
				return sumVal
			} else if sumVal < target {
				for left < right && nums[left] == nums[left+1] {
					left++
				}
				left++
			} else {
				for left < right && nums[right] == nums[right-1] {
					right--
				}
				right--
			}
		}
	}
	return int(sumRes)
}

func Solution16() {
	var nums []int = []int{-1, 2, 1, -4}
	var n int = 1
	fmt.Println(threeSumClosest(nums, n))
	fmt.Println(threeSumClosest([]int{0, 1, 2}, 3))
}
