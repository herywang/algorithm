package solution

import (
	"fmt"
	"math"
)

// Container with most water

func maxArea(height []int) int {

	l, r := 0, len(height)-1
	var maxRes int = 0

	for l < r {
		area := math.Min(float64(height[l]), float64(height[r])) * float64(r-l)
		if area > float64(maxRes) {
			maxRes = int(area)
		}
		if height[l] <= height[r] {
			l++
		} else {
			r--
		}
	}
	return maxRes
}

func Solution11() {
	var height [5]int = [5]int{3, 4, 2, 6, 7}
	fmt.Println(maxArea(height[:]))
}
