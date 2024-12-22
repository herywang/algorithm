package solution

import "fmt"

func numIslands(grid [][]byte) int {
	var numIslandsRes int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '1' {
				numIslandsRes++
				dfs1(grid, i, j)
			}
		}
	}
	return numIslandsRes
}

func dfs1(grid [][]byte, i int, j int) {
	if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) {
		return
	}
	if grid[i][j] == '0' {
		return
	}

	grid[i][j] = '0'
	dfs1(grid, i-1, j)
	dfs1(grid, i+1, j)
	dfs1(grid, i, j-1)
	dfs1(grid, i, j+1)
}

func Solution200() {
	var grid [][]byte = [][]byte{
		{'0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
		{'0', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '1', '0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '0'},
		{'0', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0'},
	}
	fmt.Println(numIslands(grid))
}
