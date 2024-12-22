package solution

import (
	"fmt"
	"sort"
)

// four sum = target , nums[i], nums[j], nums[k], nums[l] is distinck.
/**
 * 方法1 类似 three sum, 双指针遍历
 */
func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	var res [][]int = make([][]int, 0)
	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		val_1 := nums[i]
		for j := i + 1; j < len(nums)-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			val_2 := nums[j]
			left, right := j+1, len(nums)-1
			for left < right {
				val_3, val_4 := nums[left], nums[right]
				if val_1+val_2+val_3+val_4 == target {
					res = append(res, []int{val_1, val_2, val_3, val_4})
					for left < right && nums[left] == nums[left+1] {
						left++
					}
					for left < right && nums[right] == nums[right-1] {
						right--
					}
					left++
					right--
				} else if val_1+val_2+val_3+val_4 < target {
					left++
				} else {
					right--
				}
			}
		}
	}

	return res
}

func Solution18() {
	var res [][]int = fourSum([]int{1, 0, -1, 0, -2, 2}, 0)
	for _, row := range res {
		fmt.Printf("%d, %d, %d, %d\n", row[0], row[1], row[2], row[3])
	}
}
