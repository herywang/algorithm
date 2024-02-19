package competition

import "fmt"

func returnToBoundaryCount(nums []int) int {
	var count int = 0
	var res int = 0
	for _, n := range nums {
		res = res + n
		if res == 0 {
			count += 1
		}
	}
	return count
}

func Competition3028() {
	fmt.Println(returnToBoundaryCount([]int{2, 3, -5}))
	fmt.Println(returnToBoundaryCount([]int{-9, 9, 6, -6}))
	fmt.Println(returnToBoundaryCount([]int{-9, 9, 6, -6}))
}
