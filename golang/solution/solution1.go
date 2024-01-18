package solution

import "fmt"

func toSum(nums []int, target int) []int {
	if len(nums) < 2 {
		res := [2]int{-1, -1}
		return res[:]
	}
	return nil
}

func main_() {

	// generate a list with element 3,4,5,6
	var nums []int = []int{3, 4, 5, 6}
	// reverse print this list
	for i := len(nums) - 1; i >= 0; i-- {
		fmt.Println(nums[i])
	}

}
