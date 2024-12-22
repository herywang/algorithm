package solution

import "fmt"

// 单词搜索
func exist(board [][]byte, word string) bool {
	var (
		isUsed [][]bool = make([][]bool, len(board))
		dfs    func(int, int, int) bool
		row    int = len(board)
		col    int = len(board[0])
	)

	for i := 0; i < row; i++ {
		isUsed[i] = make([]bool, col)
	}

	dfs = func(i, j, k int) bool {
		if k == len(word) {
			return true
		}

		if i < 0 || j < 0 || i >= row || j >= col {
			return false
		}

		if isUsed[i][j] || board[i][j] != word[k] {
			return false
		}

		isUsed[i][j] = true
		if dfs(i-1, j, k+1) || dfs(i+1, j, k+1) || dfs(i, j-1, k+1) || dfs(i, j+1, k+1) {
			return true
		}
		isUsed[i][j] = false
		return false
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if dfs(i, j, 0) {
				return true
			}
		}
	}
	return false
}

func Solution79() {
	// board := [][]byte{
	// 	{'A', 'B', 'C', 'E'},
	// 	{'S', 'F', 'C', 'S'},
	// 	{'A', 'D', 'E', 'E'},
	// }
	// fmt.Println(exist(board, "CCEDB"))
	board := [][]byte{
		{'A'},
	}
	fmt.Println(exist(board, "A"))
}
