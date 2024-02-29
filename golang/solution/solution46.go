package solution

import "fmt"

// 全排列

func permute(nums []int) [][]int {
	var (
		ans    [][]int = make([][]int, 0)
		path   []int   = make([]int, 0)
		isUsed []bool  = make([]bool, len(nums))
		dfs    func()
	)

	dfs = func() {
		if len(path) == len(nums) {
			ans = append(ans, append([]int{}, path...))
			return
		}
		for i := 0; i < len(nums); i++ {
			if isUsed[i] {
				continue
			}
			isUsed[i] = true
			path = append(path, nums[i])
			dfs()
			path = path[:len(path)-1]
			isUsed[i] = false
		}
	}
	dfs()
	return ans
}

func Solution46() {
	fmt.Println(permute([]int{1, 2, 3}))
}
