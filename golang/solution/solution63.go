package solution

import "fmt"

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	r, c := len(obstacleGrid), len(obstacleGrid[0])
	// 初始化一个二维数组，记录每个表格的路径数量
	record := make([][]int, r)
	for i := 0; i < r; i++ {
		record[i] = make([]int, c)
	}
	// 初始化第一行第一列
	for i := 0; i < c; i++ {
		if obstacleGrid[0][i] == 1 {
			break
		}
		record[0][i] = 1
	}
	for i := 0; i < r; i++ {
		if obstacleGrid[i][0] == 1 {
			break
		}
		record[i][0] = 1
	}

	// 动态规划开始遍历
	for i := 1; i < r; i++ {
		for j := 1; j < c; j++ {
			if obstacleGrid[i][j] == 1 {
				continue
			}
			record[i][j] = record[i-1][j] + record[i][j-1]
		}
	}

	return record[r-1][c-1]
}

func Solution63() {
	fmt.Println("请输入矩阵行、列，用空格分割:")
	var row, col int
	fmt.Scanln(&row, &col)

	fmt.Println("请输入矩阵内容，用空格分割:")
	obstacleGrid := make([][]int, row)
	for i := 0; i < row; i++ {
		obstacleGrid[i] = make([]int, col)
		for j := 0; j < col; j++ {
			fmt.Scan(&obstacleGrid[i][j])
		}
	}

	fmt.Println(uniquePathsWithObstacles(obstacleGrid))
}
