package solution

import "fmt"

// 岛屿的最大周长
func islandPerimeter(grid [][]int) int {
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				return area3(grid, i, j)
			}
		}
	}
	return 0
}

func area3(grid [][]int, r int, c int) int {
	if r < 0 || c < 0 || r >= len(grid) || c >= len(grid[0]) {
		// 越界，周长+1
		return 1
	}
	if grid[r][c] == 0 {
		return 1
	}
	if grid[r][c] == 2 {
		return 0
	}
	grid[r][c] = 2
	return area3(grid, r-1, c) + area3(grid, r+1, c) + area3(grid, r, c-1) + area3(grid, r, c+1)
}

func Solution463() {
	grid := [][]int{
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0},
	}
	fmt.Println(islandPerimeter(grid))
}
