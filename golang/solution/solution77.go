package solution

import "fmt"

func combine(n int, k int) [][]int {
	var (
		path []int = make([]int, 0)
		dfs  func(int)
		ans  [][]int = make([][]int, 0)
	)

	dfs = func(begin int) {
		if len(path) == k {
			ans = append(ans, append([]int{}, path...))
			return
		}
		for i := begin; i < n; i++ {
			path = append(path, i+1)
			dfs(i + 1)
			path = path[:len(path)-1]
		}
	}
	dfs(0)
	return ans
}

// 组合
func Solution77() {
	ans := combine(4, 2)
	for _, v := range ans {
		fmt.Println(v)
	}
}
