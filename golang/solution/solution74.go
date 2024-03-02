package solution

import (
	"fmt"
)

func searchMatrix(matrix [][]int, target int) bool {

	column := len(matrix[0])
	l, r := 0, len(matrix)-1

	// 二分查找到对应的行
	for l < r {
		mid := (l + r) / 2
		if matrix[mid][column-1] == target {
			return true
		} else if matrix[mid][column-1] < target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	searchRow := l

	// 从当前行中继续进行二分查找
	l, r = 0, column-1
	for l < r {
		mid := (l + r) / 2
		if matrix[searchRow][mid] < target {
			l = mid + 1
		} else if matrix[searchRow][mid] > target {
			r = mid
		} else {
			return true
		}
	}

	return matrix[searchRow][l] == target
}

func Solution74() {
	// fmt.Println(searchMatrix([][]int{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 31))
	fmt.Println(searchMatrix([][]int{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 10))
}
