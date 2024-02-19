package solution

import "fmt"

func removeDuplicates(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	var slow, fast int = 0, 1
	for fast < len(nums) {
		if nums[fast] == nums[slow] {
			fast++
		} else {
			nums[slow+1] = nums[fast]
			slow++
			fast++
		}
	}
	return slow + 1
}

func Solution26() {
	var nums []int = []int{0, 1, 1, 2, 3, 4, 4, 5}
	n := removeDuplicates(nums)
	fmt.Println(n)

	for i := 0; i < n; i++ {
		fmt.Println(nums[i])
	}
}
