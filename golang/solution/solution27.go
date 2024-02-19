package solution

import "fmt"

func removeElement(nums []int, val int) int {
	var slow, fast int = 0, 0
	for fast < len(nums) {
		if nums[fast] != val {
			nums[slow] = nums[fast]
			slow++
			fast++
		} else {
			fast++
		}
	}
	return slow
}

func Solution27() {
	nums := []int{1, 2, 3, 4, 5, 2, 1}
	n := removeElement(nums, 2)
	for i := 0; i < n; i++ {
		fmt.Print(nums[i], " ")
	}
}
