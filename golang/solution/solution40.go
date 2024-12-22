package solution

import (
	"fmt"
	"sort"
)

// 组合数总和2

func combinationSum2(candidates []int, target int) [][]int {
	var (
		path   []int   = make([]int, 0)
		result [][]int = make([][]int, 0)
		dfs    func(begin int, sum int)
	)

	dfs = func(begin, sum int) {
		if sum == 0 {
			result = append(result, append([]int{}, path...))
			return
		}

		for i := begin; i < len(candidates); i++ {
			if sum-candidates[i] < 0 {
				break
			}
			if i > begin && candidates[i] == candidates[i-1] {
				continue
			}
			path = append(path, candidates[i])
			dfs(i+1, sum-candidates[i])
			path = path[:len(path)-1]
		}
	}

	sort.Ints(candidates)
	dfs(0, target)
	return result
}

func Solution40() {
	candidates := []int{10, 1, 2, 7, 6, 1, 5}
	result := combinationSum2(candidates, 8)
	fmt.Println(result)
}
