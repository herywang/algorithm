package solution

import "fmt"

func subsets(nums []int) [][]int {

	var (
		ans  [][]int = make([][]int, 0)
		dfs  func(int)
		path []int = make([]int, 0)
	)
	dfs = func(begin int) {
		ans = append(ans, append([]int{}, path...))
		for i := begin; i < len(nums); i++ {
			path = append(path, nums[i])
			dfs(i + 1)
			path = path[:len(path)-1]
		}
	}
	dfs(0)
	return ans
}

// 子集
func Solution78() {
	fmt.Println(subsets([]int{1, 2, 3}))
}
