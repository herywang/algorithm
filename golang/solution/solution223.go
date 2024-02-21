package solution

import "fmt"

// 计算两个矩形覆盖的面积

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	if bx1 >= ax2 || bx2 <= ax1 || by1 >= ay2 || by2 <= ay1 {
		// no intersection
		w1, h1 := (ax2 - ax1), (ay2 - ay1)
		w2, h2 := (bx2 - bx1), (by2 - by1)
		return w1*h1 + w2*h2
	}

	var max func(int, int) int = func(i, j int) int {
		if i < j {
			return j
		}
		return i
	}

	var min func(int, int) int = func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}

	cx1, cy1 := max(ax1, bx1), max(ay1, by1)
	cx2, cy2 := min(ax2, bx2), min(ay2, by2)

	crossArea := (cx2 - cx1) * (cy2 - cy1)

	w1, h1 := (ax2 - ax1), (ay2 - ay1)
	w2, h2 := (bx2 - bx1), (by2 - by1)
	return w1*h1 + w2*h2 - crossArea
}

func Solution223() {
	fmt.Println(computeArea(-3, 0, 3, 4, 0, -1, 9, 2))
}
