package lcr

import "fmt"

func trainingPlan(actions []int) []int {
	l, r := 0, len(actions)-1
	for l < r {
		// 从左边找第一个偶数
		for ; l < r && actions[l]%2 != 0; l++ {
		}
		// 从右边找第一个奇数
		for ; r > l && actions[r]%2 == 0; r-- {
		}

		if l < r {
			actions[l], actions[r] = actions[r], actions[l]
			l++
			r--
		}
	}
	return actions
}

func Lcr139() {
	// actions := []int{1, 2, 3, 4, 5}
	// result := trainingPlan(actions)
	// fmt.Println(result)
	fmt.Println(trainingPlan([]int{2, 16, 3, 5, 13, 1, 16, 1, 12, 18, 11, 8, 11, 11, 5, 1}))
}
