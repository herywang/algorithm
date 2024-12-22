package solution

import (
	"fmt"
	"strconv"
)

// 排列序列

func getPermutation(n int, k int) string {
	if n == 0 {
		return ""
	}
	// 初始化数组
	var nums []int = make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	var (
		path      []int  = make([]int, 0)
		res       []int  = nil
		isVisited []bool = make([]bool, n)
		count     int    = 0
		dfs       func()
		ans       string = ""
	)

	dfs = func() {
		if count == k {
			return
		}

		if n == len(path) {
			res = append([]int{}, path...)
			count++
			return
		}

		for i := 0; i < n; i++ {
			if count == k {
				return
			}
			if isVisited[i] {
				continue
			}
			isVisited[i] = true
			path = append(path, nums[i])
			dfs()
			path = path[:len(path)-1]
			isVisited[i] = false
		}
	}

	dfs()

	for _, v := range res {
		ans = ans + strconv.Itoa(v)
	}
	return ans
}

func Solution60() {
	fmt.Println(getPermutation(3, 3))
}
