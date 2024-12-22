package solution

import "fmt"

// 螺旋矩阵

func generateMatrix(n int) [][]int {
	// 初始化结果数组
	var ans [][]int = make([][]int, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]int, n)
	}

	// 初始化四个边界
	var (
		top, bottom, left, right int = 0, n - 1, 0, n - 1
		num                      int = 1
	)

	for num <= n*n {
		// 从左到右
		for i := left; i <= right; i++ {
			ans[top][i] = num
			num++
		}
		top++
		// 从上到下
		for i := top; i <= bottom; i++ {
			ans[i][right] = num
			num++
		}
		right--
		// 从右往左
		for i := right; i >= left; i-- {
			ans[bottom][i] = num
			num++
		}
		bottom--
		// 从下至上
		for i := bottom; i >= top; i-- {
			ans[i][left] = num
			num++
		}
		left++
	}

	return ans

}

func Solution59() {
	fmt.Println(generateMatrix(5))
}
