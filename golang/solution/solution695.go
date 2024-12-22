package solution

import "fmt"

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

// 岛屿的最大面积
func maxAreaOfIsland(grid [][]int) int {
	row, col := len(grid), len(grid[0])
	var maxArea int = 0
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			maxArea = max(maxArea, area(grid, i, j))
		}
	}
	return maxArea
}

func area(grid [][]int, r int, c int) int {
	if r < 0 || r >= len(grid) || c < 0 || c >= len(grid[0]) {
		// out of bound
		return 0
	}
	if grid[r][c] == 0 || grid[r][c] == 2 {
		return 0
	}

	grid[r][c] = 2
	return 1 + area(grid, r-1, c) + area(grid, r+1, c) + area(grid, r, c-1) + area(grid, r, c+1)
}

func Solution695() {
	var grid [][]int = [][]int{
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	}
	maxArea := maxAreaOfIsland(grid)

	fmt.Println("最大岛屿面积：", maxArea)
}
