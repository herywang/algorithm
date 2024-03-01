package solution

import "fmt"

// 旋转图像
func rotate(matrix [][]int) {
	row, col := len(matrix), len(matrix[0])
	var t int
	for i := 0; i < row; i++ {
		for j := i + 1; j < col; j++ {
			t = matrix[i][j]
			matrix[i][j] = matrix[j][i]
			matrix[j][i] = t
		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col/2; j++ {
			t = matrix[i][j]
			matrix[i][j] = matrix[i][col-j-1]
			matrix[i][col-j-1] = t
		}
	}
}

func Solution48() {
	matrix := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	rotate(matrix)
	fmt.Println(matrix)
}
