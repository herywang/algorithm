package solution

import "fmt"

func largestIsland(grid [][]int) int {
	row, col := len(grid), len(grid[0])

	// 复制一个二维数组，用于存储每个陆地所属的岛屿编号
	globalIslandLayout := make([][]int, len(grid))
	for i := range grid {
		globalIslandLayout[i] = make([]int, len(grid[i]))
		copy(globalIslandLayout[i], grid[i])
	}

	// 定义一个map，存储每个岛屿的面积大小
	var areaMap map[int]int = make(map[int]int)

	islandIndex := 1
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			islandArea := area2(grid, globalIslandLayout, i, j, islandIndex)
			if islandArea != 0 {
				areaMap[islandIndex] = islandArea
				islandIndex++
			}

		}
	}

	// 开始遍历海洋
	result := areaMap[1]
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if globalIslandLayout[i][j] != 0 {
				continue
			}
			result = max(result, 1+ocean(globalIslandLayout, i, j, areaMap))
		}
	}
	return result
}

func ocean(globalIslandLayout [][]int, r int, c int, areaMap map[int]int) int {
	if r < 0 || c < 0 || r >= len(globalIslandLayout) || c >= len(globalIslandLayout[0]) {
		return 0
	}
	// 使用map实现一个set，获取与该海洋相邻的岛屿
	var neighbor map[int]int = map[int]int{}
	if r-1 >= 0 && globalIslandLayout[r-1][c] != 0 {
		neighbor[globalIslandLayout[r-1][c]] = 1
	}
	if r+1 < len(globalIslandLayout) && globalIslandLayout[r+1][c] != 0 {
		neighbor[globalIslandLayout[r+1][c]] = 1
	}
	if c-1 >= 0 && globalIslandLayout[r][c-1] != 0 {
		neighbor[globalIslandLayout[r][c-1]] = 1
	}
	if c+1 < len(globalIslandLayout[0]) && globalIslandLayout[r][c+1] != 0 {
		neighbor[globalIslandLayout[r][c+1]] = 1
	}

	sumSize := 0
	for key, _ := range neighbor {
		sumSize += areaMap[key]
	}
	return sumSize
}

func area2(grid [][]int, globalIslandLayout [][]int, r int, c int, islandIndex int) int {
	if r < 0 || r >= len(grid) || c < 0 || c >= len(grid[0]) {
		return 0
	}
	if grid[r][c] != 1 {
		return 0
	}
	grid[r][c] = 2
	globalIslandLayout[r][c] = islandIndex

	return 1 + area2(grid, globalIslandLayout, r, c-1, islandIndex) +
		area2(grid, globalIslandLayout, r, c+1, islandIndex) +
		area2(grid, globalIslandLayout, r-1, c, islandIndex) +
		area2(grid, globalIslandLayout, r+1, c, islandIndex)
}

func Solution827() {
	grid := [][]int{
		{1, 0},
		{0, 1},
	}
	res := largestIsland(grid)
	fmt.Println(res)
	fmt.Println(largestIsland([][]int{{1, 1}, {1, 0}}))
	fmt.Println(largestIsland([][]int{{1, 1}, {1, 1}}))
}
