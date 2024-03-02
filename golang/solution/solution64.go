package solution

import (
	"fmt"
)

// 最小路径和

func minPathSum(grid [][]int) int {
	var (
		r   int                = len(grid)
		c   int                = len(grid[0])
		dp  [][]int            = make([][]int, r)
		min func(int, int) int = func(i1, i2 int) int {
			if i1 < i2 {
				return i1
			}
			return i2
		}
	)

	for i := 0; i < r; i++ {
		dp[i] = make([]int, c)
	}
	dp[0][0] = grid[0][0]
	// 初始化dp矩阵第一行
	for i := 1; i < c; i++ {
		dp[0][i] = dp[0][i-1] + grid[0][i]
	}
	// 初始化dp矩阵第一列
	for i := 1; i < r; i++ {
		dp[i][0] = dp[i-1][0] + grid[i][0]
	}
	for i := 1; i < r; i++ {
		for j := 1; j < c; j++ {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		}
	}
	return dp[r-1][c-1]
}

func Solution64() {
	grid := [][]int{
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1},
	}
	fmt.Println(minPathSum(grid))
}
