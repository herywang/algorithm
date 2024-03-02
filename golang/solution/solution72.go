package solution

import "fmt"

// 编辑距离
func minDistance(word1 string, word2 string) int {
	var (
		l1  int                = len(word1)
		l2  int                = len(word2)
		dp  [][]int            = make([][]int, l1+1)
		min func(int, int) int = func(i1, i2 int) int {
			if i1 < i2 {
				return i1
			}
			return i2
		}
	)
	for i := 0; i < l1+1; i++ {
		dp[i] = make([]int, l2+1)
	}
	// 初始化dp矩阵第一行，第一列
	for i := 0; i <= l2; i++ {
		dp[0][i] = i
	}
	for i := 0; i <= l1; i++ {
		dp[i][0] = i
	}

	for i := 1; i <= l1; i++ {
		for j := 1; j <= l2; j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1
			}
		}
	}
	return dp[l1][l2]
}

func Solution72() {
	fmt.Println(minDistance("horse", "ros"))
}
