package solution

import "fmt"

func generateParenthesis(n int) []string {
	res := make([]string, 0)
	combination := ""
	dfs(&res, &combination, 0, 0, n)
	return res
}

func dfs(res *[]string, combination *string, left int, right int, n int) {
	if len(*combination) == 2*n {
		(*res) = append((*res), *combination)
		return
	}
	if left < n {
		*combination = *combination + "("
		dfs(res, combination, left+1, right, n)
		*combination = (*combination)[:len(*combination)-1]
	}
	if right < left {
		*combination = *combination + ")"
		dfs(res, combination, left, right+1, n)
		*combination = (*combination)[:len(*combination)-1]
	}
}

func Solution22() {
	res := generateParenthesis(4)
	for _, row := range res {
		fmt.Println(row)
	}
}
