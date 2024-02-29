package solution

import (
	"fmt"
	"sort"
)

// 组合数总和1

func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var (
		result [][]int
		dfs    func(candidates []int, path []int, target int, begin int)
	)

	dfs = func(candidates, path []int, target, begin int) {
		if target == 0 {
			dest := make([]int, len(path))
			copy(dest, path)
			result = append(result, dest)
			return
		} else if target < 0 {
			return
		}
		for i := begin; i < len(candidates); i++ {
			path = append(path, candidates[i])
			dfs(candidates, path, target-candidates[i], i)
			path = path[:len(path)-1]
		}
	}

	combination := make([]int, 0)
	dfs(candidates, combination, target, 0)
	return result
}

func Solution39() {
	candidates := []int{2, 3, 5}
	fmt.Println(combinationSum(candidates, 8))
}
