package solution

import (
	"fmt"
	"sort"
)

// 3 Sum

func threeSum(nums []int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	var res [][]int = make([][]int, 0)

	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			break
		}
		left, right := i+1, len(nums)-1
		for left < right {
			if nums[i]+nums[left]+nums[right] > 0 {
				right--
			} else if nums[i]+nums[left]+nums[right] < 0 {
				left++
			} else {
				var row []int = []int{nums[i], nums[left], nums[right]}
				res = append(res, row)
				for left < right && nums[left] == nums[left+1] {
					left++
				}
				for left < right && nums[right] == nums[right-1] {
					right--
				}
				left++
				right--
			}
		}

		for i < len(nums)-1 && nums[i] == nums[i+1] {
			i++
		}
	}
	return res
}

func Solution15() {
	var number []int = []int{-1, 0, 1, 2, -1, -4}

	var res [][]int = threeSum(number)

	for _, row := range res {
		fmt.Printf("[(%d) + (%d) + (%d) = 0]\n", row[0], row[1], row[2])
	}
}
