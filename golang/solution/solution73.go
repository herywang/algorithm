package solution

import "fmt"

// 矩阵置0
func setZeroes(matrix [][]int) {
	var (
		zeroRow map[int]bool = make(map[int]bool)
		zeroCol map[int]bool = make(map[int]bool)
		r, c                 = len(matrix), len(matrix[0])
	)
	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if matrix[i][j] == 0 {
				zeroRow[i] = true
				zeroCol[j] = true
			}
		}
	}

	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if zeroRow[i] || zeroCol[j] {
				matrix[i][j] = 0
			}
		}
	}
}

func Solution73() {
	matrix := [][]int{
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5},
		{0, 1, 2, 0},
	}
	setZeroes(matrix)
	fmt.Println(matrix)
}
