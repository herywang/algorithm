package solution

import "fmt"

// 不同路径
func uniquePaths(m int, n int) int {
	// 初始化一个二维数组，记录每个表格的路径数量
	record := make([][]int, m)
	for i := 0; i < m; i++ {
		record[i] = make([]int, n)
	}

	// 初始化第一行和第一列
	for i := 0; i < m; i++ {
		record[i][0] = 1
	}
	for i := 0; i < n; i++ {
		record[0][i] = 1
	}
	// 动态规划
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			record[i][j] = record[i-1][j] + record[i][j-1]
		}
	}
	return record[m-1][n-1]
}

func Solution62() {
	m := 3
	n := 7
	fmt.Println(uniquePaths(m, n))
}
