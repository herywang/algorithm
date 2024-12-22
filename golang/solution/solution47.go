package solution

import (
	"fmt"
	"sort"
)

// 全排列II
func permuteUnique(nums []int) [][]int {
	var (
		length int     = len(nums)
		ans    [][]int = make([][]int, 0)
		path   []int   = make([]int, length)
		isUsed []bool  = make([]bool, length)
		dfs    func(int)
	)
	dfs = func(k int) {
		if k == length {
			ans = append(ans, append([]int{}, path...))
			return
		}
		for i := 0; i < length; i++ {
			if isUsed[i] {
				continue
			}
			if i > 0 && nums[i] == nums[i-1] && !isUsed[i-1] {
				continue
			}
			isUsed[i] = true
			path[k] = nums[i]
			dfs(k + 1)
			isUsed[i] = false
		}
	}
	sort.Ints(nums)
	dfs(0)
	return ans
}

func Solution47() {
	// nums := []int{1, 1, 1, 2}
	nums := []int{3, 3, 0, 3}
	fmt.Println(permuteUnique(nums))
}
